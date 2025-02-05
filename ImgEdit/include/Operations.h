#ifndef OPERATIONS_H
#define OPERATIONS_H

#include "PPMImage.h"

class Operations {
public:
    static void flipHorizontal(PPMImage& image);
    static void flipVertical(PPMImage& image);
    static void rotate90(PPMImage& image);
    static void rotate180(PPMImage& image);
    static void rotate270(PPMImage& image);
    static void crop(PPMImage& image, int x, int y, int newWidth, int newHeight);
    static void addPadding(PPMImage& image, int padLeft, int padRight, int padTop, int padBottom);
};

#endif
