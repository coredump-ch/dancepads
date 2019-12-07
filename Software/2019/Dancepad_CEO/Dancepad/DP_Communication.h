/*
 * File:   DP_Communication.h
 * Author: astoc
 *
 * Created on 03. Novembre 2019, 15:11
 */

#pragma once

#ifndef DB_COMMUNICATION_H
#define	DB_COMMUNICATION_H

// Communication bits
#define BEYOURSELF 1
#define SCANTOPOLOGY 2
#define SETRGBCOLOR 3
#define READPIEZO 4

//Set RGB Color
int SetRgbColor(void* handle, unsigned char red, unsigned char green, unsigned char blue);

//Read Piezo Values
int ReadPiezo(void* handle, unsigned char* PiezoData);

#endif