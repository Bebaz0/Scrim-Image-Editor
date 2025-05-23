#ifndef PROG_CHAIN_HPP
#define PROG_CHAIN_HPP

#include "Command.hpp"
#include <string>
#include <vector>
#include <set>

namespace prog {
    namespace command {
        class Chain : public Command {
        public:
            ///@brief Reads a sequence of scrim files and applies the commands in order.
            ///@param Scrim_files is a vector of strings containing the paths to the scrim files.
            Chain(const std::vector<std::string>& scrim_files);

            Image* apply(Image* img) override;

            /// @brief Resets the visited files set and chain depth counter.
            /// The chain depth counter is a safety measure to ensure that the chain does not go too deep.
            static void resetVisitedFiles();
        private:
            ///@brief The scrim files to be applied in order
            std::vector<std::string> scrim_files_;//Paths to the scrim files
            static std::set<std::string> visited_files_; //Stores the visited files to avoid loops

        };
    }
}

#endif // PROG_CHAIN_HPP