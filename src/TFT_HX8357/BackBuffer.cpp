#include "BackBuffer.h"

BackBuffer::BackBuffer(uint8_t x, uint8_t y, uint8_t w, uint8_t h)
{
	this->x = x;
	this->y = y;
	width = w;
	height = h;
	buffer = new uint16_t[w * h];
	memset(buffer, 0, w * h * sizeof(uint16_t));
}

uint16_t* BackBuffer::getBuffer()
{
	return buffer;
}

uint8_t BackBuffer::getWidth()
{
	return width;
}

uint8_t BackBuffer::getHeight()
{
	return height;
}

uint8_t BackBuffer::getX()
{
	return x;
}

uint8_t BackBuffer::getY()
{
	return y;
}

void BackBuffer::drawPixel(uint16_t x, uint16_t y, uint16_t color)
{
	buffer[y * width + x] = color;
}

void BackBuffer::drawChar(int16_t x, int16_t y, uint8_t c, uint16_t color, uint16_t bg, uint8_t font)
{
	
}
	
void BackBuffer::fillScreen(uint16_t color)
{
	int index = 0;
	int size = width * height;
	
	while(index < size)
	{
		buffer[index++] = color;
	}
}

void BackBuffer::drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color)
{
  int dx = x1 - x0;
  int dy = y1 - y0;
  int D = 2*dy - dx;
  int y = y0;

  for (int x = x0; x <= x1; x++)
  {
    buffer[y * width + x] = color;
	
    if (D > 0)
	{
       y = y + 1;
       D = D - 2*dx;
    }
	
    D = D + 2*dy;
  }
}

void BackBuffer::drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color)
{
	while(h)
	{
		buffer[(y + h-1) * width + x] = color;
		h--;
	}
}

void BackBuffer::drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color)
{
	while(w)
	{
		buffer[y * width + x + w-1] = color;
		w--;
	}
}

void BackBuffer::fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
	while(h)
	{
		for(int i = 0; i < w; i++)
		{
			buffer[(y + h) * width + x + i] = color;
		}
		h--;
	}
}
