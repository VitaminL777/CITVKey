// CITVKey.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

char ITVKey[128] = "C:\\WINDOWS\\SYSTEM32\\ITV.key";

char VNB[128];
char FSNB[128];
DWORD VSN, MCL, FSF, BW;
char OutKey[128];

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 GetVolumeInformation("C:\\",VNB,128,&VSN,&MCL,&FSF,FSNB,128);
 VSN^=0xF2F3F4F5;
itoa(VSN,OutKey,10);
HANDLE hfkey=CreateFile(ITVKey,GENERIC_READ|GENERIC_WRITE,FILE_SHARE_READ|FILE_SHARE_WRITE,NULL,CREATE_ALWAYS,FILE_ATTRIBUTE_ARCHIVE,NULL);
WriteFile(hfkey,OutKey,(DWORD)strlen(OutKey),&BW,NULL);
CloseHandle(hfkey);

	return 0;
}



