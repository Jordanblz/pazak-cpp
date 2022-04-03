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
		if (standing == false)
		{
			int rand_points = RNG(1, 9);
			field += rand_points;
			std::cout << "Added " << rand_points << " to " << name << " field." << std::endl;
			std::cout << "The field now is " << field << std::endl;
		}

		if(standing == false)
		{
		char move;
		std::cout << "Choose to play(p), stand(s) or end(e):" << std::endl;
		std::cin >> move;
		tolower(move);
		
			if (move == 'p')
			{
				
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
			else if (move == 's')
			{
				standing = true;
				std::cout << name << " is now STANDING!" << std::endl;
			}
		}
		else
		{
			std::cout << name << " is STANDING!" << std::endl;
		}
	}
};