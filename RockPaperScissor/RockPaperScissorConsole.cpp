#include <iostream>

int main()
{
	std::cout << "  Rock Paper Scissor Game  " << std::endl;
	std::cout << "Idea source (link): https://www.geeksforgeeks.org" << std::endl;
	std::cout << "To start the game, write <start>, to exit, write <exit>" << std::endl;

	std::string ms;
	std::string words[3]{ "Rock","Paper","Scissor" };
	unsigned computerWordIndex = 0;
	unsigned playerWordIndex = 4;

	std::cout << "> ";
	std::cin >> ms;
	if (ms == "start") 
	{
		while (true)
		{
			playerWordIndex = 4;
			computerWordIndex = rand() % 3;
			
			//getting user word
			std::cout << "______ vs ";
			std::cin >> ms;
			if (ms == "exit")break;

			//input validation.
			for (size_t i = 0; i < 3; i++)
			{
				if (ms == words[i])playerWordIndex = i;
			}
			if (playerWordIndex == 4)
			{
				std::cout << "Unknown word, try again." << std::endl;
				continue;
			}

			std::cout << words[computerWordIndex] << " vs " << ms << " -> ";
			
			//chooshing the winner.
			if (playerWordIndex == 0 && computerWordIndex == 1)std::cout << words[computerWordIndex] << " wins" << std::endl;//rock vs paper
			else if (playerWordIndex == 0 && computerWordIndex == 2)std::cout << words[playerWordIndex] << " wins" << std::endl;//rock vs scissor
			else if (playerWordIndex == 1 && computerWordIndex == 0)std::cout << words[playerWordIndex] << " wins" << std::endl;//paper vs rock
			else if (playerWordIndex == 1 && computerWordIndex == 2)std::cout << words[computerWordIndex] << " wins" << std::endl;//paper vs scissor
			else if (playerWordIndex == 1 && computerWordIndex == 2)std::cout << words[computerWordIndex] << " wins" << std::endl;//paper vs scissor
			else if (playerWordIndex == 2 && computerWordIndex == 1)std::cout << words[playerWordIndex] << " wins" << std::endl;//scissor vs paper
			else if (playerWordIndex == 2 && computerWordIndex == 0)std::cout << words[computerWordIndex] << " wins" << std::endl;//scissor vs rock
			else std::cout << "draw" << std::endl;
		}
	}

	std::cout << "Game ended!" << std::endl;
	return 0;
}

