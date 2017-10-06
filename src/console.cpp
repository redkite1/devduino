/** MIT License
*
* Copyright(c) 2017 DevDuino
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files(the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions :
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*/

#include "console.h"

namespace devduino {
	//------------------------------------------------------------------------//
	//---------------------------- Public methods ----------------------------//
	//------------------------------------------------------------------------//
	Console::Console(const Oled& oled, uint8_t nbAreasX, uint8_t nbAreasY, bool autoFlush) :
		oled(oled), 
		nbAreasX(nbAreasX),
		nbAreasY(nbAreasY),
		autoFlush(autoFlush)
	{
		oled.setTextPosition(0, 64);
	}

	Console& Console::write(const uint8_t* value) {
		oled.write(value);
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::write(const String& value) {
		oled.write(value);
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::write(const OutputStream& value) {
		for (int i = 0; i < value.nbCharacters(); i++) {
			oled.write(value.nextCharacter());
		}
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::writeln(const uint8_t* value) {
		oled.write(value);
		oled.write("\n");
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::writeln(const String& value) {
		oled.write(value);
		oled.write("\n");
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::writeln(const OutputStream& value) {
		for (int i = 0; i < value.nbCharacters(); i++) {
			oled.write(value.nextCharacter());
		}
		oled.write("\n");
		if (autoFlush) {
			flush();
		}
		return *this;
	}

	Console& Console::writeToArea(uint8_t areaId, const String& value) {
		uint8_t y = areaId / nbAreasX;
		uint8_t x = areaId - (y * nbAreasX);

		writeToArea(x, (nbAreasY - y) - 1, value);

		return *this;
	}

	Console& Console::writeToArea(uint8_t areaXId, uint8_t areaYId, const String& value) {
		if (areaXId < nbAreasX && areaYId < nbAreasY) {
			uint8_t areaWidth = oled.getWidth() / nbAreasX;
			uint8_t areaHeight = oled.getHeight() / nbAreasY;
			uint8_t areaX = areaXId * areaWidth;
			uint8_t areaY = areaYId * areaHeight;
			oled.clearArea(areaX, areaY, areaWidth, areaHeight);
			oled.setTextPosition(areaX, areaY);
			oled.write(value);
			if (autoFlush) {
				flush();
			}
		}
		return *this;
	}

	Console& Console::setAreas(uint8_t nbAreasX, uint8_t nbAreasY) {
		this->nbAreasX = nbAreasX;
		this->nbAreasY = nbAreasY;
	}

	Console& Console::flush() {
		oled.display();
		return *this;
	}

	Console& Console::enableAutoFlush(bool autoFlush) {
		this->autoFlush = autoFlush;
		return *this;
	}

	//------------------------------------------------------------------------//
	//--------------------------- Private methods ----------------------------//
	//------------------------------------------------------------------------//

} // namespace devduino

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_OLED) && !defined(NO_GLOBAL_CONSOLE)
	devduino::Console console(oled);
#endif