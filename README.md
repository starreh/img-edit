# ImgEdit - A Simple PPM Image Editor in C++

A lightweight C++ Image Editor that supports basic image transformations for PPM (Portable Pixmap) format images. Built from scratch without third-party libraries.

## Features
- Flip Images (Horizontal & Vertical)  
- Rotate Images (90°, 180°, 270°)  
- Crop Images (Select a specific region)  
- Tilt Images (Skew transformation)  
- Add Padding (Dynamic padding with white background)  

## Installation & Compilation

### Using g++
```sh
g++ src/main.cpp src/PPMImage.cpp src/Operations.cpp -o build/ImageEditor
```

### Using Makefile
```sh
make
```

## Usage
```sh
./build/ImageEditor <input.ppm> <output.ppm> <operation> [parameters]
```

### Example Usage
- Horizontal Flip:  
  ```sh
  ./build/ImageEditor input.ppm output.ppm hflip
  ```
- Crop (x=50, y=50, width=200, height=150):  
  ```sh
  ./build/ImageEditor input.ppm output.ppm crop 50 50 200 150
  ```
- Add Padding (Left=20, Right=20, Top=30, Bottom=30):  
  ```sh
  ./build/ImageEditor input.ppm output.ppm pad 20 20 30 30
  ```

## License
MIT License

