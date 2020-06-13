#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "helpers.h"

int main(){
	std::cout<<"exercise 1: implement find(). 20 pts\n\
as an EXAMPLE, the code below should output\n\
4,5,5,4,3,2,1,0,\n\
-------------------\n";
	{
		std::vector<int> v{ 1,2,3,4,5,5,4,3,2,1,0 };
		auto itr = ::find(v.begin(), v.end(), 4);
		std::cout << "output\n";
		for (auto i = itr; i != v.end(); ++i)
			std::cout << *i << ",";
		std::cout << std::endl;
		std::cout<<"----------------------\n";
		std::cout<<"----------------------\n";

	}
	std::cout << "exercise 2: implement find_if(). 20 pts\n\
as an EXAMPLE, the code below should output\n\
5,5,4,3,2,1,0,\n\
-------------------\n";
	{
		std::vector<int> v{ 1,2,3,4,5,5,4,3,2,1,0 };
		auto itr = ::find_if(v.begin(), v.end(), [](int n) {return ((n % 2 == 1) && n > 3); });
		std::cout << "output\n";
		for (auto i = itr; i != v.end(); ++i)
			std::cout << *i << ",";
		std::cout << std::endl;
		std::cout<<"----------------------\n";
		std::cout<<"----------------------\n";
	}
	std::cout << "exercise 3: implement remove(). 20 pts\n\
as an EXAMPLE, the code below should output\n\
1,2,4,5,5,4,2,1,0,1,0,\n\
1,2,4,5,5,4,2,1,0,\n\
-------------------\n";
	{
		std::vector<int> v{ 1,2,3,4,5,5,4,3,2,1,0 };
		auto itr = ::remove(v.begin(), v.end(), 3);
		std::cout << "output\n";
		for (auto& x:v)
			std::cout << x << ",";
		std::cout << std::endl;
		v.erase(itr, v.end());
		for (auto& x : v)
			std::cout << x << ",";
		std::cout << std::endl;
		std::cout << "----------------------\n";
		std::cout << "----------------------\n";

	}
	std::cout << "exercise 4: implement remove_if(). 20 pts\n\
as an EXAMPLE, the code below should output\n\
1,3,5,5,3,1,4,3,2,1,0,\n\
1,3,5,5,3,1,\n\
-------------------\n";
	{
		std::vector<int> v{ 1,2,3,4,5,5,4,3,2,1,0 };
		auto itr = ::remove_if(v.begin(), v.end(), [](int n) { return (n % 2 == 0); });
		std::cout << "output\n";
		for (auto& x : v)
			std::cout << x << ",";
		std::cout << std::endl;
		v.erase(itr, v.end());
		for (auto& x:v)
			std::cout << x << ",";

		std::cout << std::endl;
		std::cout << "----------------------\n";
		std::cout << "----------------------\n";
	}
}
