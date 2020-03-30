#include "Sounds.h"

MCI_OPEN_PARMS m_mciOpenParms;
MCI_PLAY_PARMS m_mciPlayParms;

MCI_OPEN_PARMS mciOpen;
MCI_PLAY_PARMS mciPlay;

void LoadSound(HWND hWnd, const wchar_t* name, const wchar_t* type)
{
	int wDeviceID = 0;
	mciOpen.lpstrDeviceType = type;
	mciOpen.lpstrElementName = name;

	mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);

	wDeviceID = mciOpen.wDeviceID;
}

void PlayMusic(int wDeviceID) {
	mciSendCommand(wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, (DWORD)(LPVOID)NULL);
	mciSendCommand(wDeviceID, MCI_PLAY, MCI_NOTIFY, (DWORD)(LPVOID)&m_mciPlayParms);
}