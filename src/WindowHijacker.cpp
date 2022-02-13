#include "WindowHijacker.h"

namespace wh {

	WindowHijacker::Window::Window(const HWND& _hwnd, const HDC& _hdc, const std::string& _title)
		: hwnd(_hwnd), hdc(_hdc), title(_title) {
	}

	std::vector<WindowHijacker::Window> WindowHijacker::getVisibleWindows() {
		std::vector<Window> visibleWindows;
		for (HWND hwnd = GetTopWindow(NULL); hwnd != NULL; hwnd = GetNextWindow(hwnd, GW_HWNDNEXT)) {

			if (!IsWindowVisible(hwnd))
				continue;

			int length = GetWindowTextLength(hwnd);
			if (length == 0)
				continue;

			char* title = new char[length + 1];
			GetWindowTextA(hwnd, title, length + 1);

			HDC hdc = GetDC(hwnd);
			visibleWindows.push_back(Window(hwnd, hdc, title));
		}
		return visibleWindows;
	}

	WindowHijacker::Window WindowHijacker::getWindow(const std::string& title) {
		HWND window = FindWindowA(NULL, title.c_str());
		HDC hdc = GetDC(window);
		return Window(window, hdc, title);
	}

	void WindowHijacker::hideConsole() {
		HWND console = GetConsoleWindow();
		ShowWindow(console, SW_HIDE);
	}
}