#include <iostream>

#include "WindowHijacker.h"

#define STB_IMAGE_IMPLEMENTATION
#include "vendor/stb_image.h"

using namespace wh;

typedef WindowHijacker::Window Window;

int main() {

	WindowHijacker::hideConsole();

	// Get all visible windows
	std::vector<Window> windows = WindowHijacker::getVisibleWindows();

	// Load image
	int width, height, bpp;
	unsigned char* buffer = stbi_load("img.png", &width, &height, &bpp, STBI_rgb_alpha);
	std::cout << "Width: " << width << ", Height: " << height << ", Bpp: " << bpp << " Buffer size: " << width * height * 4 << std::endl;

	for (Window& window : windows) {

		// window bounds
		RECT client;
		GetClientRect(window.hwnd, &client);

		// x, y of centered image
		int x = (client.right - width) / 2;
		int y = (client.bottom - height) / 2;

		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				// Get pixel position
				int p = i + j * width;
				// Get color positions
				int r = 4 * p;
				int g = 4 * p + 1;
				int b = 4 * p + 2;
				int a = 4 * p + 3;
				// Draw image
				window.setPixel(x + i, y + j, Color(buffer[r], buffer[g], buffer[b], buffer[a]));
			}
		}
	}

	// Free image buffer
	if(buffer)
		stbi_image_free(buffer);

	return 0;
}