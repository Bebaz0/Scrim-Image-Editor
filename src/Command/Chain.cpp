//
// Created by Daniel on 22/05/2025.
//

#include "Command/Chain.hpp"
#include "ScrimParser.hpp"
#include "Image.hpp"
#include "Color.hpp"
#include "Logger.hpp"
#include <fstream>
#include <string>
#include <sstream>

namespace prog {
    namespace command {

        std::set<std::string> Chain::visited_files_;

        //Use counter to limit recursion
        static int chain_depth = 0;

        Chain::Chain(const std::vector<std::string> &scrim_files)
                   : Command("Chain"), scrim_files_(scrim_files) {}


        void Chain::resetVisitedFiles() {
            visited_files_.clear();
            chain_depth = 0;  //Reset chain depth
        }

        Image *Chain::apply(Image *img) {
            if (img == nullptr) {
                return nullptr;
            }

            Image* current_image = img;

            //Increment depth counter and check limit
            chain_depth++;

            //Safety measure to avoid infinite loops. 16 is arbitrary but enough.
            if (chain_depth > 16) {
                chain_depth--;  //Decrement before returning
                return current_image;  //return the original image to prevent infinite loops
            }

            for (const std::string& file : scrim_files_) {
                //Check if file exists
                std::ifstream file_check(file);
                if (!file_check.good()) {
                    continue;
                }
                file_check.close();

                // Check if file has already been visited
                if (visited_files_.find(file) != visited_files_.end()) {
                    continue;
                }

                // Mark this file as visited
                visited_files_.insert(file);

                // Open the file and read its content
                std::ifstream inFile(file);
                std::string line;
                std::string modifiedContent;

                // Read the file line by line and splits the command and the arguments
                while (std::getline(inFile, line)) {
                    std::istringstream iss(line);
                    std::string firstWord;
                    if (iss >> firstWord && firstWord != "save") {
                        modifiedContent += line + "\n";
                    }
                }

                // Parse the modified content
                std::istringstream content(modifiedContent);
                ScrimParser parser;
                Scrim* scrim = parser.parseScrim(content);

                if (scrim != nullptr) {
                    // Apply the scrim to the current image
                    Image* result = scrim->run(current_image);

                    // Only update current_image if result is not null
                    if (result != nullptr) {
                        // If the result is different from the input, we need to
                        // delete the old image to avoid memory leaks
                        if (result != current_image && current_image != img) {
                            delete current_image;
                        }
                        current_image = result;
                    }

                    delete scrim;
                }

                // Remove this file from visited_files_ after processing
                visited_files_.erase(file);
            }

            // Decrement depth counter before returning
            chain_depth--;

            return current_image;
        }
    }
}