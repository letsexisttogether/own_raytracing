#pragma once
#include <iostream>

template <int H, int W>
class Screen
{
public:
	char m_Screen[H][W];
public:
	void Print()
	{
		for (int i = H - 1; i >= 0; i--)
		{
			for (int j = W - 1; j >= 0; j--)
			{
				std::cout << m_Screen[i][j];
			}
			std::cout << std::endl;
		}
	};
};