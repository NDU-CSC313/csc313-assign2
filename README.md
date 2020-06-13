# Programming Assignment 2
Modify the __body__ of the four functions in the file ```helpers.h``` used by the 
```main.cpp``` file. In addition to the explanations below you will find in  ```main.cpp```
different use cases with input and the expected result. 
## part 1

Implement the function 
```
template<typename iterator,typename T>
iterator find(iterator begin, iterator end, const T& val);
```
It should take a range from begin to end and finds the __first__ occurrence of val.
It returns an iterator to the first occurrence.

## part 2

Implement the function
```
template<typename iterator, typename P>
iterator find_if(iterator begin, iterator end, P pred);
```
It should take a range from begin to end and finds the __first__  element for which (function or function object) __pred__ returns true, i.e. the first element _e_ such that ``` pred(e)``` returns true. It returns an iterator to the first such occurrence.

## part 3

Implement the function 
```
iterator remove(iterator begin,iterator end, T val);
```
It should "remove" all occurrences of _val_. It returns an iterator  to the end of the "useful" values. Let _itr_ be the returned iterator then the range ```[begin,itr)``` does __not__ contain _val_ anymore. The range ```[itr,end)``` may or may not contain _val_. Note that the order of the elements in the range ```[begin,itr)``` should be the same as the original. To understand more the effect of this function, let _v_ be a vector then the code below removes all occurrence of the value _val_ from the vector while retaining the original order of the elements.

```
auto itr=remove(v.begin(),v.end(),val);
v.erase(itr,end);
```

## part 4


Implement the function 

```
iterator remove_if(iterator begin,iterator end, P pred);
```

The effect of this function is the same as remove() in part 3 except that it "removes" all the elements _e_ for which ```pred(e)``` returns true. 