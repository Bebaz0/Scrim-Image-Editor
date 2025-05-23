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
            ///Scrim_files is a vector of strings containing the paths to the scrim files.
            Chain(const std::vector<std::string>& scrim_files);

            Image* apply(Image* img) override;

            static void resetVisitedFiles();
        private:
            std::vector<std::string> scrim_files_;//Paths to the scrim files

            static std::set<std::string> visited_files_; //Stores the visited files to avoid loops

        };
    }
}

#endif // PROG_CHAIN_HPP