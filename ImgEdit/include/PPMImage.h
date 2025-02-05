#ifndef PPMIMAGE_H
#define PPMIMAGE_H

#include <iostream>
#include <vector>
#include <fstream>

class PPMImage {
private:
    int width, height, maxColor;
    std::vector<unsigned char> pixels; // Stores RGB data

public:
    PPMImage();
    bool load(const std::string& filename);
    bool save(const std::string& filename) const;
    void displayInfo() const;

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    const std::vector<unsigned char>& getPixels() const { return pixels; }
    std::vector<unsigned char>& getPixels() { return pixels; }

    void setWidth(int w) { width = w; }
    void setHeight(int h) { height = h; }
};

#endif
