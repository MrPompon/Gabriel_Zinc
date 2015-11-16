//winmain.cpp

#define Unused(x) ((void )x)

#include <Windows.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	switch (uMsg){
		case WM_CLOSE : {
			PostQuitMessage(0);
		}break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

int CALLBACK WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow){
	Unused(hInstance);
	Unused(hPrevInstance);
	Unused(lpCmdLine);
	Unused(nCmdShow);

	WNDCLASSEX window_class = { 0 };
	window_class.cbSize = sizeof(WNDCLASSEX);
	window_class.hInstance = hInstance;
	window_class.lpszClassName = L"Gabriel_Zincwindowclass";
	window_class.lpfnWndProc = WndProc;
	window_class.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC;
	window_class.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);

	int result = RegisterClassEx(&window_class);
	if (result == 0)
		return 1;
	HWND window = CreateWindowEx(0,
		window_class.lpszClassName,
		L"Gabriel_Zinc",
		WS_OVERLAPPEDWINDOW, //style
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		1024,
		640,
		NULL,
		NULL, window_class.hInstance,
		NULL);

	if (window == NULL)
		return 2;

	ShowWindow(window, nCmdShow);

	bool running = true;
	while (running){
		MSG msg;
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)){
			if (msg.message == WM_QUIT){
				running = false;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Sleep(5);
	}

	return 0;
}
