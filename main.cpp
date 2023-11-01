//
// Created by Kenny Na on 2023-10-25.
//
#include "color.h"
#include "vec3.h"

#include <iostream>

int main() {

    // Image

    int image_width = 256;
    int image_height = 256;

    // Render

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    for (int j = 0; j < image_height; ++j) {
        std::clog << "\rScanlines remaining: " << (image_height - j) << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto pixel_color = color(double(i)/(image_width-1), double(j)/(image_height-1), 0);
            write_color(std::cout, pixel_color);
        }
    }

    std::clog << "\rDone.                 \n";
}

//There are some things to note in this code:
//The pixels are written out in rows.
//Every row of pixels is written out left to right.
//These rows are written out from top to bottom.
//By convention, each of the red/green/blue components are represented internally by
// real-valued variables that range from 0.0 to 1.0.
// These must be scaled to integer values between 0 and 255 before we print them out.
//Red goes from fully off (black) to fully on (bright red) from left to right,
// and green goes from fully off at the top to black at the bottom.
// Adding red and green light together make yellow,
// so we should expect the bottom right corner to be yellow.

//executable_path > image.ppm