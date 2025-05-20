//
// Created by Afonso Lima on 19/05/2025.
//

#ifndef FILL_H
#define FILL_H

#include "Command.hpp"
#include "Color.hpp"

namespace prog {
    namespace command {
        class Fill : public Command {
        public:

            Fill(int x,int y,int w, int h, int r,int g,int b);

            Image *apply(Image *img) override;

        private:
            int x;
            int y;
            int w;
            int h;
            Color fill;
        };
    }
}


#endif //FILL_H
