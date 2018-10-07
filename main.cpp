
//////////////////////////////////////////////////////////////////////////////////////////////////////
//																									//
//								GENERATION D'UNE SPIRALE D'ULAM										//
//									V0.1 - 04/10/2018 - ADE											//
//																									//
//////////////////////////////////////////////////////////////////////////////////////////////////////

#include "Ulam.h"

#define _WIN32_WINNT 0x0500

//TODO : create log
//using source code from https://archive.codeplex.com/?p=bitmap

#ifdef _WIN32
	#define _ERR true
#else
	#define _ERR false	
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

		//using bitmap_image library
		long sizeImage = sqrt(lValue);
		bitmap_image spiraleUlam(sizeImage,sizeImage);

		spiraleUlam.clear(); //TOGET
		vecCoor vCoordinates = oPixelDrawing->getCoordinates();

		for (vecCoor::iterator it = vCoordinates.begin(); it != vCoordinates.end(); ++it)
		{
			std::pair<long,long> tempPair = *it;
			long lX = tempPair.first;
			long lY = tempPair.second;
			spiraleUlam.set_pixel(lX, lY, jet_colormap[137]);
		}

		spiraleUlam.save_image("spiraleUlam.bmp");
	

		delete oPixelDrawing;

		std::cout << "Try again ? (Y/N) : ";
		std::cin >> lAnswer;
	} while (lAnswer == 'Y');

	return 0;
}