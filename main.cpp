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

template<typename iterator, typename P>
iterator find_if(iterator begin, iterator end, P pred) {
	while (begin != end) {
		if (pred(*begin))return begin;
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
template<typename iterator, typename P>
iterator remove_if(iterator begin, iterator end, P pred) {
	begin = ::find_if(begin, end, pred);
	if (begin != end)
		for (iterator itr = begin + 1; itr != end; itr++) {
			if (!pred(*itr)) {
				*begin = std::move(*itr);
				begin++;
			}

		}
	return begin;
}
int main(){
	
	
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
	{
		const int n = 10;
		std::random_device e;
		std::uniform_int_distribution<> dist(1, 10);
		std::vector<int> v(10);
		std::generate(v.begin(), v.end(), [&]() {return dist(e); });
		
		for (auto& x : v)
			std::cout << x << ",";
		std::cout << std::endl;
		auto itr = ::remove_if(v.begin(), v.end(), [](int n) { return (n % 2 == 0); });
		std::cout << "print from first event to end\n";
		v.erase(itr, v.end());
		for (auto i = v.begin(); i != v.end(); ++i)
			std::cout << *i << ",";

		std::cout << std::endl;

	}
}
