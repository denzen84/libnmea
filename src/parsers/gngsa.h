#ifndef INC_NMEA_GNGSA_H
#define INC_NMEA_GNGSA_H

#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <nmea.h>

typedef struct {
	nmea_s base;
	char mode; /* M = manual (forced 2D or 3D), A = automatic */
	char fixtype; /* 1 = no fix, 2 = 2D, 3 = 3D */
	int satID_00;
	int satID_01;
	int satID_02;
	int satID_03;
	int satID_04;
	int satID_05;
	int satID_06;
	int satID_07;
	int satID_08;
	int satID_09;
	int satID_10;
	int satID_11;
	double pdop;
	double hdop;
	double vdop;
} nmea_gngsa_s;

/* Value indexes */
#define NMEA_GNGSA_MODE 0
#define NMEA_GNGSA_FIXTYPE 1
#define NMEA_GNGSA_SATID_00 2
#define NMEA_GNGSA_SATID_01 3
#define NMEA_GNGSA_SATID_02 4
#define NMEA_GNGSA_SATID_03 5
#define NMEA_GNGSA_SATID_04 6
#define NMEA_GNGSA_SATID_05 7
#define NMEA_GNGSA_SATID_06 8
#define NMEA_GNGSA_SATID_07 9
#define NMEA_GNGSA_SATID_08 10
#define NMEA_GNGSA_SATID_09 11
#define NMEA_GNGSA_SATID_10 12
#define NMEA_GNGSA_SATID_11 13
#define NMEA_GNGSA_PDOP 14
#define NMEA_GNGSA_HDOP 15
#define NMEA_GNGSA_VDOP 16

#endif  /* INC_NMEA_GNGSA_H */
