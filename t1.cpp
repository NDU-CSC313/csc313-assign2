#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "helpers.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"


TEST_CASE("Test0", "0") {
 std::vector<int> v {1,9,3,4,2,2,2,5,2};
 auto d=std::distance(v.begin(),::find_if(v.begin(),v.end(),
			 [](int n){return ((n%2==0)&& n<4);}
			 
			 ));
 REQUIRE(d==4);
}

TEST_CASE("Test1", "1") {
 std::vector<int> v {6,9,7,4,2,2,2,5,2};
 auto d=std::distance(v.begin(),::find_if(v.begin(),v.end(),
			 [](int n){return ((n%2==1)&& n<6);}
			 
			 ));
 REQUIRE(d==7);
}
