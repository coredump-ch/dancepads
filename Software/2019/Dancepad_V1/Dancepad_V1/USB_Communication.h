/*
 * File:   USB_Communication.h
 * Author: astoc
 *
 * Created on 02. Novembre 2019, 11:51
 */

#pragma once

#ifndef USB_COMMUNICATION_H
#define	USB_COMMUNICATION_H

//Init USB Communication
void* InitUsbComm(wchar_t NewProdDescrip[30]);

//Set USB Product Description
int SetProductDescription(wchar_t NewProdDescrip[30]);

//Close USB Communication
int CloseUsbComm(void* conn);

#endif

