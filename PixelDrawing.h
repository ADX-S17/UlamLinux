#ifndef PIXEL_DRAWING_H
#define PIXEL_DRAWING_H

#include <string>
#include <iostream>
#include <vector>
#include <map>

//OpenGL library
//#include <GL/gl.h>
//#include <GL/glu.h>

#include "bitmap_image.h"

#include <cmath>

typedef std::map<std::pair<long, long>, std::pair<long, bool>> mapCoordValPrime;
typedef std::vector<std::pair<long, long>> vecCoor;

class PixelDrawing
{
public:
	PixelDrawing();
	~PixelDrawing();

	int goUp(long, long*, std::vector<long>*, long*);
	int goDown(long, long*, std::vector<long>*, long*);
	int goRight(long, long*, std::vector<long>*, long*);
	int goLeft(long, long*, std::vector<long>*, long*);

public:
	void setPixelPosition(long, long);
	void setPixelValue(long);
	void drawPixel(std::vector<long>*, long*);

public:
	std::pair<long, long> getPixelPosition();
	long getPixelValue() { return m_lPixelVal; };
	mapCoordValPrime getDrawing() { return m_mapRecordDrawing; };
	vecCoor getCoordinates() { return m_vCoordinates; };


private:
	long m_lPosX, m_lPosY, m_lPixelVal;
	//map containing coordinates (translation) of values and if they are prime numbers
	mapCoordValPrime m_mapRecordDrawing;
	vecCoor m_vCoordinates;

	//std::pair<long, long> m_pairCoordinates;
	//std::vector<std::pair<long, long>> m_vPosition;
	//std::map<std::pair<long, long>, long> m_mapDrawing;
};

#endif //PIXEL_DRAWING_H
