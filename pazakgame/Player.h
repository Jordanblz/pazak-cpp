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
		switch (play)
		{
		case 1:
			field += cards[0];
			break;
		case 2:
			field += cards[1];
			break;
		case 3:
			field += cards[2];
			break;
		case 4:
			field += cards[3];
			break;
		}
		std::cout << "Field now is: " << field << std::endl;
	}
};