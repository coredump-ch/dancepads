#include <stdio.h>
#include <conio.h>
#include <Windows.h>
#include "mcp2221_dll_um.h"

#pragma comment(lib, "mcp2221_dll_um_x86.lib")  //Link MCP2221 library, applicable for visual studio only

//Global variables
void *handle;

void ExitFunc()
{
 printf("Closing\n");
 _sleep(10);
 //Mcp2221_Reset(handle);
 
 //Close all devices at exit
 Mcp2221_CloseAll();
}
int main()
{
 wchar_t LibVer[6];
 wchar_t MfrDescriptor[30];
 wchar_t ProdDescrip[30];
 int ver = 0; 
 int error = 0;
 int flag = 0;
 unsigned char pinFunc[4] = {MCP2221_GPFUNC_IO, MCP2221_GPFUNC_IO, MCP2221_GP_DAC, MCP2221_GPFUNC_IO};  //Set GP0, GP1, GP3 as digital IO and GP2 as DAC
 unsigned char pinDir[4] = {MCP2221_GPDIR_OUTPUT, MCP2221_GPDIR_OUTPUT, NO_CHANGE, MCP2221_GPDIR_OUTPUT};  //configure GP0, GP1, GP3 as digital output
 unsigned char OutValues[4] = {0, 0, NO_CHANGE, 0};   //set initial values to 0's
 unsigned char PowerAttrib;
 unsigned char DacVal = 31;
 unsigned char DacRefValue = 0;
 unsigned int ReqCurrent;
 unsigned int PID = 0xDD;
 unsigned int VID = 0x4D8;
 unsigned int NumOfDev = 0;

 atexit(ExitFunc); //Call exit function

 ver = Mcp2221_GetLibraryVersion(LibVer);  //Get DLL version
 if(ver == 0)
  printf("Library (DLL) version: %ls\n", LibVer);
 else
 {
  error = Mcp2221_GetLastError();
  printf("Version can't be found, version: %d, error: %d\n", ver, error);
 }

 //Get number of connected devices with this VID & PID
 Mcp2221_GetConnectedDevices(VID, PID, &NumOfDev);
 if(NumOfDev == 0)
 {
  printf("No MCP2221 devices connected\n");
  exit(0);
 }
 else
  printf("Number of devices found: %d\n", NumOfDev);   

 //Open first MCP2221 device discovered by index
 handle = Mcp2221_OpenByIndex(VID, PID, NumOfDev-1); 
 error = Mcp2221_GetLastError();
 if(error == NULL)
  printf("Connection successful\n");
 else
  printf("Error message is %s\n", error);

 //Get manufacturer descriptor
 flag = Mcp2221_GetManufacturerDescriptor(handle, MfrDescriptor);
 if(flag == 0)
  printf("Manufacturer descriptor: %ls\n", MfrDescriptor);
 else
  printf("Error getting descriptor: %d\n", flag);

 //Get product descriptor
 flag = Mcp2221_GetProductDescriptor(handle, ProdDescrip);
 if(flag == 0)
  printf("Product descriptor: %ls\n", ProdDescrip);
 else
  printf("Error getting product descriptor: %d\n", flag);
  
 //Get power attributes
 flag = Mcp2221_GetUsbPowerAttributes(handle, &PowerAttrib, &ReqCurrent);
 if(flag == 0)
  printf("Power Attributes, %x\nRequested current units = %d\nRequested current(mA) = %d\n", PowerAttrib, ReqCurrent, ReqCurrent*2);
 else
  printf("Error getting power attributes: %d\n", flag);

 //Set GPIO
 flag = Mcp2221_SetGpioSettings(handle, RUNTIME_SETTINGS, pinFunc, pinDir, OutValues);
 if(flag != 0)
 {
  printf("Error setting GPIO, error: %d\n", flag);
  system("pause");
 }
 Mcp2221_SetGpioValues(handle, OutValues); //reset all pins at initialization

 //Set DAC reference to VDD
 flag = Mcp2221_SetDacVref(handle, RUNTIME_SETTINGS, VREF_VDD);
 
 if(flag != 0)
 {
  printf("Error setting DAC reference, error: %d\n", flag);
  system("pause");
 }

 while(1)
 {
  //Set DAC value on GP2
  DacVal++;
  if(DacVal == 32)
   DacVal = 0;
  printf("DAC value is: %x\n", DacVal);
  flag = Mcp2221_SetDacValue(handle, RUNTIME_SETTINGS, DacVal);  //must use "RUNTIME_SETTINGS" to enable and output voltage to the DAC
  if(flag != 0)
  {
   printf("Error setting DAC, error: %d\n", flag);
   system("pause");
  }

  //Toggle GPIO pins: GP0, GP1, GP3 for 50mS
  OutValues[0] = MCP2221_GPVAL_HIGH;  //set GP0 (output high)
  OutValues[1] = MCP2221_GPVAL_LOW;   //reset GP1 (output low)
  OutValues[3] = MCP2221_GPVAL_LOW;   //reset GP3 (output low)
  Mcp2221_SetGpioValues(handle, OutValues);  //now set the DIO pins values
  _sleep(50);    //wait for 50mS
  OutValues[0] = MCP2221_GPVAL_LOW;    //reset GP0 (output low)
  OutValues[1] = MCP2221_GPVAL_HIGH;   //set GP1 (output high)
  OutValues[3] = MCP2221_GPVAL_HIGH;   //set GP3 (output high)
  Mcp2221_SetGpioValues(handle, OutValues);   //now set the DIO pins values
  _sleep(50);    //wait for 50mS
 }
 return 0;
}