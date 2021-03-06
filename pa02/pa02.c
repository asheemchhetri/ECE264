/*
*==============================================================================
* @Author             : Asheem Chhetri <asheem>
* @Date               : Wednesday, June 22nd 2016, 4:14:34 pm
* @Email              : achhetri@purdue.edu
* @Project Name       :
* @Last modified by   : asheem
* @Last modified time : Wednesday, June 22nd 2016, 4:40:41 pm
*==============================================================================
*@Program Purpose     :
*
*
*
*
*==============================================================================
*/

#include <stdio.h>
#include <string.h>

#include "answer02.h"

#define BUFFER_LEN 1024

int main(int argc, char * * argv)
{
    printf("Welcome to PA02.\n"
	   "\n"
	   "You are encouraged to edit this file in order to test\n"
	   "the behavior of the functions you write in answer02.c\n"
	   "\n"
	   "This file will not be marked, and should not be\n"
	   "submitted.\n"
	   "\n"
	   "Don't forget to post questions on Blackboard, and ask\n"
	   "the TAs and your classmates for help.\n"
	   "\n");

    const char * s1 = "Hello World!";
    const char * s2 = "";
    const char * s3 = "foo";
    const char * s4 = "yolo\0wolo";
    const char * s5 = "ufff";

	// -- my_strlen, should be: 12, 0, and 3
    printf("my_strlen(\"%s\") = %d\n", s1, (int) my_strlen(s1));
    printf("my_strlen(\"%s\") = %d\n", s2, (int) my_strlen(s2));
    printf("my_strlen(\"%s\") = %d\n", s3, (int) my_strlen(s3));
    printf("my_strlen(\"%s\") = %d\n", s4, (int) my_strlen(s4));
    printf("my_strlen(\"%s\") = %d\n", s5, (int) my_strlen(s5));

	// -- my_countchar, should be: 3, 0, and 2
    printf("my_countchar(\"%s\", 'l') = %d\n", s1, (int) my_countchar(s1, 'l'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s2, (int) my_countchar(s2, 'o'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s3, (int) my_countchar(s3, 'o'));
    printf("my_countchar(\"%s\", 'o') = %d\n", s4, (int) my_countchar(s4, 'o'));

	// -- my_strchr, should be: "orld!", "(null)", and ""
    printf("my_strchr(\"%s\", 'l') = %s\n", s1, my_strchr(s1, 'l'));
    printf("my_strchr(\"%s\", 'o') = %s\n", s2, my_strchr(s2, 'o'));
    printf("my_strchr(\"%s\", '\\0') = %s\n", s3, my_strchr(s3, '\0'));
	  printf("my_strchr(\"%s\", '\\0') = %s\n", s4, my_strrchr(s4, '\0'));

	// -- my_strstr, should be: "World!", "Hello World!", "(null)"
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "World"));
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "ld"));
    printf("my_strstr(\"%s\", \"World\") = %s\n", s1, my_strstr(s1, "ello"));
    printf("my_strstr(\"%s\", \"\") = %s\n", s1, my_strstr(s1, ""));
    printf("my_strstr(\"%s\", \"hello\") = %s\n", s1, my_strstr(s1, "hello"));

	// -- my_strcpy. For this function you need a buffer where you
    // copy the string to.
    char buffer[50];
    my_strcpy(buffer, s1);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s1, buffer);
    my_strcpy(buffer, s2);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s2, buffer);
    my_strcpy(buffer, s3);
    printf("my_strcpy(buffer, \"%s\"), buffer = \"%s\"\n", s3, buffer);

	// -- my_strcat. You will have to do this yourself.
    // Look at my_strcpy for an example, and go from there.
    // char buffer[50];
    // my_strcpy(buffer, "Hello ");
    my_strcat(buffer, "Zippy!");
    // printf("%s\n",buffer);
    printf("%s\n", my_strcat(buffer, "Zippy!")); // prints "Hello Zippy!"

    // -- my_isspace. You will have to do this for yourself.

    printf("Is space status: %d\n", my_isspace(' '));
    printf("Is space status: %d\n", my_isspace('A'));
    printf("Is space status: %d\n", my_isspace('C'));
    printf("Is space status: %d\n", my_isspace('\t'));
    printf("Is space status: %d\n", my_isspace('a'));
    printf("Is space status: %d\n", my_isspace('m'));
    printf("Is space status: %d\n", my_isspace('\f'));
    printf("Is space status: %d\n", my_isspace('\n'));
    printf("Is space status: %d\n", my_isspace('X'));
    printf("Is space status: %d\n", my_isspace('Z'));
    printf("Is space status: %d\n", my_isspace(' '));
    printf("Is space status: %d\n", my_isspace('\r'));
    printf("Is space status: %d\n", my_isspace('\t'));
    printf("Is space status: %d\n", my_isspace('\v'));
    printf("Is space status: %d\n", my_isspace('h'));
    printf("Is space status: %d\n", my_isspace(';'));

    // -- my_atoi. You will have to do this for yourself.

	printf("Atoi result of string: %d\n",my_atoi("24")); // 0
    printf("Atoi result of string: %d\n",my_atoi("-12")); // -12
    printf("Atoi result of string: %d\n",my_atoi("15th of March would be the ides.")); // 15
    printf("Atoi result of string: %d\n",my_atoi("4 months to Summer.")); // 4
    printf("Atoi result of string: %d\n",my_atoi("\n\f\t\v\r 6 white space characters handled correctly.")); // 6
    printf("Atoi result of string: %d\n",my_atoi("garbage, instead of a number like 73 for example, should yield a zero")); //0
    printf("\n\n");
	return EXIT_SUCCESS;
}
