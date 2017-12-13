#ifndef DEVDUINO_THERMOMETERSPRITE
#define DEVDUINO_THERMOMETERSPRITE

#include "DevduinoSprite.h"

static const uint8_t thermometerSpriteBuffer[8][48] PROGMEM = {
	{ 0x07, 0x1C, 0x30, 0x60, 0x40, 0xC0, 0x83, 0x8D, 0x9F, 0x81, 0x80, 0x8F, 0x90, 0x90, 0x8F, 0x80, 0x80, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x82, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xC0, 0x40, 0x60, 0x30, 0x1C, 0x07 }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x84, 0x03, 0x00, 0x07, 0x85, 0x85, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x21, 0xA1, 0xA1, 0x60, 0x00, 0x20, 0x21, 0x21, 0xC0, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x28, 0x28, 0xD8, 0x00, 0xF0, 0x08, 0x08, 0xF0, 0x00, 0x00, 0x20, 0x20, 0x20, 0x20, 0x20, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x42, 0x46, 0x4A, 0x32, 0x00, 0x72, 0x52, 0x52, 0x4C, 0x00, 0x00, 0x08, 0x08, 0x08, 0x08, 0x08, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x11, 0x12, 0x0C, 0x00, 0x0F, 0x10, 0x10, 0x0F, 0x00, 0x00, 0x02, 0x02, 0x02, 0x02, 0x02, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x87, 0x80, 0x80, 0x00, 0x07, 0x85, 0x85, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0xAA, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF }, 
	{ 0xE0, 0x38, 0x0C, 0x06, 0x02, 0x03, 0x21, 0xE1, 0x21, 0x01, 0x01, 0x21, 0x21, 0x21, 0xC1, 0x01, 0x01, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x03, 0x02, 0x06, 0x0C, 0x38, 0xE0 }
};

DevduinoSprite thermometerSprite((uint8_t*) thermometerSpriteBuffer, 48, 8);

#endif //DEVDUINO_THERMOMETERSPRITE