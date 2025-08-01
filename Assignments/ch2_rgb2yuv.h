#ifndef CH2_RGB2YUV_H
#define CH2_RGB2YUV_H

#include <iostream>
#include <array>

/**
* Clamps a double to small and large boundaries.
* @param small The small boundary.
* @param large The large boundary.
* @param val The double value.
* @returns The clamped value.
*/
static double clamp(double small, double large, double val);

/**
* To print an array.
* @param arr The array.
*/
static void printArr(std::array<double, 3> arr);

/**
* Converts RGB format to YUV format.
* @param r Red value.
* @param g Green value.
* @param b Blue value.
* @returns A length-3 array of Y-U-V values.
*/
static std::array<double, 3> rgb2yuv(int r, int g, int b);

/**
* Converts YUV format to RGB format.
* @param y Y (Luminance) value.
* @param u U (Chrominance) value.
* @param v V (Chroma) value.
* @returns A length-3 array of R-G-B values.
*/
static std::array<double, 3> yuv2rgb(int y, int u, int v);


namespace ch2 {
    void run();
}
#endif