//
// Created by JBispo on 05/04/2025.
//
#include "Scrim.hpp"
#include "Logger.hpp"

using prog::Command;

namespace prog {
    Scrim::Scrim(std::vector<Command *> &commands) : commands(commands) {
    }

    Scrim::~Scrim() {
        // Deallocate each command
        for (Command *c: commands) {
            delete c;
        }
    };

    Image *Scrim::run(Image *img) {
        Image* current = img;
        size_t start = 0;
        //Skip leading blank/open if input image is not null
        if (current != nullptr && !commands.empty()) {
            std::string name = commands[0]->name();
            if (name == "Blank" || name == "Open") {
                start = 1;
            }
        }
        for (size_t i = start; i < commands.size(); ++i) {
            *Logger::out() << "Applying command '" << commands[i]->toString() << "'\n";
            current = commands[i]->apply(current);
        }
        return current;
    }

    Image *Scrim::run() {
        return this->run(nullptr);
    }

    std::vector<Command *> Scrim::getCommands() const {
        return commands;
    }
}
