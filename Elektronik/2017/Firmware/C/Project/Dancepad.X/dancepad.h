/* 
 * File:   dancepad.h
 * Author: astoc
 *
 * Created on 19. April 2018, 16:07
 */

#ifndef DANCEPAD_H
#define	DANCEPAD_H

#define dir_master 100
#define dir_right 140
#define dir_straight 160
#define dir_left 180
#define dir_error 0

// communication bits
#define NOSTATE 0
#define BEYOURSELF 1
#define LIFELEDSYNCH 2
#define LIFELEDBLINK 3
#define SCANTOPOLOGY 4
#define SETRGBCOLOR 5
#define READPIEZO 6

#endif	/* DANCEPAD_H */

// programm for master dancepad
void master_dancepad(unsigned char direction);

// programm for slave dancepad
void slave_dancepad(unsigned char direction);
