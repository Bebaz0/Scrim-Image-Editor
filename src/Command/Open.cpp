//
// Created by JBispo on 05/04/2025.
//
#include "Command/Open.hpp"
#include "PNG.hpp"
#include "Logger.hpp"
#include <cstdlib>
#include <sstream>
#include <filesystem>

namespace prog {

    namespace command {
        Open::Open(std::string filename) : Command("Open"), filename(filename) {}

        Open::~Open() {};

Image *Open::apply(Image *img) {
    // Dispose of previous image
    delete img;

    // Try multiple possible locations for the input directory
    std::vector<std::string> possiblePaths = {
        filename,                    //direct path
        "input/" + filename,         //input subdirectory
        "../input/" + filename,      //input directory one level up
        "../../input/" + filename,   //input directory two levels up
        "../../../input/" + filename //input directory three levels up
    };

    img = nullptr;
    std::string successPath;

    //try each path
    for (const auto& path : possiblePaths) {
        img = loadFromPNG(path);
        if (img) {
            successPath = path;
            break;
        }
    }

    if (!img) {
        *Logger::err() << "Could not open file " << filename << " in any known location\n";
        *Logger::err() << "Tried the following paths:\n";
        for (const auto& path : possiblePaths) {
            *Logger::err() << " - " << path << "\n";
        }
        std::exit(1);
    } else {
    }

    return img;
}

        std::string Open::toString() const {
            std::ostringstream ss;
            ss << name() << " filename:" << filename;
            return ss.str();
        }
    }
}