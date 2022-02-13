#pragma once

#include <iostream>
#include <vector>

#include <Windows.h>

namespace wh {

	struct Color {
		int r, g, b, a;
		Color(int _r, int _g, int _b, int _a = 255)
			: r(_r), g(_g), b(_b), a(_a) {}
	};

	class WindowHijacker {
	public:
		struct Window {
			HWND hwnd;
			HDC hdc;
			std::string title;

			Window(const HWND& _hwnd, const HDC& _hdc, const std::string& _title);
			~Window() = default;

			inline void setPixel(int x, int y, const Color& color) {
				SetPixel(hdc, x, y, RGB(color.r, color.g, color.b));
			}
		};
	public:
		static std::vector<Window> getVisibleWindows();
		static Window getWindow(const std::string& title);
		static void hideConsole();
	};
}