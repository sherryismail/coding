/*
You are asked to produce code for a system that has a frame buffer. The frame
buffer stores a 2D image which is automatically displayed on an LCD screen.

The LCD and framebuffer have a resolution of 640x480. All buffers’ pixels are
stored sequentially in rows, with each subsequent row immediately following
the previous in the buffer. The first pixel in the frame buffer is displayed 
in the top-left most corner of the LCD.

The frame buffer uses 16-bits to encode each pixel, split into individual 
blue, green & red components of sizes 5, 6 & 5 bits respectively 
(red occupies the least significant bits).

A software renderer is required to blend a 32x32 pixel mouse pointer over the
frame buffer. The buffer containing the pointer uses 32-bits to encode each
pixel, split into individual 8-bit blue, green, red & alpha components,
respectively (alpha occupies the least significant byte).

A mouse pixel's transparency is defined by its alpha value, which may be
anywhere between 0 and 255 inclusive, where 0 is completely transparent 
and 255 is completely opaque.

The mathematical equation for alpha blending, for each component C, is:

     outputC = (foregroundC x alpha) + 
                         (backgroundC x (1.0 – alpha))

Where all values are in the range 0.0-1.0.

Note the co-ordinates will always be within 640x480, but the mouse pointer 
may overhang the end of the framebuffer.

Implement the 'overlay_mouse_pointer' function below. Any tests can be run
by adding them to the 'main' function.
*/

#include <stdio.h>
#include <stdint.h>

/*
Blends the image contained in the mouse pointer buffer over the provided frame
buffer, at the specified coordinates. The result of the blend should be written
back to the frame buffer.

Inputs: 
    frame_buffer: The provided frame buffer, over which the mouse pointer 
                  image should be blended
    mouse_pointer_buffer: Buffer containing mouse pointer image (with per 
                         pixel alpha information)
    x_coordinate: X coordinate of top left pixel of mouse pointer on frame 
                  buffer. Only values within the range 0 -> 639 are permitted.
    y_coordinate: Y coordinate of top left pixel of mouse pointer on frame 
                  buffer. Only values within the range 0 -> 479 are permitted.
  
Output:
    frame_buffer: The result of the blend is written back to frame_buffer

DO NO*/
#include <stdio.h>
#include <stdint.h>
#include <string.h>

#define FRAME_BLUE_MASK  0xF100
#define FRAME_GREEN_MASK  0x07E0
#define FRAME_RED_MASK    0x001F
#define FRAME_BLUE_OFFSET  11
#define FRAME_GREEN_OFFSET  6
#define FRAME_RED_OFFSET  0

#define MOUSE_BLUE_MASK  0xFF000000
#define MOUSE_GREEN_MASK 0x00FF0000
#define MOUSE_RED_MASK    0x0000FF00
#define MOUSE_ALPHA_MASK   0x000000FF

float get_alpha (uint32_t mouse_val)
{
   float alpha = mouse_val & MOUSE_ALPHA_MASK; //LSB 8 bit
   alpha = alpha/255;
   return alpha;
}
uint16_t foreground_with_alpha(uint32_t mouse, float alpha)
{
  uint16_t small_mouse = 0;
  //drop to LSBs of each R,G and B component
  uint16_t blue = (mouse & MOUSE_BLUE_MASK) >> 24;
  uint16_t green = (mouse & MOUSE_GREEN_MASK) >> 16;
  uint16_t red = (mouse & MOUSE_RED_MASK) >> 8;
  //apply alpha
  blue = (uint16_t)( blue * alpha);
  green = (uint16_t)( green * alpha);
  red = (uint16_t)( red * alpha);
  //adjust to smaller values, BGR = 5|6|5
  blue = blue >> 3;
  green >>= 2;
  red >>= 3;
  //reassemble it to 16-bit number
  //bit-wise OR to combine all bits to be compatible with frame
  small_mouse = (blue << FRAME_BLUE_OFFSET) | (green << FRAME_GREEN_OFFSET) | (red);
  return small_mouse;
}

uint16_t background_with_alpha(uint32_t frame, float alpha) {
  float beta = 1- alpha;
  uint16_t mod_frame = 0;
  //drop to LSBs of each R,G and B
  uint16_t blue = (frame & FRAME_BLUE_MASK) >> FRAME_BLUE_OFFSET;
  uint16_t green = (frame & FRAME_GREEN_MASK) >> FRAME_GREEN_OFFSET;
  uint16_t red = (frame & FRAME_RED_MASK) >> FRAME_RED_OFFSET;
 //apply 1 - alpha
  blue = (uint16_t)( blue * beta);
  green = (uint16_t)( green * beta);
  red = (uint16_t)( red * beta);
  //reassemble it to 16-bit number
  //bit-wise OR to combine all bits
  mod_frame = (blue << FRAME_BLUE_OFFSET) | (green << FRAME_GREEN_OFFSET) | (red);
  return mod_frame;
}
void overlay_mouse_pointer(uint16_t* frame_buffer,
                           uint32_t* mouse_pointer_buffer,
                           unsigned int x_coordinate, 
                           unsigned int y_coordinate)
{
  /* Put your code here */
  uint16_t i=0,j=0, x,y;
  float alpha = 0;

  uint16_t foregroundC, backgroundC;
  uint16_t outputC;
  uint16_t * back;//pointer to frame's current pixel
  //unsigned int = 32-bit, ptr advances 16-bit
  x = (uint16_t) x_coordinate;
  y = (uint16_t) y_coordinate;
  //check mouse overhang condition
  
  back = (frame_buffer + x + (y * 640));
  for (i=0; i < 2; i++)
  {
    for (j=0; j < 2; j++)
    {
      alpha = get_alpha (*mouse_pointer_buffer);
      foregroundC = foreground_with_alpha(*mouse_pointer_buffer, alpha); 
     
      backgroundC = background_with_alpha(*back, alpha);
      outputC = foregroundC + backgroundC;//use 32-bit prevent overflow ?
      *back = outputC;
      //printf("[%d][%d] alpha=%f, fore=0x%x,back=0x%x\n",i,j,alpha, foregroundC, backgroundC);
      back++;
      mouse_pointer_buffer++;//move to the next mouse pixel on x-axis
    }
    //printf("before p_back=%p,",back);
    //--back; //undo the extra increment by last iteration of inner-loop
    back = back + (640 - 32);//next line of pixels minus 32 positions
    //printf("after p_back=%p,\n",back);
  }
    
}


int main() {
  printf("Alpha Blending\n");
  
  /* Put any tests here. */
  uint32_t mouse[32*32];
  mouse[0] = 0x22222280;
  mouse[1] = 0x11111180;
  mouse[32] = 0x44444480;
  mouse[33] = 0x44444480;
  uint16_t frame [640*480];
  frame[0] = 0;
  frame[1] = 0;
  frame[32] = 0;
  frame[33] = 0;
  overlay_mouse_pointer(&frame[0], &mouse[0], 0, 0);
  return 0;
}