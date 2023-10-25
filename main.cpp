//
// Created by Kenny Na on 2023-10-25.
//
#include <iostream>

int main() {
    // RESOLUTION
    int image_width = 256;
    int image_height = 256;

    // IMAGE FILE GENERATION

    std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
    std::cout << "# The P3 means colors are in ASCII, then 3 columns and 2 rows,\n"
                 "# then 255 for max color, then RGB triplets\n"

    for (int j = 0; j < image_height; ++j) {
        for (int i = 0; i < image_width; ++i) {
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0;

            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            std::cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }
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