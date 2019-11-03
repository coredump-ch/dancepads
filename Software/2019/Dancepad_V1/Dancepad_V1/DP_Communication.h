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
#define SETRGBCOLOR 1

//Set RGB Color
int SetRgbColor(void* handle, unsigned char red, unsigned char green, unsigned char blue);

#endif