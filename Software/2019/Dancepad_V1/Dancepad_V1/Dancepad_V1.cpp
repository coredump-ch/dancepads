/*
 * File:   Dancepad_V1.cpp
 * Author: astoc
 *
 * Created on 02. November 2019, 10:06
 */

#include <iostream>
#include <Windows.h>
#include "mcp2221_dll_um.h"

using namespace std;

int main() {
	wchar_t LibVer[6];
	int ver = 0;
	int error = 0;

	ver = Mcp2221_GetLibraryVersion(LibVer);  //Get DLL version
	if (ver == 0)
	{
		cout << "Library (DLL) version: " << LibVer << endl;
	}
	else
	{
		error = Mcp2221_GetLastError();
		cout << "Version can't be found, version: " << ver << ", error: " << error << endl;
	}

	cout << "Muahaha, I've done it" << endl; // prints !!!Hello World!!!
	return 0;
}