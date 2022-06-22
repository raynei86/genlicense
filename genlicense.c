/* A simple tool to generate licenses because copy and paste is uncool */
/* By Zhang Li Hui 2022 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "licenses.h"

#define VERSION "0.1"

static void run(void);
static void parseAuthor(char **args, int pos, char *buf);

static char *license, author[128], *date; // Interesting syntax

static void
run()
{
	FILE *f = fopen("LICENSE", "w");

	if (!strcmp(license, "mit"))
		fprintf(f, MIT, date, author);
	else if (!strcmp(license, "bsd_2"))
		fprintf(f, BSD_2, date, author);
	else if (!strcmp(license, "bsd_3"))
		fprintf(f, BSD_3, date, author);

	fclose(f);
}

static void
parseAuthor(char **args, int pos, char *buf)
{
	for (char *c = args[pos]; strstr(c, "-") == NULL; c = args[pos]) {
		strcat(buf, c);
		strcat(buf, " ");
		pos++;
	}
}

int
main(int argc, char **argv)
{
	if (argc < 2) {
		puts("usage: genlicense [-l license] [-a authors] [-d date]");
		exit(EXIT_FAILURE);
	}

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
			license = argv[++i];
		else if (!strcmp(argv[i], "-a"))
			parseAuthor(argv, ++i, author);
		else if (!strcmp(argv[i], "-d"))
			date = argv[++i];
	}

	run();
}
