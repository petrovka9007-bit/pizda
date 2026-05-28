#include "raylibApp.h"

void startRaylibDemo() {
	pizda::RaylibApp app;

	if (app.init()) {
		app.start();
		app.terminate();
	}
}

#ifdef WIN_APP
#include <Windows.h>
#include <sysinfoapi.h>
INT WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, INT iCmdShow) {
	startRaylibDemo();
	return 0;
}
#else

int main(int, char**) {
	startRaylibDemo();
	return 0;
}
#endif