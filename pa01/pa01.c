#include <stdio.h>
#include <stdlib.h>

// The line below includes the /definitions/ of the functions that you write
// in this assignment. Including the definitions allows you to use
// the functions in this file.
#include "answer01.h"

void printArray(int * array, int len)
{
    printf("{");
    int ind;
    for(ind = 0; ind < len; ++ind) {
	printf("%d", array[ind]);
	if(ind != len - 1) {
	    printf(", ");
	}
    }
    printf("}");
    // If we don't include a '\n' character, then we need to
    // include this line to ensure that our output is immediately
    // printed out output.
    fflush(stdout);
}

void test_arraySum(int * array, int len, int expected)
{
    printArray(array, len);
    int sum = arraySum(array, len);
    printf(". sum = %d, expected = %d.", sum, expected);
    if(sum != expected)
	printf(" FAIL");
    printf("\n");
}

void test_00_arraySum()
{
    printf("Testing arraySum(...)\n");

    // Here we use "static initialization" to create an array
    int array1[] = { -4, -1, 0, 1, 5, 10, 20, 21 };
    int len1 = 8;
    int expected1 = 52;
    test_arraySum(array1, len1, expected1);

    // Our functions must always work... even on empty arrays
    int array2[] = {};
    int len2 = 0;
    int expected2 = 0;
    test_arraySum(array2, len2, expected2);

    // You can add more test-cases here
    // ...

    printf("\n"); // Tidy output is easier to use
}

void test_arrayCountNegative(int * array, int len, int expected)
{
    printArray(array, len);
    int count = arrayCountNegative(array,len);
    printf(". count = %d, expected = %d.", count, expected);
    if(count != expected)
	printf(" FAIL");
    printf("\n");
}

void test_01_arrayCountNegative()
{
    printf("Testing arrayCountNegative(...)\n");

    int array1[] = { 1, 4, -5, 4 };
    int len1 = 4;
    test_arrayCountNegative(array1, len1, 1);

    int array2[] = {};
    int len2 = 0;
    test_arrayCountNegative(array2, len2, 0);

    int array3[] = { 0, 1, 2, 3, 4 };
    int len3 = 5;
    test_arrayCountNegative(array3, len3, 0);

    int array4[] = { -1, -2, -3, -4 };
    int len4 = 4;
    test_arrayCountNegative(array4, len4, 4);

    // You can add more test-cases here
    // ...

    printf("\n");
}

void test_arrayIsIncreasing()
{
  int array1[] = {1, 1, 2, 3, 3};
  int len1 = 5;
  int array2[] = {1, 2, 0, 4};
  int len2 = 4;
  int isInc1 = arrayIsIncreasing(array1, len1); //isInc1 == 1
  int isInc2 = arrayIsIncreasing(array2, len2); //isInc2 == 0
  int isInc3 = arrayIsIncreasing(NULL,0);		  //isInc3 == 1
  printf("%d\n",isInc1);
  printf("%d\n",isInc2);
  printf("%d\n",isInc3);
}
void test_arrayIndexFind()
{
  int array1[] = {1, 1, 2, 3, 3};
  int len1 = 5;
  int array2[] = {1, 2, 0, 4};
  int len2 = 4;
  int isInc1 = arrayIndexFind(1,array1, len1); //isInc1 == 1
  int isInc2 = arrayIndexFind(0,array2, len2); //isInc2 == 2
  int isInc3 = arrayIndexFind(-1,NULL,0);		  //isInc3 == -1
  printf("%d\n",isInc1);
  printf("%d\n",isInc2);
  printf("%d\n",isInc3);
  int haystack[] = { 1, 4, -5, 4 };
  int len = 4;
  int x1 = arrayIndexFind(1, haystack, len); // x1 == 0
  int x2 = arrayIndexFind(4, haystack, len); // x2 == 3
  int x3 = arrayIndexFind(6, haystack, len); // x3 == -1
  printf("%d\n",x1);
  printf("%d\n",x2);
  printf("%d\n",x3);
}
void test_arraySmallFind()
{
  printf("\n\n");
  int array1[] = {1, 1, -1, 2, 3, 3};
  int len1 = 6;
  int array2[] = {1, 2, 0, 4};
  int len2 = 4;
  int isInc1 = arrayFindSmallest(array1, len1); //isInc1 == 2
  int isInc2 = arrayFindSmallest(array2, len2); //isInc2 == 2
  int isInc3 = arrayFindSmallest(NULL,0);		  //isInc3 == 0
  printf("%d\n",isInc1);
  printf("%d\n",isInc2);
  printf("%d\n",isInc3);
  int haystack[] = { 1, 4, -5, -8 };
  int len = 4;
  int haystack1[] = { 3, 4, -5 };
  int len3 = 3;
  int x1 = arrayFindSmallest(haystack, len); // x1 == 3
  int x2 = arrayFindSmallest(haystack1, len3); // x2 == 2
  printf("%d\n",x1);
  printf("%d\n",x2);
}

int main(int argc, char * * argv)
{
    printf("Welcome to ECE264, we are working on PA01.\n\n");

    // Uncomment to run two example (incomplete) testcases.
    //test_00_arraySum();
    //test_01_arrayCountNegative();
    test_00_arraySum();
    test_01_arrayCountNegative();
    test_arrayIsIncreasing();
    test_arrayIndexFind();
	//If you write any additional test functions, you can call them below
    test_arraySmallFind();
    return EXIT_SUCCESS;
}
