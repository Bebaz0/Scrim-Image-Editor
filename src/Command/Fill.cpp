//
// Created by Afonso Lima on 19/05/2025.
//

#include "Command/Fill.hpp"
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {

    Fill::~Fill(){};

    Fill::Fill(int x,int y,int w, int h, rgb_value r, rgb_value g, rgb_value b) : Command("Fill"),x(x),y(y),w(w),h(h),fill(r,g,b){}

    Image *Fill::apply(Image *img) {


        //Runs through the pixels and changes them to the color
        for (int i = x;i<x+w;i++) {
            for (int j = y;j<y+h;j++) {
                img->at(i,j) = Color(fill);
            }
        }
        return img;

    }


}
}