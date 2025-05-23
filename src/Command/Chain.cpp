//
// Created by Daniel on 22/05/2025.
//

#include "Command/Chain.hpp"

#include <fstream>
#include <ScrimParser.hpp>
#include <sstream>
#include <Command/Blank.hpp>
#include <Command/Open.hpp>
#include <Command/Save.hpp>
#include <Command/Open.hpp>

#include "Image.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        
        std::set<std::string> Chain::visited_files_;

        Chain::Chain(const std::vector<std::string> &scrim_files)
                   : Command("Chain"), scrim_files_(scrim_files) {}

        Image *Chain::apply(Image *img) {
            Image* current_image = img;
            for (const std::string& file : scrim_files_) {
                //Check if the file has been visited before
                if (visited_files_.find(file) != visited_files_.end()) {
                    return nullptr;
                }

                visited_files_.insert(file);
                //Open the scrim file
                std::ifstream scrim_file(file);

                //Iterate through the scrim file
                std::string line;
                while (std::getline(scrim_file, line)) {
                    //Get the command from the line
                    std::string command_name = line.substr(0, line.find(' '));
                    if (command_name == "blank" || command_name =="open" || command_name == "save"){
                        //Skips to the next line
                        continue;
                    }

                    //Removes the command name from the line
                    std::istringstream args(line.substr(line.find(' ') + 1));
                    //Parse the command
                    ScrimParser parser;
                    Command* cmd = parser.parse_command(command_name, args);
                    if (cmd == nullptr) {
                        continue;
                    }
                    current_image = cmd->apply(current_image);
                    //Delete the command
                    delete cmd;
                }
                //Close the scrim file
                scrim_file.close();
            }

            return current_image;

        }
    }
}
