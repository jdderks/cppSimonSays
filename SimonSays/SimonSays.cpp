// SimonSays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "SimonSays.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

std::vector<int> randomInts;
std::vector<int> inputInts;

void clear();
void getUserInput();
void addRandomInt();
void initGameLoop();
void checkUserInputForErrors();

void clear() 
{
	system("cls");
}

void checkUserInputForErrors()
{
	clear();

	for (size_t i = 0; i < randomInts.size(); i++)
	{
		if (randomInts[i] != inputInts[i])
		{
			clear();
			std::cout << "GAME OVER" << std::endl;
			std::cout << "Press ENTER to continue...\n" << std::cin.get();
			std::exit(0);
		}
	}

	addRandomInt();
}

void getUserInput()
{
	clear();
	inputInts.clear();

	std::cout << "Repeat: " << std::endl;

	for (size_t i = 0; i < randomInts.size(); i++)
	{
		std::cout << "Int " << i + 1 << ":";
		int in;
		std::cin >> in;
		inputInts.push_back(in);
	}

	std::cout << "Press ENTER to continue...\n" << std::cin.get();
	checkUserInputForErrors();
}

void initGameLoop()
{
	clear();

	for (size_t i = 0; i < 3; i++)
	{
		int randInt = std::rand() % 10;
		randomInts.push_back(randInt);
	}

	std::cout << "Simon: " << std::endl;
	for (size_t i = 0; i < randomInts.size(); i++)
	{
		std::cout << randomInts[i] << ", " << std::endl;
	}

	std::cout << "Press to continue...\n" << std::cin.get();
	getUserInput();
}


void addRandomInt()
{
	clear();

	int randInt = std::rand() % 10;
	randomInts.push_back(randInt);

	std::cout << "Simon: " << std::endl;
	for (size_t i = 0; i < randomInts.size(); i++)
	{
		std::cout << randomInts[i] << ", " << std::endl;
	}

	std::cout << "Press to continue...\n" << std::cin.get();
	getUserInput();
}


int main()
{
	srand(time(NULL));
	initGameLoop();

	return 0;
}

