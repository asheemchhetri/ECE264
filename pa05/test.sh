# @Author:              Asheem Chhetri <asheem>
# @Date:                Saturday, July 9th 2016, 5:35:15 pm
# @Email:               achhetri@purdue.edu
# @Project:
# @Last modified by:    asheem
# @Last modified time:  Saturday, July 9th 2016, 9:35:41 pm

#!/bin/bash
gcc -Wall -Wshadow -g answer05.c image-bmp.c main.c -o pa05

# echo $'Testing corrupt cases: \n'
# ./pa05 images/corrupt-testcases/01-incomplete-header.ee264 1
# echo
# ./pa05 images/corrupt-testcases/02-check-magic-number.ee264 1
# echo
# ./pa05 images/corrupt-testcases/03-width0.ee264 1
# echo
# ./pa05 images/corrupt-testcases/04-height0.ee264 1
# echo
# ./pa05 images/corrupt-testcases/05-big-width-height.ee264 1
# echo
# ./pa05 images/corrupt-testcases/06-bad-comment-len.ee264 1
# echo
# ./pa05 images/corrupt-testcases/07-comment-has-no-null-byte.ee264 1
# echo
# ./pa05 images/corrupt-testcases/08-height-wrong.ee264 2
# echo
# ./pa05 images/corrupt-testcases/09-incomplete-image.ee264 1
# echo
valgrind --tool=memcheck --leak-check=full --verbose --log-file=memcheck.log ./pa05 images/04-nelsonmandela.ee264 student-out-13_04-nelsonmandela.bmp

./diff-plus student-out-13_04-nelsonmandela.bmp 04-nelsonmandela.ee264
