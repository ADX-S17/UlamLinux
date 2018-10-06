#include "PixelDrawing.h"

PixelDrawing::PixelDrawing() : m_lPosX(0), m_lPosY(0), m_lPixelVal(1)
{
}

PixelDrawing::~PixelDrawing()
{
}

int PixelDrawing::goUp(long lMoveNumber, long *lValue, std::vector<long> *vPrimeNumbers, long* maxValue)
{
	//Move to the pixel above lMoveNumber time and set its value to lValue
	long lVal = *lValue;

	for (long l = 1; l <= lMoveNumber; l++)
	{
		this->setPixelPosition(m_lPosX, m_lPosY + 1);
		this->setPixelValue(lVal);
		this->drawPixel(vPrimeNumbers, maxValue);
		lVal++;
	}

	*lValue = lVal;
	return 0;
}

int PixelDrawing::goDown(long lMoveNumber, long *lValue, std::vector<long> *vPrimeNumbers, long* maxValue)
{
	//Move to the pixel below lCase time and set its value to lValue
	long lVal = *lValue;

	for (long l = 1; l <= lMoveNumber; l++)
	{
		this->setPixelPosition(m_lPosX, m_lPosY - 1);
		this->setPixelValue(lVal);
		this->drawPixel(vPrimeNumbers, maxValue);
		lVal++;
	}

	*lValue = lVal;
	return 0;
}

int PixelDrawing::goRight(long lMoveNumber, long *lValue, std::vector<long> *vPrimeNumbers, long* maxValue)
{
	//Move to the pixel to the right lCase time and set its value to lValue
	long lVal = *lValue;

	for (long l = 1; l <= lMoveNumber; l++)
	{
		this->setPixelPosition(m_lPosX + 1, m_lPosY);
		this->setPixelValue(lVal);
		this->drawPixel(vPrimeNumbers, maxValue);
		lVal++;
	}

	*lValue = lVal;
	return 0;
}

int PixelDrawing::goLeft(long lMoveNumber, long *lValue, std::vector<long> *vPrimeNumbers, long* maxValue)
{
	//Move to the pixel to the left lCase time and set its value to lValue
	long lVal = *lValue;

	for (long l = 1; l <= lMoveNumber; l++)
	{
		this->setPixelPosition(m_lPosX - 1, m_lPosY);
		this->setPixelValue(lVal);
		this->drawPixel(vPrimeNumbers, maxValue);
		lVal++;
	}

	*lValue = lVal;
	return 0;
}

void PixelDrawing::setPixelPosition(long X, long Y)
{
	m_lPosX = X;
	m_lPosY = Y;
}

void PixelDrawing::setPixelValue(long lVal)
{
	m_lPixelVal = lVal;
}

std::pair<long, long> PixelDrawing::getPixelPosition()
{
	std::pair<long,long> pairPos = std::make_pair(m_lPosX, m_lPosY);

	return pairPos;
}

void PixelDrawing::drawPixel(std::vector<long>* vPrimeNumbers, long* maxValue)
{
	//translation in order to draw negative pixels
	long lPosXTrans = m_lPosX + sqrt(*maxValue) / 2;
	long lPosYTrans = m_lPosY + sqrt(*maxValue) / 2;

	if (vPrimeNumbers->size() > 0 && this->getPixelValue() == vPrimeNumbers->at(0))
	{
		vPrimeNumbers->erase(vPrimeNumbers->begin()); //erase the vector
				
		m_mapRecordDrawing[std::make_pair(lPosXTrans, lPosYTrans)] = std::make_pair(this->getPixelValue(), true);

		//SetPixel(*deviceContent, lPosXTrans, lPosYTrans, COLOR);
		//SetPixel(*deviceContent, m_lPosX, m_lPosY, COLOR);
		//std::cout << "Value: " << this->getPixelValue() << " is painted in white !" << std::endl;
	}
	else
	{
		m_mapRecordDrawing[std::make_pair(lPosXTrans, lPosYTrans)] = std::make_pair(this->getPixelValue(), false);
		//COLORREF ROLOC = RGB(125, 0, 255);
		//SetPixel(*deviceContent, m_lPosX, m_lPosY, ROLOC);
	}
}