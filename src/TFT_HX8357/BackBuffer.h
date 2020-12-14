#ifndef BackBuffer_h
#define BackBuffer_h

#include <Arduino.h>

class BackBuffer
{
  private:
	uint8_t width;
	uint8_t height;
	uint8_t x;
	uint8_t y;
    uint16_t *buffer;

  public:
    BackBuffer(uint8_t x, uint8_t y, uint8_t w, uint8_t h);
    uint16_t* getBuffer();
	uint8_t getWidth();
	uint8_t getHeight();
	uint8_t getX();
	uint8_t getY();
	
	void drawPixel(uint16_t x, uint16_t y, uint16_t color);
    void fillScreen(uint16_t color);

    void drawChar(int16_t x, int16_t y, uint8_t c, uint16_t color, uint16_t bg, uint8_t size);
	int16_t drawChar(uint16_t uniCode, int16_t x, int16_t y, int16_t font);

	void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
	void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color);
	void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color);
	void fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
	
};

#endif
