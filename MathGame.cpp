#include <iostream>
#include <random>
#include <tuple>

std::tuple<int, int, int> setEquation(int difficulty);
int setAnswer(int numberOne, int numberTwo, int symbol);
void printEquation(int numberOne, int numberTwo, int symbol);

int main()
{
	int userInput, correctAnswer{}, difficulty{};

	/*Easy: Numbers between 1-100, only + and -.
	  Medium: Numbers between 1-100, with everything.
	  Hard: Numbers between 1-1000, with everything.
	  
	  1 = +, 2 = -, 3 = *, 4 = / */

	std::cout << "Select difficulty: Easy(1), Medium(2), Hard(3)" << '\n';
	while (difficulty != 1 && difficulty != 2 && difficulty != 3)
	{
		std::cout << "Enter: ";
		std::cin >> difficulty;
	}
	int numberOne, numberTwo, symbol;
	std::tie(numberOne, numberTwo, symbol) = setEquation(difficulty);
	correctAnswer = setAnswer(numberOne, numberTwo, symbol);
	printEquation(numberOne, numberTwo, symbol);
    printEquation;
    std::cout << '\n';
	while (userInput != correctAnswer)
	{
        std::cout << "Enter: ";
        std::cin >> userInput;
        if (userInput != correctAnswer)
            std::cout << "Incorrect!\n";
	}
    std::cout << "\nYou won!";
}

void printEquation(int numberOne, int numberTwo, int symbol)
{
	if (symbol == 1)
		std::cout << numberOne << " + " << numberTwo;
	else if (symbol == 2)
		std::cout << numberOne << " - " << numberTwo;
	else if (symbol == 3)
		std::cout << numberOne << " * " << numberTwo;
	else
		std::cout << numberOne << " / " << numberTwo;
}

int setAnswer(int numberOne, int numberTwo, int symbol)
{
	if (symbol == 1)
		return numberOne + numberTwo;
	else if (symbol == 2)
		return numberOne - numberTwo;
	else if (symbol == 3)
		return numberOne * numberTwo;
	else 
		return numberOne / numberTwo;
}

std::tuple<int, int, int> setEquation(int difficulty)
{
	std::random_device generator;

	if (difficulty == 1)
	{
		std::uniform_int_distribution<int> numberRange(1, 100);
		std::uniform_int_distribution<int> symbolRange(1, 2);
		int numberOne = numberRange(generator);
		int numberTwo = numberRange(generator);
		int symbol = symbolRange(generator);
		return std::make_tuple(numberOne, numberTwo, symbol);
	}

	else if (difficulty == 2)
	{
		std::uniform_int_distribution<int> numberRange(1, 100);
		std::uniform_int_distribution<int> symbolRange(1, 4);
		int numberOne = numberRange(generator);
		int numberTwo = numberRange(generator);
		int symbol = symbolRange(generator);
		if (symbol == 4)
		{
			while (floor(float(numberOne) / numberTwo) != (float(numberOne) / numberTwo))
			{
				numberOne = numberRange(generator);
				numberTwo = numberRange(generator);
			}
		}
		return std::make_tuple(numberOne, numberTwo, symbol);
	}

	else
	{
		std::uniform_int_distribution<int> numberRange(1, 1000);
		std::uniform_int_distribution<int> symbolRange(1, 4);
		int numberOne = numberRange(generator);
		int numberTwo = numberRange(generator);
		int symbol = symbolRange(generator);
		if (symbol == 4)
		{
			while (floor(float(numberOne) / numberTwo) != (float(numberOne) / numberTwo))
			{
				numberOne = numberRange(generator);
				numberTwo = numberRange(generator);
			}
		}
		return std::make_tuple(numberOne, numberTwo, symbol);
	}
}