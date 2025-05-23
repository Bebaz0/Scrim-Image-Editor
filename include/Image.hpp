#ifndef __prog_Image_hpp__
#define __prog_Image_hpp__

#include "Color.hpp"
#include <vector>

namespace prog {
	/// @brief Class to represent an image
    class Image {
		private:
		int width_;
		int height_;
    	std::vector<std::vector<Color>> pixels_;

    
	public:
    	///@brief Constructor for Image class
    	///@param w Width of the image
    	///@param h Height of the image
    	///@param fill Color to fill the image with
        Image(int w, int h, const Color &fill = {255, 255, 255});
        ~Image();

    	///@return Width of the image
        int width() const;
    	/// @return Height of the image
        int height() const;

    	
        Color &at(int x, int y);
        const Color &at(int x, int y) const;
    };
}
#endif
