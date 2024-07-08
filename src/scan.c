#include <scan.h>

#include <dirent.h>

#define FUNCTION_FAIL 0
#define FUNCTION_SUCCESS 1

int Multi_Git_Project_scan(char* str) {

}

int Git_Project_scan(char* directoryPath) {
	struct dirent* entry;

	DIR* dp = opendir(directoryPath);

	if (dp == NULL) {
		return FUNCTION_FAIL;
	}

	while (entry = readdir(dp)) {

		if (entry->d_type == DT_DIR) {

			if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
				continue;
			}

			if (strcmp(entry->d_name, ".git") == 0) {
				return FUNCTION_SUCCESS;
			}

		}
	}

	return FUNCTION_FAIL;
}

int Multi_Git_Project_rm(char* str) {

}

int Git_Project_rm(char* str) {

}
