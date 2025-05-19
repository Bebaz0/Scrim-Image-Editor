//
// Created by Afonso Lima on 19/05/2025.
//

#ifndef FILL_H
#define FILL_H

#include "Command.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:
            Fill(int x,int y,int w, int h, Color &fill);

            Image *apply(Image *img) override;

        private:
            int w;
            int h;
            Color fill;
            int x;
            int y;
        };
    }
}


#endif //FILL_H
