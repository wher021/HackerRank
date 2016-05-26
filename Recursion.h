#pragma once
#include<iostream>

class myRecursion
{
public:
	static int recursion(int x)
	{
		if (x == 1)
		{
			std::cout << x << std::endl;
			return 1;
		}
		else 
		{
			std::cout << x << std::endl; 
			return x*recursion(x - 1);
		}
	}
};