#pragma once
#include <iostream>
#include "RandomGen.h"
class Player
{
public:
	std::string name;
	int field;
	bool standing = false;
	int cards[4] = {};
	Player()
	{
		name = "";
		field = 0;
	}
	void set_cards(int (&arr)[4])
	{
		for (int i = 0; i < 4; i++)
			arr[i] += RNG(1, 4);
	}
	void print_cards()
	{
		int card_count = 1;
		for (int i = 0; i < 4; i++)
		{
			std::cout << card_count<<")" << cards[i] << std::endl;
			card_count++;
		}
	}
	void play_round()
	{
		field += RNG(1, 9);
		int play;
		std::cout << name << " field is : " << field << std::endl;
		std::cout << "Choose which card to play: " << std::endl;
		print_cards();
		std::cin >> play;
		field += cards[play];
		std::cout << "Field now is: " << field << std::endl;
	}
};