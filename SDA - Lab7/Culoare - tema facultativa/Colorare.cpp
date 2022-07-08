// Colorare.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2\imgproc.hpp>
#include <opencv2\highgui.hpp>
#include "Queue.h"
#include "Functii.h"

using namespace std;

Pozitie directii[4] = { { -1,0 },{ 0,-1 },{ 1,0 },{ 0,1 } };


cv::Mat ColoreazaDomeniu(cv::Mat in, Pozitie init, uint8_t color) {
	cv::Mat imgOut;
	in.copyTo(imgOut); //imgOut este o copie a lui in

	//dimensiunile imaginii
	int width = in.size().width;
	int height = in.size().height;

	// mi s-a parut mai firesc folorisrea cu uint8_t
	uint8_t culoareDomeniu = in.at<uint8_t>(init.y, init.x);
	std::cout << "Color: " << (unsigned int)culoareDomeniu << "( " << init.x << ", " << init.y << ")" << std::endl;

	Queue *pixels = nullptr;
	InitQueue(pixels);
	Put(pixels, init);
	imgOut.at<uint8_t>(init.y, init.x) = color;

	while (!isEmpty(pixels)) 
	{
		Pozitie p = Get(pixels);
		if (p.x + 1 < width  && imgOut.at<uint8_t>(p.y, p.x + 1) == culoareDomeniu)
		{
			Pozitie q;
			q.x = p.x + 1;
			q.y = p.y;
			Put(pixels, q);
			imgOut.at<uint8_t>(q.y, q.x) = color;
		}
		if (p.x - 1 >= 0 && imgOut.at<uint8_t>(p.y, p.x - 1) == culoareDomeniu)
		{
			Pozitie q;
			q.x = p.x - 1;
			q.y = p.y;
			Put(pixels, q);
			imgOut.at<uint8_t>(q.y, q.x) = color;
		}
		if (p.y + 1 < height && imgOut.at<uint8_t>(p.y + 1, p.x) == culoareDomeniu)
		{
			Pozitie q;
			q.x = p.x;
			q.y = p.y + 1;
			Put(pixels, q);
			imgOut.at<uint8_t>(q.y, q.x) = color;
		}
		if (p.y - 1 >= 0 && imgOut.at<uint8_t>(p.y - 1, p.x) == culoareDomeniu)
		{
			Pozitie q;
			q.x = p.x;
			q.y = p.y - 1;
			Put(pixels, q);
			imgOut.at<uint8_t>(q.y, q.x) = color;
		}	
	}

	std::cout << "DONE!" << std::endl;
	return imgOut;
}

int main()
{
	cv::Mat imgIn = cv::imread("img.png"); //obiectul Mat contine o matrice de pixeli
	cv::cvtColor(imgIn, imgIn, 7); //Am avut problema cu libraria
	cv::namedWindow("Input");      //asa ca am cautat in librarie definirea
	cv::namedWindow("Output");     // pentru COLOR_RGB2GRAY

	Pozitie posInit;
	posInit.x = imgIn.size().width / 2;
	posInit.y = imgIn.size().height / 2;

	//imgIn este o imagine grayscale (fiecare pixel este reprezentat de o valoare pe 8 biti, in [0,255])
	cv::Mat imgOut = ColoreazaDomeniu(imgIn, posInit, 255);

	//afisarea imaginilor
	cv::imshow("Input", imgIn);
	cv::imshow("Output", imgOut);
	cv::waitKey();

	return 0;
}