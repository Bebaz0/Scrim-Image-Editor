//
// Created by JBispo on 05/04/2025, adapted by danielramaa and limaa on 17/05/2025-22/05/2025
//
#include "ScrimParser.hpp"

#include "Command/Blank.hpp"
#include "Command/Save.hpp"
#include "Command/Open.hpp"
#include "Logger.hpp"
#include "Command/Invert.hpp"
#include "Command/to_gray_scale.hpp"
#include "Command/Fill.hpp"
#include "Command/Add.hpp"
#include "Command/Move.hpp"
#include "Command/Replace.hpp"
#include "Command/Rotate_left.hpp"
#include "Command/Slide.hpp"
#include "Command/h_mirror.hpp"
#include "Command/v_mirror.hpp"
#include "Command/Resize.hpp"
#include "Command/Scaleup.hpp"


#include <fstream>
#include <string>
#include <vector>

#include <cstdlib>

using std::ifstream;
using std::istream;
using std::string;
using std::vector;

namespace prog {
    ScrimParser::ScrimParser() {
    };

    ScrimParser::~ScrimParser() {
    };


    Scrim *ScrimParser::parseScrim(std::istream &input) {
        // Create vector where commands will be stored
        vector<Command *> commands;

        // Parse commands while there is input in the stream
        string command_name;
        while (input >> command_name) {
            Command *command = parse_command(command_name, input);

            if (command == nullptr) {
                // Deallocate already allocated commands
                for (Command *allocated_command: commands) {
                    delete allocated_command;
                }


                *Logger::err() << "Error while parsing command\n";
                return nullptr;
            }

            commands.push_back(command);
        }

        // Create a new image pipeline
        return new Scrim(commands);
    }


    Scrim *ScrimParser::parseScrim(const std::string &filename) {
        ifstream in(filename);
        return parseScrim(in);
    }

    Command *ScrimParser::parse_command(string command_name, istream &input) {
        if (command_name == "blank") {
            // Read information for Blank command
            int w, h;
            Color fill;
            input >> w >> h >> fill;
            return new command::Blank(w, h, fill);
        }

        if (command_name == "save") {
            // Read information for Save command
            string filename;
            input >> filename;
            return new command::Save(filename);
        }

        if (command_name == "open") {
            string filename;
            input >> filename;
            return new command::Open(filename);
        }

        if (command_name == "invert"){
            return new command::Invert();
        }

        if (command_name == "to_gray_scale") {
            return new command::to_gray_scale();
        }

        if (command_name == "fill") {
            int x;
            int y;
            int w;
            int h;
            int r,g,b;
            input >>x>>y>>w>>h>>r>>g>>b;

            return new command::Fill(x,y,w,h,r,g,b);
        }

        if (command_name == "add") {
            std::string filename;
            int r,g,b;
            int x;
            int y;
            input >>filename>>r>>g>>b>>x>>y;
            return new command::Add(filename,r, g, b, x, y);
        }

        if (command_name == "move"){
            int x, y;
            input >> x >> y;

            Color fill(255, 255, 255);
            return new command::Move(x, y, fill);
        }

        if (command_name == "slide"){
            int x, y;
            input >> x >> y;
            return new command::Slide(x, y);
        }

        if (command_name == "replace") {
            int r1,g1, b1, r2, g2, b2;
            input >>r1>>g1>>b1>>r2>>g2>>b2;
            return new Replace(r1,g1,b1,r2,g2,b2);
        }

        if (command_name == "rotate_left") {
            return new command::Rotate_left();
        }

        if (command_name == "h_mirror") {
            return new command::H_mirror();
        }

        if (command_name == "v_mirror"){
            return new command::V_mirror();
        }

        if (command_name == "resize") {
            int x, y, w, h;
            input >> x>>y>>w>>h;

            return new command::Resize(x, y, w, h);
        }
        if (command_name == "scaleup") {
            int x, y;
            input >> x >> y;

            return new command::Scaleup(x, y);
        }



        // TODO: implement cases for the new commands

        *Logger::err() << "Command not recognized: '" + command_name + "'\n";
        return nullptr;
    }
}
