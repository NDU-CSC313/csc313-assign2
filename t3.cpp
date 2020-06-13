#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <random>
#include "helpers.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"


TEST_CASE("Test0", "0") {
 std::vector<int> v {1,9,3,4,2,2,2,5,2};
 auto itr=::remove_if(v.begin(),v.end(),
			 [](int n){return ((n%2==0)&& n<4);}
			 
			 );
 v.erase(itr,v.end());
 REQUIRE(v.size()==5);
}

TEST_CASE("Test1", "1") {
 std::vector<int> v {61,9,63,74,5,43,5,23,27,2,5,2,8,7,9,8,7,78};
 int org=v.size();
 auto itr=::remove_if(v.begin(),v.end(),
			 [](int n){return ((n%2==1)&& n<6);}
			 
			 );
 v.erase(itr,v.end());
 REQUIRE(v.size()==(org-3));
}
