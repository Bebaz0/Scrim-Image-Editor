//
// Created by Afonso Lima on 19/05/2025.
//

#include "Command/Fill.hpp"
#include <sstream>
#include "Image.hpp"
#include "Color.hpp"

namespace prog {
namespace command {

    Fill::~Fill(){};

    Fill::Fill(int x,int y,int w, int h, rgb_value r, rgb_value g, rgb_value b) : Command("Fill"),x(x),y(y),w(w),h(h),fill(r,g,b){}

    Image *Fill::apply(Image *img) {

        //limits
        int startX = std::max(0, x);
        int startY = std::max(0, y);
        int endX = std::min(img->width(), x + w);
        int endY = std::min(img->height(), y + h);

        //goes over valid image coordinates
        for (int i = startX; i < endX; i++) {
            for (int j = startY; j < endY; j++) {
                img->at(i, j) = Color(fill);
            }
        }
        return img;
    }
    std::string Fill::toString() const {
        std::ostringstream ss;
        ss << name() << " x:" << x << " y:" << y << " w:" << w << " h:" << h << " fill:" << fill;
        return ss.str();
    }
  }
}