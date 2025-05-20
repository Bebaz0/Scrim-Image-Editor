//
// Created by Afonso Lima on 19/05/2025.
//

#include "Command/Fill.hpp"
#include <sstream>
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {

    Fill::Fill(int x,int y,int w, int h, int r, int g, int b) : Command("Fill"),x(x),y(y),w(w),h(h),fill(r,g,b){}

    Image *Fill::apply(Image *img) {
        int width = img->width();
        int height = img->height();

        //Only fills the area that is inside the image and within the bounds
        for (int i = y; i < y + h; i++) {
            for (int j = x; j < x + w ; j++) {
                //Check if the pixel is within the bounds of the image
                if (i >= 0 && i < height && j >= 0 && j < width) {
                    //Set the pixel color to the fill color
                    img->at(j, i) = fill;
                }
            }
        }
        return img;
    }
    }
  }
