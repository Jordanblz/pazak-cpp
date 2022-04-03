#include <iostream>
#include <string>
#include "RandomGen.h"
#include "Player.h"

int main()
{

	Player player_one;
	Player player_two;
	std::cout << "Enter Player name for player one: ";
	std::cin >> player_one.name;
	std::cout << "Enter Player name for player two: ";
	std::cin >> player_two.name;
	std::cout << "Welcome " << player_one.name << " and " << player_two.name 
		<< " to the game! Good luck and have fun!" << std::endl;

	system("pause");
	system("cls");
	player_one.set_cards(player_one.cards);
	player_two.set_cards(player_two.cards);

	while (true)
	{
		player_one.play_round();
		player_two.play_round();
		if (player_one.field == 20)
		{
			std::cout << player_one.name << "WINS" << std::endl;
			break;
		}
		if (player_two.field == 20)
		{
			std::cout << player_two.name << "WINS" << std::endl;
			break;
		}

	}
}