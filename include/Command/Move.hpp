//
// Created by danielramaa on 5/19/25.
//

#ifndef PROJECT_MOVE_HPP
#define PROJECT_MOVE_HPP

#include "Command.hpp"
#include "Fill.hpp"

namespace prog{
    namespace command{
        class Move : public Command{
        public:

            ///@brief Moves a area to a new position replacing the moved pixels for the color fill
            ///x,y coordinates of the top left corner of the image
            ///fill color
            Move(int x , int y, Color fill);
            Image *apply(Image *img) override;


        private:
            int x_;
            int y_;
            Color fill_;
        };
    }
}


#endif //PROJECT_MOVE_HPP