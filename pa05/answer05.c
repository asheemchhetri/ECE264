/**
* @Author:              Asheem Chhetri <asheem>
* @Date:                Saturday, July 8th 2016, 2:47:48 am
* @Email:               achhetri@purdue.edu
* @Project:             answer05.c
* @Last modified by:    asheem
* @Last modified time:  Saturday, July 9th 2016, 9:40:32 pm
*/

#include "answer05.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

static int checkValid_ee264_header(ImageHeader * header);
/*
  Note:
  Help was taken from image-bmp.c file that was provided with this assignment as,
  it helped in understanding the cases where a file will be correupted and what to do
  in such cases. checkvalid_ee264_header helper function is direct implementation
  from <image-bmp.c>.
  The integrity of file <image-bmp.c> has been maintained throughout, and was modified accordingly to meet our needs
  for files with <.ee264> extension.
*/
Image * Image_load(const char * filename)
{
  FILE *fp = NULL;
  ImageHeader header;
  Image * tmp_im = NULL;
  Image * im = NULL;
  size_t read;
  size_t n_bytes = 0;
  int err = FALSE;

  // Open filename
  if(!err)
  {
    fp = fopen(filename, "rb");
    if(!fp) err = TRUE;
  }

  // Read the header
  if(!err)
  {
    read = fread(&header, sizeof(ImageHeader), 1, fp);
    if(read != 1) err = TRUE;
  }

  // We're only interested in a subset of valid ee264 files
  if(!err)
  {
    if(!checkValid_ee264_header(&header)) err = TRUE;
  }

  // Allocate Image struct
  if(!err)
  {
    tmp_im = malloc(sizeof(Image));
    if(tmp_im == NULL)  err = TRUE;
  }

  // Initializing the Image struct
  if(!err)
  {
    tmp_im->width = header.width;
    tmp_im->height = header.height;

    //Reading comment
    n_bytes = header.comment_len;
    tmp_im->comment = malloc(n_bytes);
    if(tmp_im->comment == NULL) err = TRUE;
    else
    {
      read = fread(tmp_im->comment,sizeof(char),n_bytes,fp);
      if (n_bytes != read)  err = TRUE;
      else if (tmp_im->comment[n_bytes - 1] != '\0')  err = TRUE;
    }

    // Handling image data
    n_bytes = header.width * header.height;
    tmp_im->data = malloc(n_bytes);
    if(tmp_im->data == NULL)  err = TRUE;
  }

  // Read pixel data
  if(!err)
  {
    n_bytes = header.width* header.height;
    read = fread(tmp_im->data,sizeof(uint8_t),n_bytes,fp);
    if(n_bytes != read) err = TRUE;
  }

  // We should be at the end of the file now
  if(!err)
  {
    uint8_t byte;
    read = fread(&byte, sizeof(uint8_t), 1, fp);
    if(read != 0) err = TRUE;
  }

  //successfully read file
  if(!err)
  {
    im = tmp_im;
    tmp_im = NULL;
  }

  // House Cleaning
  if(tmp_im != NULL)  Image_free(tmp_im);
  if(fp)  fclose(fp);

  return im;
}

/**
* Helper Function:
* We are only interested in a subset of ee264 file functionality.
*/
int checkValid_ee264_header(ImageHeader * header)
{
  // Make sure the magic number is correct
  if (header->magic_number != ECE264_IMAGE_MAGIC_NUMBER)  return FALSE;
  //Make sure neither the width nor height is zero.
  if (header->width == 0) return FALSE;
  if (header->height == 0)  return FALSE;

  //Make sure the length of the comment is not zero
  if (header->comment_len == 0) return FALSE;

  return TRUE;
}

void linearNormalization(int width, int height, uint8_t * intensity)
{
  int i;
  uint8_t max;
  uint8_t min;

  max = intensity[0];
  min = max;

  for(i=1; i < height * width; i++)
  {
    if(intensity[i] > max)  max = intensity[i];
    if(intensity[i] < min)  min = intensity[i];
  }

  for(i = 0; i < height * width; i++)
  {
    intensity[i] = (intensity[i] - min) * 255 / (max - min);
  }
}

int Image_save(const char *filename, Image * image)
{
  FILE * fptr = fopen(filename, "w");
  ImageHeader head;

  head.magic_number = ECE264_IMAGE_MAGIC_NUMBER;
  head.width = image->width;
  head.height = image->height;
  head.comment_len = strlen(image->comment) + 1;

  fwrite(&head, sizeof(ImageHeader), 1, fptr);
  fprintf(fptr,"%s%c", image->comment, '\0');

  int i;
  for(i = 0; i < image->width * image->height; i++)
  {
    fprintf(fptr, "%c", image->data[i]);
  }

  fclose(fptr);
  return 1;
}

void Image_free(Image * image)
{
  if ( image != NULL )
  {
    free ( image->comment );
    free ( image->data );
    free ( image );
  }
}
