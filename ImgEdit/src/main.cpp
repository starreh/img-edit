#include "PPMImage.h"
#include "Operations.h"
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <input.ppm> <output.ppm> <operation>\n";
        std::cerr << "Operations:\n";
        std::cerr << "  hflip   - Horizontal Flip\n";
        std::cerr << "  vflip   - Vertical Flip\n";
        std::cerr << "  rot90   - Rotate 90 degrees\n";
        std::cerr << "  rot180  - Rotate 180 degrees\n";
        std::cerr << "  rot270  - Rotate 270 degrees\n";
        std::cerr << "  crop <x> <y> <width> <height> - Crop Image\n";
        std::cerr << "  pad <left> <right> <top> <bottom> - Add Padding - White\n";
        return 1;
    }

    std::string inputFile = argv[1];
    std::string outputFile = argv[2];
    std::string operation = argv[3];

    PPMImage image;
    
    if (!image.load(inputFile)) {
        return 1;
    }

    if (operation == "hflip") {
        Operations::flipHorizontal(image);
    } else if (operation == "vflip") {
        Operations::flipVertical(image);
    } else if (operation == "rot90") {
        Operations::rotate90(image);
    } else if (operation == "rot180") {
        Operations::rotate180(image);
    } else if (operation == "rot270") {
        Operations::rotate270(image);
    } else if (operation == "crop") {
        if (argc != 8) {
            std::cerr << "Usage: " << argv[0] << " <input.ppm> <output.ppm> crop <x> <y> <width> <height>\n";
            return 1;
        }

        int x = std::stoi(argv[4]);
        int y = std::stoi(argv[5]);
        int newWidth = std::stoi(argv[6]);
        int newHeight = std::stoi(argv[7]);

        Operations::crop(image, x, y, newWidth, newHeight);
    } else if (operation == "pad") {
        if (argc != 8) {
            std::cerr << "Usage: " << argv[0] << " <input.ppm> <output.ppm> pad <left> <right> <top> <bottom>\n";
            return 1;
        }

        int padLeft = std::stoi(argv[4]);
        int padRight = std::stoi(argv[5]);
        int padTop = std::stoi(argv[6]);
        int padBottom = std::stoi(argv[7]);

        Operations::addPadding(image, padLeft, padRight, padTop, padBottom);
    } else {
        std::cerr << "Error: Unknown operation '" << operation << "'\n";
        return 1;
    }

    if (!image.save(outputFile)) {
        return 1;
    }

    std::cout << "Operation '" << operation << "' completed successfully! Saved to " << outputFile << std::endl;
    return 0;
}
