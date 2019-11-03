/*
 * File:   DP_Communication.cpp
 * Author: astoc
 *
 * Created on 03. Novembre 2019, 15:11
 */

#include <iostream>
#include <Windows.h>
#include <wchar.h>
#include "mcp2221_dll_um.h"
#include "USB_Communication.h"
#include "DP_Communication.h"

using namespace std;

int SetRgbColor(void* handle, unsigned char red, unsigned char green, unsigned char blue)
{
	int error = 0;
	unsigned char Data[USBDATASIZE] = {0};
	
	Data[0] = SETRGBCOLOR;

	Data[1] = red;
	Data[2] = green;
	Data[3] = blue;

	error = TransmitUsbData(handle, Data);

//	wcout << "Color Data: " << Data[0] << " " << Data[1] << " " << Data[2] << " " << Data[3] << " " << Data[4] << " " << Data[5] << " " << Data[6] << " " << Data[7] << " has following error: " << error << endl;

	return(error);
}
