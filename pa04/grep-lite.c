/**
* @Author:              Asheem Chhetri <asheem>
* @Date:                Thursday, July 7th 2016, 7:38:20 pm
* @Email:               achhetri@purdue.edu
* @Project:             grep-lite.c
* @Last modified by:    asheem
* @Last modified time:  Sunday, July 10th 2016, 2:38:44 pm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
  -v: --invert-match 	var: forInvertMatch
  -n: --line-number 	var: forLineNumber
  -q: --quiet 				var: forQuiet
*/
char *helpMsg = "\
Usage: grep-lite [OPTION]... PATTERN\n\
Search for PATTERN in standard input. PATTERN is a\n\
string. grep-lite will search standard input line by\n\
line, and (by default) print out those lines which\n\
contain pattern as a substring.\n\
\n\
 -v, --invert-match     print non-matching lines\n\
 -n, --line-number      print line number with output\n\
 -q, --quiet            suppress all output\n\
\n\
Exit status is 0 if any line is selected, 1 otherwise;\n\
if any error occurs, then the exit status is 2.\n";

int main(int argc, char **argv)
{
	int forInvertMatch=0;
  int forLineNumber=0;
  int forQuiet=0;
  int i;
  char *printString = NULL;
	for(i = 0; i < argc; ++i)
	{
		if(strcmp(argv[i], "--help") == 0)
		{
			printf("%s",helpMsg);
			return EXIT_SUCCESS; //if --help was encountered then stop here.
		}
		else if(strcmp(argv[i],"-v") == 0 || strcmp(argv[i],"--invert-match") == 0)  forInvertMatch = 1;
		else if(strcmp(argv[i],"-n") == 0 || strcmp(argv[i],"--line-number") == 0)  forLineNumber = 1;
		else if(strcmp(argv[i],"-q") == 0 || strcmp(argv[i],"--quiet") == 0)  forQuiet = 1;
		else if(argv[i][0]=='-' && i != (argc-1) )
		{
			fprintf(stderr, "Command passed cannot be undertood! Terminating!");
			return 2;
		}
	}
	if(argv[argc-1][0]=='-')
	{
		fprintf(stderr, "'-' is used as a pattern, which is not allowed! Terminating!!");
		return 2;
	}

  //2001: because we need one extra for NULL terminating character.
	char *str =  malloc(2001*sizeof(char));
  if(str == NULL)
  {
    fprintf(stderr, "Something went wrong on our side, cannot allocate memory! Terminating!");
    return 2;
  }
	int lineNum = 1;
  int valueFoundTracking = 0;
	int check;
	while((check = !feof(stdin)))
	{
		fgets(str,2000,stdin);
		printString = strstr(str, argv[argc-1]);
		if(printString != NULL) valueFoundTracking = 1;
		if(!forQuiet)
		{
			if(!forInvertMatch)
			{
				if(printString != NULL)
				{
					if(forLineNumber)  fprintf(stdout, "%d: ", lineNum);
					fprintf(stdout, "%s", str);
				}
			}
			else
			{
				if(printString == NULL && str[0] != '\0')
				{
					if(forLineNumber)  fprintf(stdout, "%d: ", lineNum);
					fprintf(stdout,"%s", str);
				}
			}
		}
		lineNum++;
		printString = NULL;
		str[0] = '\0';
	}
	free(str);

	return 1 - valueFoundTracking;
}
