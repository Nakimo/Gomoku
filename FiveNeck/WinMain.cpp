#include <windows.h>
#include <math.h>

#include "Graphics.h"
#include "Sounds.h"

Gdiplus::GdiplusStartupInput gdiplusStartupInput;
ULONG_PTR           gdiplusToken;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

HINSTANCE g_hInst;

LPCTSTR lpszClass = TEXT("FiveNeck"); // 게임 이름
HWND hWnd;

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance
	, LPSTR lpszCmdParam, int nCmdShow)
{
	//GDI+ initialize
	Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);


	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, MAP_W + 16, MAP_H + 18,
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while (GetMessage(&Message, NULL, 0, 0)) {
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	//gdi end
	Gdiplus::GdiplusShutdown(gdiplusToken);

	return (int)Message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	static int dir = 0;
	HDC hdc;
	PAINTSTRUCT ps;

	static Game *game;

	switch (iMessage) {

	case WM_CREATE:
		LoadSound(hWnd, PUSHSOUND, SOUNDMP3);

		game = new Game;

		game->init();


		break;


	case WM_LBUTTONDOWN:
		int X, Y;

		X = LOWORD(lParam);
		Y = HIWORD(lParam);

		X = (X - 3) / 26;
		Y = (Y - 3) / 26;

		if (game->Map[X][Y] == 0) {
			game->Map[X][Y] = game->Turn;

			game->LOAD[game->Load_cnt][0] = X;
			game->LOAD[game->Load_cnt++][1] = Y;

			game->Turn *= -1;

			PlayMusic(PushSound);
		}

		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_KEYDOWN:
		if (wParam == VK_BACK && game->Load_cnt > 0) { // 한수 무르기
			game->Map[game->LOAD[game->Load_cnt - 1][0]][game->LOAD[game->Load_cnt - 1][1]] = 0;
			game->Load_cnt--;
		}
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		Render(hdc, game);

		EndPaint(hWnd, &ps);

		if (game->Chk_Win() == 1 && game->Map[game->LOAD[game->Load_cnt - 1][0]][game->LOAD[game->Load_cnt - 1][1]] != 0) {

			if(game->Map[game->LOAD[game->Load_cnt - 1][0]][game->LOAD[game->Load_cnt - 1][1]] == 1) MessageBox(hWnd, L"흑돌 승리", L"GAME OVER", MB_OK);
			else MessageBox(hWnd, L"백돌 승리", L"GAME OVER", MB_OK);

			PostQuitMessage(0);
		}

		break;


	case WM_DESTROY:
		delete game;
		PostQuitMessage(0);
		break;
	}

	return(DefWindowProc(hWnd, iMessage, wParam, lParam));

}