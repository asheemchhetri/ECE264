/*
*==============================================================================
* @Author             : Asheem Chhetri <asheem>
* @Date               : Wednesday, June 22nd 2016, 4:17:38 pm
* @Email              : achhetri@purdue.edu
* @Project Name       :
* @Last modified by   : asheem
* @Last modified time : Wednesday, June 22nd 2016, 4:22:31 pm
*==============================================================================
*@Program Purpose     : Relates to PA02 from the class ECE 264.
* Function description are provided in the <answer02.h> file.
*
*
*
*
*==============================================================================
*/

#include <stdlib.h>
#include "answer02.h"

size_t my_strlen(const char * str)
{
    int length = 0; // Variable to hold the value of the length of any given string.
    int i = 0; // Test counter for while loop, to access each element of character array.
    while (str[i] != '\0') // Keep iterating over single character untill we reach a special character: NULL terminator
    {
        length += 1;
        i += 1;
    }
	return length;
}

char * my_strrchr(const char * str, int ch)
{
	char * targetCh = NULL;
// 	int index = 0;
	while(*str != '\0')
	{
	    if(*str == (char)ch)
	    {
	        targetCh = (char*)str;
	    }
	    str++;
	}
    if((char)ch == '\0')    return "";
	else return (char *)targetCh;
}

int my_countchar(const char * str, char ch)
{
    int count = 0; // Variable to hold the amount of occurence of charcter <ch> in string <str>.
    int i = 0; // Test counter for while loop, to access each element of character array.
    while(str[i] != '\0') // Keep iterating over single character untill we reach a special character: NULL terminator
    {
        if(str[i] == ch)
        {
            count += 1;
            i++;
        }
        else    i++;
    }
    return count;
}

char * my_strchr(const char * str, int ch)
{
    while (*str != '\0' && *str != (char)ch)
    {
         str++;
    }
     return ((*str == ch) ? (char *) str : NULL );
}

int my_isspace(int ch)
{
    if( (ch == ' ') || (ch == '\f') || (ch == '\n') || (ch == '\r') || (ch == '\t') || (ch == '\v'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int my_atoi(const char * str)
{
    if (str == NULL)    return 0;

    int res = 0;  // Initialize result
    int sign = 1;  // Initialize sign as positive
    int i = 0;  // Initialize index of first digit
    while(my_isspace(str[i]) == 1)
    {
        i++;
    }

    // If number is negative, then update sign
    if (str[i] == '-')
    {
        sign = -1;
        i++;  // Also update index of first digit
    }

    else if(str[i]=='+')
    {
        i++;
    }

    // Iterate through all digits of input string and update result
    for (; str[i] != '\0'; ++i)
    {
        if ((str[i] >= '0' && str[i] <= '9') == 0)
        {
            break;
        }
        res = res*10 + str[i] - '0';
    }

    // Return result with sign
    return sign*res;
}

char * my_strcat(char * dest, const char * src)
{
    char *s = dest;
    size_t n = my_strlen(src) + 1;
     while (*s != '\0')
     {
         s++;
     }
     while (n != 0 && (*s = *src++) != '\0')
     {
         n--;
         s++;
     }
     if (*s != '\0')
     {
         *s = '\0';
     }
     return dest;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int i = 0;
  int j = 0;
  int k = 0;
  int len_hay = my_strlen(haystack);
  int len_needle = my_strlen(needle);

  if(len_needle == 0)   return (char *) haystack+i;

  for(i=0;i<len_hay;i++)
  {
    if(*(haystack+i)==*(needle+j))
	{
	  for(k=i;k<len_hay;k++)
	  {
	    if(*(haystack+k) == (*(needle+j)))
		{
		  if(j==len_needle-1)   return (char *) (haystack+(k-j));
		  j++;
		}
	      else  break;
	  }
	}
  }
  return NULL;
}

char * my_strcpy(char * dest, const char * src)
{
    while(*src != '\0')
    {
        *dest = *src;
        // printf("%s\n",(char*)src);
        src++;
        dest++;
    }
    *dest = '\0';
    return (char*)dest;
}
