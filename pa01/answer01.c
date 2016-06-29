/*
*==============================================================================
* @Author             : Asheem Chhetri <asheem>
* @Date               : Tuesday, June 14th 2016, 9:13:32 pm
* @Email              : achhetri@purdue.edu
* @Project Name       : Pa01
* @Last modified by   : asheem
* @Last modified time : Wednesday, June 29th 2016, 2:10:55 pm
*==============================================================================
*@Program Purpose     : Assignment number 1 from calss ECE 264.
* We are required to complete the following functions:
* int arraySum(int * array, int len)
* int arrayCountNegative(int * array, int len)
* int arrayIsIncreasing(int * array, int len)
* int arrayIndexFind(int needle, const int * haystack, int len)
* int arrayFindSmallest(int * array, int len)
*==============================================================================
*/

#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
	if(len <= 0)
  {
      return 0;
  }
  int i;
  int sum = 0;
  for(i = 0; i<len; i++)
  {
      sum += array[i];
  }
	return sum;
}

int arrayCountNegative(int * array, int len)
{
	if(len<=0) return 0;//Returning negative number if array is empty to signify there is fact no negative numbers.
  int count = 0;
  int i;
  for(i=0; i<len; i++)
  {
      if(array[i] < 0) count++;
  }
	return count;
}

int arrayIsIncreasing(int * array, int len)
{
	if(len == 0) return 1;
	if(array == NULL) return 1;
	if(len < 0) return 0;
	int check = 0; //Set to false by default, and its value will be changed as needed.
	int i;
	/*
	    Array starts at index 0,and stops one element before than usual(i.e. if an array has len of 5, then running loop from 0 to 4, we run from 0 to 3)
	    Reason, this is done because we want to avoid array out of bounds issue.
	    As that will generate some random value(in C), and thus causing unexpected behavior.
	*/
	for(i=0; i<(len-1); i++)
	{
	    if(array[i] >= array[i+1]) check = 1;
	    else check = 0;
	}
	return check;
}

int arrayIndexFind(int needle, const int * haystack, int len)
{
	if(len <= 0) return -1;
	int i;
	int index = -1;//Variable to keep track of wether we have found the needle, by default set to not found.
	for(i=0; i<len; i++)
	{
	    if(needle == haystack[i])   index=i;
	}
	return index;return 0;
}

int arrayFindSmallest(int * array, int len)
{
	if(len <= 0) return 0;
	int i = 0;
  int index = i;
  int small = array[i];
  for(i = 1;i<len;i++)
  {
      if(array[i] < small)
      {
          small = array[i];
          index = i;
      }
  }
  return index;
}
int arrayIndexRFind(int needle, const int * haystack, int len)
{
    int index = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        // printf("Elements of i: %d\n",haystack[i]);
        if(needle == haystack[i])
        {
            index = i;
        }
    }
    return index;
}
