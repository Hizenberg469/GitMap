#ifndef __COMMAND_H
#define __COMMAND_H

#include <stddef.h>

enum {
	CMD_SUCCESS = 0,
	CMD_FAIL_EXEC,
	CMD_FAIL_CMD
};

/*
* Defined in scan.c source file.
*/
int Multi_Git_Project_scan(char* str);
int Git_Project_scan(char* str);
int Multi_Git_Project_rm(char* str);
int Git_Project_rm(char* str);

int
command_exec(int argc, char** argv);

int
command_parse_and_exec(char* str);

#endif