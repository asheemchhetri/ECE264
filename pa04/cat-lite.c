/**
* @Author:              Asheem Chhetri <asheem>
* @Date:                Saturday, July 9th 2016, 12:55:48 pm
* @Email:               achhetri@purdue.edu
* @Project:							cat-lite.c
* @Last modified by:    asheem
* @Last modified time:  Sunday, July 10th 2016, 2:39:03 pm
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int fileCheck(char *fileName);
char *helpMsg = "Usage: cat-lite [--help] [FILE]...\nWith no FILE, or when FILE is -, read standard input.\n\n\
Examples:\n\
 cat-lite README   Print the file README to standard output.\n\
 cat-lite f - g    Print f's contents, then standard input, \n\
\t\t   then g's contents.\n\
 cat-lite          Copy standard input to standard output.\n";
 
int main(int argc, char ** argv)
{
	if(argc == 1)
	{
		fileCheck("-");
		return EXIT_SUCCESS;
	}
	int i;
	for(i = 1; i < argc; ++i)
	{
		if(strcmp(argv[i],"--help") ==0)
		{
			printf("%s",helpMsg);
			return EXIT_SUCCESS; //Terminating right here, we are not suppose to proceed.
		}
	}
	int fileCheck_status=0;
	for(i = 1; i < argc; ++i)
	{
		fileCheck_status = fileCheck(argv[i]);
		if(fileCheck_status == EXIT_FAILURE)
		{
			fprintf(stderr,"cat cannot open %s\n", argv[i]);
			return EXIT_FAILURE; //Not able to open a file.
		}
	}
	return EXIT_SUCCESS;
}

/*Helper function:
  fileCheck: check for special character "-", or if it is a normal file.
  Ctrl+D: is terminal own way to terminate user input when "-" is encountered.
*/
int fileCheck(char *fileName)
{
	if(strcmp(fileName,"-") == 0)
	{
		while(!feof(stdin))
		{
			int character = fgetc(stdin);
			if(character > 0)  fputc(character,stdout);
		}
		return EXIT_SUCCESS;
	}

	FILE *file = fopen(fileName, "r");
	if(file == NULL) return EXIT_FAILURE;
	while(!feof(file))
	{
		int character = fgetc(file);
		if(character > 0)		fputc(character, stdout);
	}
	fclose(file);
	return EXIT_SUCCESS;
}
