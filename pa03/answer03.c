/*
*==============================================================================
* @Author             : Asheem Chhetri <asheem>
* @Date               : Sunday, June 26th 2016, 3:07:00 pm
* @Email              : achhetri@purdue.edu
* @Project Name       : answer03.c
* @Last modified by   : asheem
* @Last modified time : Tuesday, June 28th 2016, 6:15:05 pm
*==============================================================================
*@Program Purpose     :
* Containing Functions
* char * strcat_ex( char * * dest, int * n, const char * src );
* char ** explode(const char * str, const char * delims, int * arrlen);
* char * implode(char * * strArr, int len, const char * glue);
* void sortStringArray(char * * arrString, int len);
* void sortStringCharacters(char * str);
* void destroyStringArray(char * * strArr, int len);
*==============================================================================
*/

#include <stdlib.h>
#include "answer03.h"
#include <stdio.h>
#include <string.h>

char * strcat_ex( char * * dest, int * n, const char * src )
{
	char * newString;
	if ( ( ( * dest ) == NULL ) || ( strlen ( *dest ) + strlen ( src ) > *n ) )
	{
		if ( * dest != NULL && src != NULL )
		{
			newString = malloc ( 1 + 2 * ( strlen ( *dest ) + strlen ( src ) ) );
			*n = ( 1 + 2 * ( strlen ( *dest ) + strlen ( src ) ) );
		}
		else if ( * dest == NULL )
		{
			newString = malloc ( 1 + 2 * ( strlen ( src ) ) );
			*n = ( 1 + 2 * strlen ( src ) );
		}
		newString[0] = '\0';
		if ( newString != NULL && *dest != NULL )  strcpy ( newString, *dest );
		if ( *dest != NULL )  free ( *dest );

		*dest = newString;
	}
	strcat ( *dest, src );
	return *dest;
}

char ** explode(const char * str, const char * delims, int * arrlen)
{
  int len = strlen(str);
  int i;
  int previous = 0;
  int count = 0;
  char ** ans = NULL;
  *arrlen = 1;
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)  (*arrlen)++;
  }

  ans = (char **) malloc((2*(*arrlen) + 1) * sizeof(char*));
  for (i = 0; i < len; ++i)
  {
    if (strchr(delims,str[i])!=NULL)
      {
        int string = (2*(i-previous) + 1) * sizeof(char);
        ans[count]=(char *)malloc(string);
        memcpy(ans[count],str+previous,(i-previous + 1)*sizeof(char));
        ans[count++][i-previous]='\0';
        previous = i + 1;
      }
  }
  ans[count]=(char *)malloc((2*(len-previous) + 1)*sizeof(char));
  memcpy(ans[count],str + previous,(len - previous + 1)*sizeof(char));
  ans[count++][len - previous] = '\0';
  *arrlen = count;
  return ans;
}

char * implode ( char ** strArr, int len, const char * glue )
{
	char * output;

	int i = 0;
	int retStrLen = 0;

	for ( i = 0; i < len; i++ )
	{
		if ( strArr[i] != NULL )  retStrLen += strlen ( strArr[i] );
	}
	retStrLen += strlen ( glue ) * i + 1;
	output = malloc ( retStrLen * sizeof (char) );
	output[0] = '\0';

	for ( i = 0; i < len - 1; i++ )
	{
		if ( i == 0 )
		{
			output = strcat_ex ( &output, &retStrLen, strArr[i] );
			strcat ( output, glue );
		}
		else
		{
			strcat (output, strArr[i]);
			strcat (output, glue );
		}
	}
	strcat ( output, strArr[i] );
	return output;
}

int cstring_cmp(const void *arg1, const void *arg2)
{
  int compare;

  const char * * ptr1 = ( const char * * ) arg1;
  const char * * ptr2 = ( const char * * ) arg2;

  const char * string1 = *ptr1;
  const char * string2 = *ptr2;

  compare = strcmp (string1, string2);

  if (compare > 0)  return 1;
  else if (compare < 0) return -1;
  else  return 0;
}
void sortStringArray(char ** arrString, int len)
{
  qsort(arrString, len, sizeof(char *), cstring_cmp);
}

int char_cmp(const void * arg1, const void * arg2)
{
  const char * ptr1 = (const char *) arg1;
	const char * ptr2 = (const char *) arg2;

	const char a = *ptr1;
	const char b = *ptr2;

	if (( a - b ) > 0) return 1;
	else if (( a - b ) < 0)  return -1;
	else return 0;
}

void sortStringCharacters(char * str)
{
  int n = strlen(str);
  qsort(str, n, sizeof(str[0]), char_cmp);
}

void destroyStringArray(char ** strArr, int len)
{
  int i;
  if (strArr == NULL)
  {
    return;
  }
  for (i = 0; i < len; i++)
  {
    free(strArr[i]);
  }
  free(strArr);
return;
}
