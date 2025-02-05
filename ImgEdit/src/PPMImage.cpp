#include "PPMImage.h"

PPMImage::PPMImage() : width(0), height(0), maxColor(255) {}

// Read a PPM image
bool PPMImage::load(const std::string& filename) {
    
    std::ifstream file(filename);
    
    if (!file) {
        std::cerr << "Error: File Not Found " << filename << std::endl;
        return false;
    }

    std::string format;
    file >> format;
    if (format != "P3") {
        std::cerr << "Error: Unsupported File Format" << std::endl;
        return false;
    }

    file >> width >> height >> maxColor;
    pixels.resize(width * height * 3);

    for (int i = 0; i < width * height * 3; ++i) {
        int pixelValue;
        file >> pixelValue;
        pixels[i] = static_cast<unsigned char>(pixelValue);
    }

    file.close();
    return true;
}

// Write a PPM image
bool PPMImage::save(const std::string& filename) const {
    
    std::ofstream file(filename);
    
    if (!file) {
        std::cerr << "Error: File Not Found " << filename << std::endl;
        return false;
    }

    for (size_t i = 0; i < pixels.size(); i++) {
        file << static_cast<int>(pixels[i]) << " ";
        if ((i + 1) % (width * 3) == 0)
            file << "\n";
    }

    file.close();
    return true;
}

void PPMImage::displayInfo() const {
    std::cout << "Image Width : " << width << "\n";
    std::cout << "Image Height : " << height << "\n";
    std::cout << "Max Color : " << maxColor << "\n";
}
