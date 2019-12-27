/*
 * File:   DP_Communication.h
 * Author: astoc
 *
 * Created on 03. Novembre 2019, 15:11
 */

#pragma once

#ifndef DB_COMMUNICATION_H
#define	DB_COMMUNICATION_H

// communication bits
#define BEYOURSELF 1
#define LIFELEDSYNCH 2
#define SCANTOPOLOGY 3
#define SETRGBCOLOR 4
#define READPIEZO 5

// set RGB Color
int SetRgbColor(void* handle, unsigned char red, unsigned char green, unsigned char blue);

// read Piezo Values
int ReadPiezo(void* handle, unsigned char* PiezoData);

// set Life LED
int setLifeLed(void* handle, bool led);

#endif
