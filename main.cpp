
//////////////////////////////////////////////////////////////////////////////////////////////////////
//																									//
//								GENERATION D'UNE SPIRALE D'ULAM										//
//									V0.1 - 04/10/2018 - ADE											//
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Ulam.h"

#define _WIN32_WINNT 0x0500

//TODO : create log

#ifdef _WIN32
	#define _ERR false
#else
	#define _ERR true	
	//TODO : create a linux version using OpenGL
#endif

int main(int argc, char* argv[])
{
	if (_ERR)
		return -1;

	long lValue, lPos;
	char lAnswer = 'N';

	std::cout << "*****************************************************\n";
	std::cout << "**                      WELCOME                    **\n";
	std::cout << "*****************************************************\n\n";
	std::cout << "WARNING : Maximum value is 500000\n\n";

	do
	{
		//TODO : open two consoles : one for the text, another one for the drawing
		std::cout << "What is the upper limit of this model ? Your answer : ";
		std::cin >> lValue;

		while (lValue > 500000)
		{
			std::cout << "[ERROR] Maximum value is 500000. New answer : ";
			std::cin >> lValue;
		}

		Ulam oUlam;
		PixelDrawing* oPixelDrawing = new PixelDrawing;

		oUlam.computePrime(lValue);

		/*
		std::cout << "\nWhich prime number would you like ? Your answer : ";
		std::cin >> lPos;
		std::cout << oUlam.getPrimeAtPos(oUlam.getVectorPrimeNumbers(), lPos) << std::endl;
		*/

		//TODO : save the drawing inside a file
		oUlam.setScreenPath(lValue, oPixelDrawing, &lValue);


		delete oPixelDrawing;

		std::cout << "Try again ? (Y/N) : ";
		std::cin >> lAnswer;
	} while (lAnswer == 'Y');

	return 0;
}