/*
 * File:   Dancepad_V1.cpp
 * Author: astoc
 *
 * Created on 02. November 2019, 10:06
 */

#include <iostream>
#include <Windows.h>
#include "mcp2221_dll_um.h"
#include "USB_Communication.h"
#include "DP_Communication.h"
#include "hsi.h"

using namespace std;

//Global variables
void* handle;

int main() {
	wchar_t ProdDescrip[30] = L"Dancepad_Master";
	bool FirstRun = FALSE;
	int error = 0;
	RGB rgbColor;
	unsigned char Data[USBDATASIZE];
	unsigned char piezoValues[5];

	for (int i = 0; i < USBDATASIZE; i++)
	{
		Data[i] = 2+i;
	}

	if (FirstRun)
	{
		error = SetProductDescription(ProdDescrip);
		if (error != 0)
		{
			cout << "Product Description not written successfull" << endl;
		}
	}

	handle = InitUsbComm(ProdDescrip);

	while (1)
	{
		for (float hue = 0; hue < 360; hue++)
		{
			rgbColor = hsi2rgb(hue, 1, 0.1);

			//	error = TransmitUsbData(handle, Data);
			error = SetRgbColor(handle, rgbColor.r, rgbColor.g, rgbColor.b);

			//	error = ReceiveUsbData(handle, Data);
			error = ReadPiezo(handle, piezoValues);

			wcout << "Piezodata; Integrated (func): " << piezoValues[0] << " Integrated (point): " << piezoValues[1] << " Piezo 1: " << piezoValues[2] << " Piezo 2: " << piezoValues[3] << " Piezo 3: " << piezoValues[4] << " Piezo 4: " << piezoValues[5] << endl;

//			wcout << "Read Data: " << Data[0] << " " << Data[1] << " " << Data[2] << " " << Data[3] << " " << Data[4] << " " << Data[5] << " " << Data[6] << " " << Data[7] << " has following error: " << error << endl;
		}
}
	error = CloseUsbComm(handle);
	if (error != 0)
	{
		cout << "Device not successfully closed " << error << endl;
	}


	cout << "Muahaha, I've done it" << endl;
	return 0;
}
