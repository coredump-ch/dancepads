/*
 * File:   USB_Communication.h
 * Author: astoc
 *
 * Created on 02. Novembre 2019, 11:51
 */

#pragma once

#ifndef USB_COMMUNICATION_H
#define	USB_COMMUNICATION_H

#define USBDATASIZE 8

// Init USB Communication
void* InitUsbComm(wchar_t NewProdDescrip[30]);

// Set USB Product Description
int SetProductDescription(wchar_t NewProdDescrip[30]);

// Open USB Communication
void* OpenUsbComm();

// Close USB Communication
int CloseUsbComm(void* conn);

// Transmit USB Data
int TransmitUsbData(void* conn, unsigned char* I2cTxData);

// Receive USB Data
int ReceiveUsbData(void* conn, unsigned char* I2cRxData);

#endif

