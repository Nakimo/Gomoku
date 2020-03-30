#pragma once
#define PUSHSOUND L"Sound\\Push.mp3"
#define PushSound 1

//format
#define SOUNDMP3 L"mpegvideo"

#include<stdio.h>
#include<Windows.h>

#pragma comment(lib, "winmm.lib")
#include "Mmsystem.h"
#include "Digitalv.h"

void LoadSound(HWND hWnd, const wchar_t* name, const wchar_t* type);

void PlayMusic(int wDeviceID);