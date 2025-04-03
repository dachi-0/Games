#include <iostream>
#include <random>




int setDifficulty(int difficulty);
void response(int guess, int generatedNumber);

int main()
{
	int difficulty{}, guess{};
	while (difficulty != 1 && difficulty != 2 && difficulty != 3)
	{
		std::cout << "Choose the difficulty: Easy (1), Medium (2), Hard (3)\nEnter: ";
		std::cin >> difficulty;
	}
	int generatedNumber = setDifficulty(difficulty);
	while (guess != generatedNumber)
	{
		std::cin >> guess;
		response(guess, generatedNumber);
	}
	
}

int setDifficulty(int difficulty)
{
	std::random_device generator;
	if (difficulty == 1)
	{
		std::uniform_int_distribution<int> range(1, 10);
		int generatedNumber = range(generator);
		return range(generator);
	}
	else if (difficulty == 2)
	{
		std::uniform_int_distribution<int> range(10, 100);
		int generatedNumber = range(generator);
		return range(generator);
	}
	else
	{
		std::uniform_int_distribution<int> range(100, 1000);
		return range(generator);
	}

}

void response(int guess, int generatedNumber)
{
	if (guess > generatedNumber)
		std::cout << "Number too high\n";
	else if (guess < generatedNumber)
		std::cout << "Number too low\n";
	else
		std::cout << "You won!\n";
}
