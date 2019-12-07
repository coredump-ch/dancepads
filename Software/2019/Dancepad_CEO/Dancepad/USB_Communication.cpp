/*
 * File:   USB_Communication.cpp
 * Author: astoc
 *
 * Created on 02. Novembre 2019, 11:53
 */

#include <iostream>
#include <Windows.h>
#include <wchar.h>
#include "mcp2221_dll_um.h"
#include "USB_Communication.h"

using namespace std;

//Global variables
void* conn;

void* InitUsbComm(wchar_t NomProdDescrip[30])
{
	int i = 0;
	int ver = 0;
	int error = 0;
	int flag = 0;
	unsigned int PID = 0xDD;
	unsigned int VID = 0x4D8;
	unsigned int NumOfDev = 0;
	wchar_t ActProdDescrip[30];

	//Get number of connected devices with this VID & PID
	Mcp2221_GetConnectedDevices(VID, PID, &NumOfDev);
	if (NumOfDev == 0)
	{
		cout << "No MCP2221 devices connected" << endl;
	}

	for (unsigned int i = 0; i <= (NumOfDev - 1); i++)
	{
		//Open first MCP2221 device discovered by index
		conn = Mcp2221_OpenByIndex(VID, PID, i);
		error = Mcp2221_GetLastError();
		if (error != NULL)
		{
			cout << "Error message is " << error << endl;
		}

		//Get product descriptor
		flag = Mcp2221_GetProductDescriptor(conn, ActProdDescrip);
		if (flag != 0)
		{
			cout << "Error getting product descriptor: " << flag << endl;
		}

		//Check if correct handle is opened
		if (0 == wcscmp(ActProdDescrip, NomProdDescrip))
		{
			cout << "USB Connection established." << endl;
			return(conn);
		}
		else
		{
			//Close communication
			flag = Mcp2221_Close(conn);
			if (flag == 0)
			{
				cout << "Connection closing of unused Devises successful" << endl;
			}
			else
			{
				cout << "Error message is " << flag << endl;
			}
		}
	}
	return(conn);
}

int SetProductDescription(wchar_t NewProdDescrip[30])
{
	int flag = 0;
	unsigned int PID = 0xDD;
	unsigned int VID = 0x4D8;
	unsigned int NumOfDev = 0;

	//Get number of connected devices with this VID & PID
	Mcp2221_GetConnectedDevices(VID, PID, &NumOfDev);
	if (NumOfDev == 0)
	{
		cout << "No MCP2221 devices connected" << endl;
		return(-1);
	}
	else if (NumOfDev == 1)
	{
		cout << "One Device found. New Product Description can be programmed." << endl;

	}
	else
	{
		cout << "Too many Devices found. Number of devices found: " << NumOfDev << endl;
		return(-1);
	}

	//Open first MCP2221 device discovered by index
	conn = Mcp2221_OpenByIndex(VID, PID, NumOfDev - 1);
	flag = Mcp2221_GetLastError();
	if (flag == NULL)
	{
		cout << "Connection successful" << endl;
	}
	else
	{
		cout << "Error message is " << flag << endl;
		return(-1);
	}

	//Set product descriptor
	flag = Mcp2221_SetProductDescriptor(conn, NewProdDescrip);
	if (flag == 0)
	{
		wcout << "New Product descriptor: " << NewProdDescrip << endl;
	}
	else
	{
		cout << "Error setting product descriptor: " << flag << endl;
		return(-1);
	}

	//Close communication
	flag = Mcp2221_Close(conn);
	if (flag == 0)
	{
		cout << "Connection  closing successful" << endl;
	}
	else
	{
		cout << "Error message is " << flag << endl;
		return(-1);
	}

	return(0);
}

void* OpenUsbComm()
{
    wchar_t ProdDescrip[30] = L"Dancepad_Master";
    unsigned char Data[USBDATASIZE];
    bool FirstRun = 0;
    int error = 0;

    for (unsigned char i = 0; i < USBDATASIZE; i++)
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

  conn = InitUsbComm(ProdDescrip);

  return(conn);
}

int CloseUsbComm(void* conn)
{
	int flag = 0;

	//Close communication
	flag = Mcp2221_Close(conn);
	if (flag == 0)
	{
		cout << "USB Communication closed successful" << endl;
		return(0);
	}
	else
	{
		cout << "Error message is " << flag << endl;
		return(-1);
	}
}


int TransmitUsbData(void* conn, unsigned char* I2cTxData)
{
	int flag = 0;

	flag = Mcp2221_I2cWrite(conn, USBDATASIZE, 0xA, 1, I2cTxData);
	if (flag != 0)
	{
		cout << "Data haven't been written correctly. Errorcode: " << flag << endl;
		return(-1);
	}
	return(0);
}

int ReceiveUsbData(void* conn, unsigned char* I2cRxData)
{
	int flag = 0;

	flag = Mcp2221_I2cRead(conn, USBDATASIZE, 0xA, 1, I2cRxData);
	if (flag != 0)
	{
		cout << "Data haven't been read correctly. Errorcode: " << flag << endl;
		return(-1);
	}
	return(0);	
}
