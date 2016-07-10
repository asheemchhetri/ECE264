/**
* @Author:              Asheem Chhetri <asheem>
* @Date:                Sunday, July 10th 2016, 12:47:40 pm
* @Email:               achhetri@purdue.edu
* @Project:             echo-lite.c
* @Last modified by:    asheem
* @Last modified time:  Sunday, July 10th 2016, 2:20:47 pm
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  int loopCounter;
  for(loopCounter = 1; loopCounter < argc; loopCounter++) printf("%s ", argv[loopCounter]);
  printf("\n");

  return EXIT_SUCCESS;
}
