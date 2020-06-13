#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "TestClass.h"
std::random_device e;
std::uniform_int_distribution<> dist(1, 10);

bool operator == (const TestClass& a,const TestClass & b){
	return a._x == b._x;
}
void createTest() {

	void* p = operator new(2*sizeof(TestClass));
	TestClass* q = new(p) TestClass(7, 9);
	TestClass* t = new(q+ sizeof(TestClass)) TestClass(11, 13);
	q->~TestClass();
	t->~TestClass();
	operator delete(p);
}

/// @brief finds first occurence of val in range
/// @tparam iterator 
/// @tparam T 
/// @param begin beginning of the range
/// @param end end of the range
/// @param val value we are searching for
/// @return iterator to the found element or end if not found
template<typename iterator,typename T>
iterator find(iterator begin, iterator end, const T& val) {
	while (begin != end) {
		if (*begin == val)return begin;
		begin++;
	}
	return begin;
}
/// @brief 
/// @tparam iterator 
/// @tparam T 
/// @param begin 
/// @param end 
/// @param val 
/// @return 
template <typename iterator,typename T>
iterator remove(iterator begin,iterator end, T val) {
     begin = ::find(begin, end, val);
	if(begin!=end)
		for(iterator itr=begin+1;itr!=end;itr++){
			if (*itr != val) {
				*begin = std::move(*itr);
				begin++;
			}

		}
	return begin;
}
int main(){
	
	//v.reserve(10);
	//if (v.begin() == v.end())std::cout << "the same\n";
/*	{
		std::vector<TestClass> v;
		v.push_back(TestClass(1, 2));
	}
	std::cout << "emplace back\n";
	{std::vector<TestClass> v;
		v.emplace_back(3, 4);
	}*/
	//std::cout << "Whereas \n";
	//std::vector<TestClass> u(3);
	//if (u.begin() != u.end())std::cout << "not the same\n";
/*	int n = 10;
	std::vector<int> c;
	for (int i = 0; i < n; i++)
		c.push_back(dist(e));
	int val = dist(e);
	std::cout << val << " to be removed\n";
	std::vector<int> d = c;
	for(auto& x:c)
		std::cout<<x<<",";
	std::cout<<"\n----------------\n";
	auto a=  std:: remove(c.begin(),c.end(),val);
	auto b=::remove(d.begin(), d.end(), val);
	for(auto& x:c)
		std::cout<<x<<",";
	std::cout<<"\n";
	for (auto& x : d)
		std::cout << x << ",";
	std::cout << "\n";
	std::cout << "\n---------------\n";
	for (auto itr = c.begin(); itr != a; itr++)
		std::cout << *itr << ",";
	std::cout << "\n";
	for (auto itr = d.begin(); itr != b; itr++)
		std::cout << *itr << ",";
	std::cout << "size=" << d.size() << std::endl;
	d.erase(b, d.end());
	std::cout << "size=" << d.size() << std::endl;
	std::cout << d.begin() - d.end() << std::endl;
	std::cout << "memory \n";
	createTest();
	int* z = new int[10];
	Test u(1, 2);
	Test v(2, 3);
	operator == (u, v);
	u == v;*/
	//Test* w =:: new ((void*) z) Test ();
	
	/*	std::cout << "array\n";
		TestClass t[5];
		TestClass* p = (TestClass *) operator new (5 * sizeof(TestClass));
		new(p) TestClass(1, 2);
		new(p + 1) TestClass(3, 4);
		new (p + 2) TestClass(5, 6);
		new (p + 3) TestClass(7, 8);
		new (p + 4) TestClass(9, 10);

		int x = 12;*/
	//TODO: example about adjacent_find
	//std::adjacent_find;

	//TODO: example about transofrm
	//std::transform;
}
