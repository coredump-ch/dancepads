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
	if (error != 0)
	{
		wcout << "Error setting RGB Color. Errorcode: " << error << endl;
	}

//	wcout << "Color Data: " << Data[0] << " " << Data[1] << " " << Data[2] << " " << Data[3] << " " << Data[4] << " " << Data[5] << " " << Data[6] << " " << Data[7] << " has following error: " << error << endl;

	return(error);
}

int ReadPiezo(void* handle, unsigned char* PiezoData)
{
	int error = 0;
	unsigned char transData[USBDATASIZE] = { 0 };
	unsigned char recData[USBDATASIZE] = { 0 };

	transData[0] = READPIEZO;

	error = TransmitUsbData(handle, transData);
	if (error != 0)
	{
		wcout << "Error sending Read Piezo command. Errorcode: " << error << endl;
	}

	error = ReceiveUsbData(handle, recData);
	if (error != 0)
	{
		wcout << "Error receiving Read Piezo values. Errorcode: " << error << endl;
	}

	for (int i = 0; i <= 5; i++)
	{
		PiezoData[i] = recData[i];
	}

	wcout << "Color Data: " << recData[0] << " " << recData[1] << " " << recData[2] << " " << recData[3] << " " << recData[4] << " " << recData[5] << " " << recData[6] << " " << recData[7] << " has following error: " << error << endl;

	return(error);
}