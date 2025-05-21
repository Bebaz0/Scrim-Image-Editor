//
// Created by Afonso Lima on 21/05/2025.
//

#ifndef SCALEUP_H
#define SCALEUP_H

#include "Command.hpp"
#include "Color.hpp"
#include "Image.hpp"

namespace prog {
    namespace command {
        class Scaleup : public Command {
        public:
            /// @brief Constructor for Scaleup command
            /// @param x The x scale factor
            /// @param y The y scale factor
            Scaleup(int x,int y);

            Image *apply(Image *img) override;

        private:
            int x;
            int y;
        };
    }
}

#endif //SCALEUP_H
