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

using namespace std;

//Global variables
void* handle;

int main() {
	wchar_t ProdDescrip[30] = L"Dancepad_Master";
	bool FirstRun = FALSE;
	int error = 0;

	if (FirstRun)
	{
		error = SetProductDescription(ProdDescrip);
		if (error != 0)
		{
			cout << "Product Description not written successfull" << endl;
		}
	}

	handle = InitUsbComm(ProdDescrip);

	error = CloseUsbComm(handle);
	if (error != 0)
	{
		cout << "Device not successfully closed " << error << endl;
	}

	cout << "Muahaha, I've done it" << endl;
	return 0;
}