#include "Ulam.h"
#include <chrono>

Ulam::Ulam()
{
	//initialize vPrimeNumbers ?
}

Ulam::~Ulam()
{
}

void Ulam::computePrime(long maxValue)
{
	long lNumber = 3;
	m_vPrimeNumbers.push_back(2); //first prime number

	//SECOND METHOD
	//std::vector<long> vPrimeNumbers = m_vPrimeNumbers;

	auto start = std::chrono::steady_clock::now();

	for (lNumber; lNumber <= maxValue; lNumber++)
	{
		bool bIsPrime = false;

		//---------------------------------------------------------------------
		//FIRST METHOD : ~92sec to find result between 2 and 300 000
		//  ~41sec to find result between 2 and 200 000
		//  ~10sec to find result between 2 and 100 000
		//---------------------------------------------------------------------
		
		long lCompare = lNumber - 1;
		while ((lCompare > 1) && (lNumber % lCompare != 0))
		{
			lCompare--;
		}

		if (lCompare == 1)
			bIsPrime = true;

		if (bIsPrime == true)
		{
			m_vPrimeNumbers.push_back(lNumber);
		}
		

		//---------------------------------------------------------------------
		//SECOND METHOD  (SLOWEST : ~120sec to find result between 2 and 100 000)
		//---------------------------------------------------------------------
		/*
		while ((vPrimeNumbers.size() > 0) && (lNumber % vPrimeNumbers.at(0) != 0))
		{
			vPrimeNumbers.erase(vPrimeNumbers.begin());
		}

		if (vPrimeNumbers.size() == 0)
			bIsPrime = true;

		if (bIsPrime == true)
		{
			m_vPrimeNumbers.push_back(lNumber);
		}

		vPrimeNumbers = m_vPrimeNumbers;
		*/

		//---------------------------------------------------------------------
		//THIRD METHOD : ~132sec to find result between 2 and 300 000
		//  ~55sec to find result between 2 and 200 000
		//  ~16sec to find result between 2 and 100 000
		//---------------------------------------------------------------------
		/*
		for (long lCompare = 0; lCompare < m_vPrimeNumbers.size(); lCompare++)
		{
			if (lNumber % m_vPrimeNumbers[lCompare] == 0)
			{
				bIsPrime = false;
				break;
			}
			else
				bIsPrime = true;
		}

		if (bIsPrime == true)
		{
			m_vPrimeNumbers.push_back(lNumber);
		}
		*/
	}

	auto end = std::chrono::steady_clock::now();

	std::chrono::duration<double> elapsedTime = end - start;

	//std::cout << "Elapsed time is equal to " << elapsedTime.count() << " seconds" << std::endl;
}

long Ulam::getPrimeAtPos(std::vector<long> vPrimeNumbers, long lPos)
{
	//TODO : if it doesn't exist create exception
	return vPrimeNumbers.at(lPos);
}

int Ulam::goToNextPixel(long lPixelPos)
{
	return 0;
}

int Ulam::setScreenPath(long lLast, PixelDrawing* oPixelDrawing, long* maxValue)
{
	bool bRepere = true;
	long lInitValue = 2; //because we start at position (0,0) with value equal to 1

	for (long lNombreCase = 1; lNombreCase <= lLast; lNombreCase++)
	{

		if (bRepere)
		{
			oPixelDrawing->goRight(lNombreCase, &lInitValue, &m_vPrimeNumbers, maxValue);
			if (lInitValue >= lLast) break;
			oPixelDrawing->goUp(lNombreCase, &lInitValue, &m_vPrimeNumbers, maxValue);
			if (lInitValue >= lLast) break;
			bRepere = false;
		}
		else
		{
			oPixelDrawing->goLeft(lNombreCase, &lInitValue, &m_vPrimeNumbers, maxValue);
			if (lInitValue >= lLast) break;
			oPixelDrawing->goDown(lNombreCase, &lInitValue, &m_vPrimeNumbers, maxValue);
			if (lInitValue >= lLast) break;
			bRepere = true;
		}		
	}

	

	return 0;
}