#ifndef TYPES_H_
#define TYPES_H_
#define NULL ((void*)0)

typedef unsigned char ukimo8;
typedef unsigned short ukimo16 ;
typedef unsigned int ukimo32;
typedef unsigned long int ukimo64;

typedef signed char kimo8;
typedef signed short kimo16 ;
typedef signed int kimo32;
typedef signed long int kimo64;

typedef enum {
	STATE_SUCCESS,
	STATE_INAVALIED_COMMAND,
	STATE_INVALIED_DATA,
	STATE_INVALIED_STRING,
	STATE_INVALIED,
	}check_error;

#endif 
