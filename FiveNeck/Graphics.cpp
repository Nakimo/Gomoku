#include "Graphics.h"

//이미지 그리기 (MemDC,MyBitmap,파일경로,좌상단 좌표(x,y),이미지 길이
void drawing_img(HDC MemDC, const wchar_t *str, int x, int y, int width, int height) {
	Graphics graphic(MemDC);
	Image image(str);
	graphic.DrawImage(&image, x, y, width, height);
}

extern HWND hWnd;

int Render(HDC whdc, Game* game) { // 그리기
	HBITMAP MyBitmap, OldBitmap;
	HDC MemDC = CreateCompatibleDC(whdc);
	MyBitmap = CreateCompatibleBitmap(whdc, MAP_W, MAP_H);
	OldBitmap = (HBITMAP)SelectObject(MemDC, MyBitmap);


	drawing_img(MemDC, GoBorad, 0, 0, MAP_W, MAP_H-20); // 보드판 그리기

	for (int i = 0; i < 19; i++) {
		for (int j = 0; j < 19; j++) {
			if (game->Map[i][j] == 1) {
				drawing_img(MemDC, GoB, 15 + i * 26 - 12, 15 + j * 26 - 12, 24, 24); // 흑돌 그리기
			}
			else if (game->Map[i][j] == -1) {
				drawing_img(MemDC, GoW, 15 + i * 26 - 12, 15 + j * 26 - 12, 24, 24); // 백돌 그리기
			}
		}
	}



	BitBlt(whdc, 0, 0, MAP_W, MAP_H, MemDC, 0, 0, SRCCOPY);

	SelectObject(MemDC, OldBitmap);

	DeleteDC(MemDC);
	DeleteObject(MyBitmap);
	DeleteObject(OldBitmap);
	return 0;
}