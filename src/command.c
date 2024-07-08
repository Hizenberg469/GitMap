#include <command.h>

#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ARR_SIZE(a) (sizeof(a)/sizeof((a)[0]))

#define SMILEY "\xF0\x9F\x98\x8A"
#define SAD "\xF0\x9F\x98\x9E"
#define SALUTE "\xF0\x9F\xAB\xA1"
#define THUMBS_UP "\xF0\x9F\x91\x8D\n"

typedef struct cmd {
	const char* name;
	int (*func)(int argc, char** argv);
	char* usage;
}cmd_t;

static int exit_cmd(int argc, char** argv);
static int help_cmd(int argc, char** argv);
static int scan_cmd(int argc, char** argv);
static int rm_cmd(int argc, char** argv);

static cmd_t s_cmd_table[] = {
	{"exit", exit_cmd, "exit"},
	{"help", help_cmd, "help"},
	{"scan", scan_cmd, "scan \"Option\" <Git Project directory path>\n\
Option:\n\
  -D : Mentioning Directory to scan Multiple Git Project.\n\
  <empty> : For searching for single Git Project on specifed directory.\n"},
	{"rm", rm_cmd, "rm \"Option\" <Git Project directory path>\n\
Option:\n\
  -D : Mentioning Directory to scan Multiple Git Project.\n\
  <empty> : For searching for single Git Project on specifed directory.\n"}
};

static void print_usage(const char* cmdname) {

	for (int i = 0; i < ARR_SIZE(s_cmd_table); i++) {
		if (!strcmp(cmdname, s_cmd_table[i].name)) {
			printf("Command usage: ");
			printf("%s\n", s_cmd_table[i].usage);
			break;
		}
	}
}

static int exit_cmd(int argc, char** argv) {
	
	printf("Exiting GitMap. %s\n", SALUTE);

	exit(EXIT_SUCCESS);
}

static int help_cmd(int argc, char** argv) {
	if (argc != 1) {
		print_usage(argv[0]);
		return CMD_FAIL_CMD;
	}

	for (int i = 0; i < ARR_SIZE(s_cmd_table) ; i++) {
		printf("    %s\n", s_cmd_table[i].usage);
	}

	return CMD_SUCCESS;
}

static int scan_cmd(int argc, char** argv) {

	int ret;

	if (argc < 2) {
		print_usage(argv[0]);
		return CMD_FAIL_CMD;
	}

	if (argv[1] == "-D")
		ret = Multi_Git_Project_scan(argv[2]) ? CMD_SUCCESS : CMD_FAIL_CMD;
	else
		ret = Git_Project_scan(argv[1]) ? CMD_SUCCESS : CMD_FAIL_CMD;

	if (ret == CMD_SUCCESS)
		printf("Successfully scanned Git Project. %s\n", SMILEY);
	else
		printf("Could not scan Git Project. %s\n", SAD);
}

static int rm_cmd(int argc, char** argv) {

	int ret;

	if (argc < 2) {
		print_usage(argv[0]);
		return CMD_FAIL_CMD;
	}

	if (argv[1] == "-D")
		ret = Multi_Git_Project_rm(argv[2]) ? CMD_SUCCESS : CMD_FAIL_CMD;
	else
		ret = Git_Project_rm(argv[1]) ? CMD_SUCCESS : CMD_FAIL_CMD;

	if (ret == CMD_SUCCESS)
		printf("Successfully removed Git Project from DB. %s\n", THUMBS_UP);
	else
		printf("Could not remove mentioned Git Project from DB.\n");

}

int command_exec(int argc, char** argv) {
	
	for (int i = 0; i < ARR_SIZE(s_cmd_table); i++) {
		if (!strcmp(argv[0], s_cmd_table[i].name)) {
			return s_cmd_table[i].func(argc, argv);
		}
	}

	return CMD_FAIL_EXEC;
}

int command_parse_and_exec(char* str) {
	int (*func)(int argc, char** argv) = NULL;
	const char* delims = " \t\n";
	char* token;
	int argc = 0;

	char copy[strlen(str) + 1];
	strcpy(copy, str);
	token = strtok(copy, delims);
	while (token) {
		argc++;
		token = strtok(NULL, delims);
	}

	if (argc == 0)
		return CMD_FAIL_EXEC;

	token = strtok(str, delims);
	for (int i = 0; i < ARR_SIZE(s_cmd_table); i++) {
		if (!strcmp(token, s_cmd_table[i].name)) {
			func = s_cmd_table[i].func;
			break;
		}
	}

	if (!func)
		return CMD_FAIL_EXEC;
	
	char* argv[argc];
	int i = 0;
	do {
		assert(i < argc);
		argv[i++] = token;
		token = strtok(NULL, delims);
	} while (token);

	assert(i == argc);

	return func(argc, argv);
}