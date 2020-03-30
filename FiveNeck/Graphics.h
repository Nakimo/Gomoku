#pragma once
#include <Windows.h>
#include <gdiplus.h>
#include "Std.h"
#include "FiveNeck.h"
#pragma comment(lib, "Gdiplus.lib")
using namespace Gdiplus;


#define GoW L"PNG//Go_w.png"
#define GoB L"PNG//Go_b.png"
#define GoBorad L"PNG//Go_board.png"


void drawing_img(HDC MemDC, const wchar_t *str, int x, int y, int width, int height);
int Render(HDC whdc, Game* game);