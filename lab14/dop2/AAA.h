#pragma once
#include <string>

struct AAA
{
	int key;
	std::string word;
	AAA(int k, std::string z)
	{
		key = k;  word = z;
	}
	AAA() {}
};
#pragma once
