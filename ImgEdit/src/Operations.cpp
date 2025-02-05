#include "Operations.h"

// Flip image horizontally
void Operations::flipHorizontal(PPMImage& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<unsigned char>& pixels = image.getPixels();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width / 2; ++x) {
            int leftIndex = (y * width + x) * 3;
            int rightIndex = (y * width + (width - 1 - x)) * 3;

            for (int i = 0; i < 3; ++i) {
                std::swap(pixels[leftIndex + i], pixels[rightIndex + i]);
            }
        }
    }
}

// Flip image vertically
void Operations::flipVertical(PPMImage& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<unsigned char>& pixels = image.getPixels();

    for (int y = 0; y < height / 2; ++y) {
        for (int x = 0; x < width; ++x) {
            int topIndex = (y * width + x) * 3;
            int bottomIndex = ((height - 1 - y) * width + x) * 3;

            for (int i = 0; i < 3; ++i) {
                std::swap(pixels[topIndex + i], pixels[bottomIndex + i]);
            }
        }
    }
}

// Rotate image 90 degrees
void Operations::rotate90(PPMImage& image) {
    int oldWidth = image.getWidth();
    int oldHeight = image.getHeight();
    std::vector<unsigned char> newPixels(oldWidth * oldHeight * 3);

    for (int y = 0; y < oldHeight; ++y) {
        for (int x = 0; x < oldWidth; ++x) {
            int oldIndex = (y * oldWidth + x) * 3;
            int newIndex = (x * oldHeight + (oldHeight - 1 - y)) * 3;

            for (int i = 0; i < 3; ++i) {
                newPixels[newIndex + i] = image.getPixels()[oldIndex + i];
            }
        }
    }

    image.getPixels() = std::move(newPixels);
    image.setWidth(oldHeight);
    image.setHeight(oldWidth);
}

// Rotate image 180 degrees
void Operations::rotate180(PPMImage& image) {
    int width = image.getWidth();
    int height = image.getHeight();
    std::vector<unsigned char>& pixels = image.getPixels();

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            int oldIndex = (y * width + x) * 3;
            int newIndex = ((height - 1 - y) * width + (width - 1 - x)) * 3;

            for (int i = 0; i < 3; ++i) {
                std::swap(pixels[oldIndex + i], pixels[newIndex + i]);
            }
        }
    }
}

// Rotate image 270 degrees
void Operations::rotate270(PPMImage& image) {
    int oldWidth = image.getWidth();
    int oldHeight = image.getHeight();
    std::vector<unsigned char> newPixels(oldWidth * oldHeight * 3);

    for (int y = 0; y < oldHeight; ++y) {
        for (int x = 0; x < oldWidth; ++x) {
            int oldIndex = (y * oldWidth + x) * 3;
            int newIndex = ((oldWidth - 1 - x) * oldHeight + y) * 3;

            for (int i = 0; i < 3; ++i) {
                newPixels[newIndex + i] = image.getPixels()[oldIndex + i];
            }
        }
    }

    image.getPixels() = std::move(newPixels);
    image.setWidth(oldHeight);
    image.setHeight(oldWidth);
}

// Crop Image
void Operations::crop(PPMImage& image, int x, int y, int newWidth, int newHeight) {
    
    int oldWidth = image.getWidth();
    int oldHeight = image.getHeight();
    
    std::vector<unsigned char>& pixels = image.getPixels();

    if (x < 0 || y < 0 || x + newWidth > oldWidth || y + newHeight > oldHeight) {
        std::cerr << "Error: Crop Dimensions : Out of bounds!" << std::endl;
        return;
    }

    std::vector<unsigned char> newPixels(newWidth * newHeight * 3);

    for (int row = 0; row < newHeight; ++row) {
        for (int col = 0; col < newWidth; ++col) {
            int oldIndex = ((y + row) * oldWidth + (x + col)) * 3;
            int newIndex = (row * newWidth + col) * 3;

            for (int i = 0; i < 3; ++i) {
                newPixels[newIndex + i] = pixels[oldIndex + i];
            }
        }
    }

    image.getPixels() = std::move(newPixels);
    image.setWidth(newWidth);
    image.setHeight(newHeight);
}

// Padding - White
void Operations::addPadding(PPMImage& image, int padLeft, int padRight, int padTop, int padBottom) {
    int oldWidth = image.getWidth();
    int oldHeight = image.getHeight();
    int newWidth = oldWidth + padLeft + padRight;
    int newHeight = oldHeight + padTop + padBottom;
    
    std::vector<unsigned char> newPixels(newWidth * newHeight * 3, 255);

    std::vector<unsigned char>& oldPixels = image.getPixels();

    for (int y = 0; y < oldHeight; ++y) {
        for (int x = 0; x < oldWidth; ++x) {
            int oldIndex = (y * oldWidth + x) * 3;
            int newIndex = ((y + padTop) * newWidth + (x + padLeft)) * 3;

            for (int i = 0; i < 3; ++i) {
                newPixels[newIndex + i] = oldPixels[oldIndex + i];
            }
        }
    }

    image.getPixels() = std::move(newPixels);
    image.setWidth(newWidth);
    image.setHeight(newHeight);
}
