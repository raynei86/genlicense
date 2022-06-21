/* A simple tool to generate licenses because copy and paste is uncool */
/* By Zhang Li Hui 2022 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
	MIT,
	BSD_2,
	BSD_3,
	GPL,
	MPL,
} LicenseType;

#define VERSION "0.1"

static void setLicense(const char *license);
static void setAuthor(const char *author);
static void setDate(const char *date);

int
main(int argc, char **argv)
{
	for (int i = 1; i < argc; i++) {
		/* Options that don't take additional arguments */
		if (!strcmp(argv[i], "-h")) {
			puts(
			    "usage: genlicense [-l license] [-a authors] [-d date]");
			exit(EXIT_FAILURE);
		} else if (!strcmp(argv[i], "-v")) {
			puts("genlicense v" VERSION);
			exit(EXIT_FAILURE);
		}

		/* Options that take additional arguments */
		else if (!strcmp(argv[i], "-l"))
			setLicense(argv[++i]);
		else if (!strcmp(argv[i], "-a"))
			setAuthor(argv[++i]);
		else if (!strcmp(argv[i], "-d"))
			setDate(argv[++i]);
		else
			puts(
			    "usage: genlicense [-l license] [-a authors] [-d date]");
	}
}
