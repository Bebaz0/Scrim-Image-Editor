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
            Chain(const std::vector<std::string>& scrim_files);
            Image* apply(Image* img) override;

        private:
            std::vector<std::string> scrim_files_;
            static std::set<std::string> visited_files_; //prevent loops/recursion

        };
    }
}

#endif // PROG_CHAIN_HPP