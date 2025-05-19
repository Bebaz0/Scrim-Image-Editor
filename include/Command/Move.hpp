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