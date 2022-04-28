#include <iostream>
#include <ranges>
#include <list>

uint64_t getValue(std::list<uint64_t> l, uint64_t var)
{
	uint64_t myNum{ 0 };
	for (uint64_t j : l)
	{
		if (myNum == var)
		{
			return j;
		}
		else
		{
			++myNum;
		}
	}
}

int main()
{
	uint64_t minimumNum{};
	std::cout << "Enter the mimimum value from the range (of numbers): ";
	std::cin >> minimumNum;
	uint64_t maximumNum{};
	std::cout << "Enter the maximum value from the range (of numbers): ";
	std::cin >> maximumNum;
	uint64_t howManyNums{};
	std::cout << "How many numbers do you want to generate: ";
	std::cin >> howManyNums;
	uint64_t minVal{ 1 };
	std::list<uint64_t> l{};
	for (uint64_t j : std::ranges::iota_view{ minimumNum,maximumNum+1 })
	{
		l.push_back(j);
	}
	std::list<uint64_t> lt{};
	for (uint64_t j : std::ranges::iota_view{ minVal,howManyNums+1 })
	{
		uint64_t randomVal{ rand() % l.size() };
		uint64_t val{ getValue(l,randomVal)};
		lt.push_back(val);
		l.remove(val);
	}
	for (uint64_t j : lt)
	{
		std::cout << j << ' ';
	}
	return 0;
}
