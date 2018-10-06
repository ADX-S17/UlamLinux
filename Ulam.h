#ifndef ULAM_H
#define ULAM_H

#include <string>
#include <iostream>
#include <vector>
//#include <cmath>

#include "PixelDrawing.h"

class Ulam
{
public:
	Ulam();
	~Ulam();
	void computePrime(long);
	long getPrimeAtPos(std::vector<long>, long);
	int goToNextPixel(long);

public:
	int setScreenPath(long, PixelDrawing*, long*);

public:
	std::vector<long> getVectorPrimeNumbers() { return m_vPrimeNumbers; };

private:
	std::vector<long> m_vPrimeNumbers;
};

#endif //ULAM_H

