#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include "helpers.h"
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.h"


TEST_CASE("Test0", "0") {
 std::vector<int> v {1,8,3,4,2,2,2,5,2};
 auto d=::remove(v.begin(),v.end(),2);
 v.erase(d,v.end());
 REQUIRE(v.size()==5);
}

TEST_CASE("Test1", "1") {
 std::vector<int> v {1,8,3,4,2,2,5,2,5,2};
 auto d=::remove(v.begin(),v.end(),5);
 v.erase(d,v.end());
 REQUIRE(v.size()==8);
}

TEST_CASE("Test2", "2") {
 std::vector<int> v {1,5,5,5,17,5,20,999,2,2,5,2};
 auto d=::remove(v.begin(),v.end(),5);
 v.erase(d,v.end());
 REQUIRE(v.size()==7);
}
