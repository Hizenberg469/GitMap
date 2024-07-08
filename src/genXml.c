#include <scan.h>

#include <include/libmxml4/mxml.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define FUNCTION_FAIL 0
#define FUNCTION_SUCCESS 1

#define GIT_PROJECT_PATH_XML "cache/gitProjectPath.xml"

static int synthesize_path(const char* directory_path, const char* git_project_path, char* absolute_path);






static int synthesize_path(const char* directory_path, const char* git_project_path,
	char* absolute_path) {

	char fullPath[PATH_MAX];
	snprintf(fullPath, sizeof(fullPath), "%s/%s", directory_path, git_project_path);

	//char absolute_path[PATH_MAX];
	if (realpath(fullPath, absolute_path) == NULL) {
		printf("Failure in resolving absolute path of the git project: %s", git_project_path);
		return FUNCTION_FAIL;
	}

	return FUNCTION_SUCCESS;
}


int cache_location(const char* directory_path, const char* git_project_path) {

	char absolute_path[PATH_MAX];
	if (!synthesize_path(directory_path, git_project_path, absolute_path)) {
		return FUNCTION_FAIL;
	}

	
}