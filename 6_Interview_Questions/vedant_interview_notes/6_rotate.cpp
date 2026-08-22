// Author: Yash Deshpande
// Date  : 18-08-2026
// Interviwee: Vedant Paranjpe
// Interviewer: Matthijs and Ravi (Apple)
// Link  : https://gist.github.com/VedantParanjape/686091abe62ea6903c7064bb8789db82

#include <iostream>

typedef struct Pixel
{
  unsigned char r, g, b, a;
} Pixel;

typedef struct Image             // A 2D grid of pixels
{
  unsigned int width, height; // Dimensions of the grid
  Pixel* data;      // Pixels, laid out row-major order
} Image;


// Implement a function to rotate an image by 90 degrees counter-clockwise.
// For example, given the input on the left, produce the output on the right:
//  A B C        C F I 0
//  D E F   ->   B E H 1
//  G H I        A D G 2
// h is vertical
// w is horizontal
// row major

// w = 3
// h = 3
Image rotateImage(const Image in)
{
  // TO DO: implement this function
  int w = in.width;
  int h = in.height;

  Image *res = new Image;
  res->width = h;
  res->height = w;
  res->data = new Pixel[h * w];

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      Pixel temp = in.data[i * w + j];
      res->data[(w - j - 1) * h + i] = temp;
    }
  }

  return *res;
}