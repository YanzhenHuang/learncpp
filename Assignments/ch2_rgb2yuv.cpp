#include <iostream>
#include <array>


static double clamp(double small, double large, double val) {
	if (small > large) {
		return small;
	}

	if (val < small) {
		return small;
	}

	if (val > large) {
		return large;
	}

	return val;
}


static void printArr(std::array<double, 3> arr) {
	for (int i = 0; i < arr.size(); i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}


static std::array<double, 3> rgb2yuv(int r, int g, int b){
	double y = 0.299 * r + 0.587 * g + 0.114 * b;
	double u = -0.14713 * r + 0.28886 * g + 128;
	double v = 0.615 * r - 0.51498 * g - 1.0001 * b + 128;
	std::array<double, 3> yuv = { y, u, v };
	return yuv;
}


static std::array<double, 3> yuv2rgb(int y, int u, int v) {
	double r = y + 1.13983 * (v - 128);
	double g = y - 0.39465 * (u - 128) - 0.58060 * (v - 128);
	double b = y + 2.03211 * (u - 128);

	r = clamp(0, 255, r);
	g = clamp(0, 255, g);
	b = clamp(0, 255, b);

	std::array<double, 3> rgb = { r, g, b };
	return rgb;
}


namespace ch2 {
	void run() {
		for (;;) {

			std::cout << "Enter 3 values: " << std::endl;
			int x, y, z;
			std::cin >> x >> y >> z;

			std::cout << "RGB [from (f) / to (t)] YUV?" << std::endl;
			char op;
			std::cin >> op;

			switch (op) {
				case 'f':
					std::array<double, 3> rgb = yuv2rgb(x, y, z);
					printArr(rgb);
					return;
				case 't':
					std::array<double, 3> yuv = rgb2yuv(x, y, z);
					printArr(yuv);
					return;
				default:
					continue;
			}
		}
	}
}