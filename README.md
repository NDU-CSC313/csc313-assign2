
Many of the data structures that we will be studying and implementing are already implemented in the Standard Template Library (STL). Our strategy is to use and familiarize ourselves with the provided containers and algorithms and then implement them ourselves.
# Vector container
A vector is basically a dynamic array. We can add and remove elements from it and it auto resizes itself. Since we would like to store any type of objects in a vector the implementation uses templates to pass any type to the vector. A vector has the all usual syntax of arrays, specifically the indexing.

```
#include <vector>
int main(){
    //declare a vector of int. creates an empty vector
    std::vector<int > v;
    //declare a vector of strings
    std::vector<std::string > sv;
    //add elements to the end
    v.push_back(1);
    v.push_back(2);
    sv.push_back("one");
    sv.push_back("two");
    //print all elements similar to arrays
    for(int i=0;i<sv.size();++i)
        std::cout<<sv[i]<<",";
    std::cout<<"\n";
    //print all elements using range-based for loop
    for(auto x:v)
        std::cout<<x<< ",";
    std::cout<<"\n";

    
}
```
The ```push_back``` member function adds an element at the end of the vector. Above we have used two features from c++11: auto and range-based for loops. As you can see we can create a vector of any type (note the syntax). 
**Note**: since the type of an auto variable is inferred by the compiler it cannot be used with _uninitialized_ variables.
```
auto x;//error
auto y=1;//OK
```
## Automatic allocation

In a typical use case when we use ```push_back``` we don't know in advance the size of the data. If memory allocated to the vector is "full" then the vector needs to allocate more space **and** copy the existing data to the new storage space before adding the new values.
Let us look an example using arrays
```
  //create an array of two elements
        int size = 2;
        int* p = new int[2];
        for (int i = 0; i < 10; ++i) {
            if (i == size) {//array is full
                std::cout << "copying\n";
                int* old = p;
                p = new int[size + 1];
                for (int j = 0; j < size; ++j)
                    p[j] = old[j];
                size++;
            }
            p[i] = i;

        }
        std::cout << "------content-------\n";
        for (int i = 0; i < size; ++i)
            std::cout << p[i] << ",";
        std::cout << "\n";
```
It is obvious from the example that there is a lot of copying. In fact if we add _n_ numbers there will be _n<sup>2</sup>_ operations. A smarter strategy would be to overallocate. The overallocation is STL implementation dependent. A good rule of thumb, used by the g++ STL, is to double the size every time.
```
 {
        //create an array of two elements
        int size = 2;
        int* p = new int[2];
        for (int i = 0; i < 10; ++i) {
            if (i == size) {//array is full
                std::cout << "copying\n";
                int* old = p;
                p = new int[2*size];
                for (int j = 0; j < size; ++j)
                    p[j] = old[j];
                size*=2;
            }
            p[i] = i;

        }
        std::cout << "------content-------\n";
        for (int i = 0; i < size; ++i)
            std::cout << p[i] << ",";
        std::cout << "\n";
    }
```
But as you can see in the output, after the 10th element the values are arbitrary. This is because we didn't differentiate between __size__ and __capacity__. This is exactly how a vector handles allocated memory.
```
 {   std::vector<int> v;
         for (int i = 0; i < 100; i++) {
        std::cout << "i= " << i << ", capacity=" << v.capacity() << std::endl;
        v.push_back(i);
          }
    }
```
If you run the above you will see the effect of preallocating memory. **Note**: it seems the msc++ uses a different preallocation strategy. From what i see it looks that the size is incremented 50% every time instead of 100%.
### Iterators
Iterators are generalization of pointers and present a common interface to all STL containers and algorithms. For an array a pointer is sufficient since the elements of an array form a contiguous location in memory. What if the elements are not stored contiguously? Since every container stores the elements differently it implements its own methods to _iterate_ over its elements. This has the added value that the user does not need to know the internal workings of the container in order to be able to use it.
 Given a container **c** and iterator **itr** points at an element stored in **c**. Therefore dereferencing an iterator **(*itr)** will return the element itself. Also iterators can be incremented and decremented like pointers: (itr++) and (itr--). Furthermore, every container **c** has a **begin** and **end()** method. As an example, suppose that we have a container that stores an integer sequence from 0 to n-1 but even numbers first then odd numbers. For example, 0,2,4,6,8,1,3,5,7,9. Below is a code that allow us to iterate over the values in order
```
class Container {
    int* p, * _begin;
protected:
    int _size;
    int *_end;
public:
    class Iterator {
        int* current;
        int _size;
    public:
        Iterator(int* p,int size) :current(p),_size(size) {}
        Iterator operator++() {
            
            if (*current == _size-1)current = current + 1;
            else if (*current % 2 == 0)
                current = current + _size / 2;
            else
                current = current-_size/2+1;
            return *this;
        }
        int operator *() {
            return *current;
        }
        bool operator!=(const Iterator& rhs) {
            return current != rhs.current;
        }
        
    };
    Container(int size) :_size(size) {
        p = new int[_size];
        _begin = p;
        _end = p + size;
        for (int i = 0; i < _size; ++i) {
            if (i % 2 == 0)
                p[i / 2] = i;
            else
                p[_size / 2 + i / 2] = i;
        }
    }
    Iterator begin() {
        return Iterator(_begin,_size);
    }
    Iterator end() {
        return Iterator(_end,_size);
    }
};

```
so we can print the values in order as follows:
```
 Container c(10);
    for (Container::Iterator itr = c.begin(); itr != c.end(); ++itr)
        std::cout << *itr << ",";

```
Note the syntax for a dependent type (we could have used auto) because Iterator is a nested class. Similarly to the above we can use iterators with any STL container. In particular with vectors.
```
#include <vector>
#include <iostream>
int main(){
  std::vector<std::string> sv;
  sv.push_back("one");
  sv.push_back("two");
  for(auto itr=sv.begin();itr!=sv.end();itr++){
      std::cout<<(*itr)<<std::endl;
  }
}  
```
The auto keyword is useful since otherwise we have to write down the long type of the iterator: (since it is an iterator to container of type ```std::vector<std::string>```)
```
std::vector<std::string>::iterator itr;
```
vectors can be used similarly to arrays.
```
std::vector<int> iv;
iv.push_back(1);
iv.push_back(2);
for(int i=0;i<iv.size();i++)
  iv[i]=i;
```
Since vectors are required by the c++ standard to use contiguous memory 
it is best to add and remove(as opposed to change) from the end of a vector.
We still can insert and erase elements at arbitrary position using iterators but it is a _costly_ operation.

## Pre allocation

In what follows we will use a TestClass 
```
template <int nodebug=0>
struct TestClass {
    int _x, _y;
    TestClass(int x = 0, int y = 0) :_x(x), _y(y) {
       if(!nodebug) std::cout << "ctor\n";

    }
    TestClass(const TestClass& rhs) {
        if(!nodebug)std::cout << "copy ctor\n";
        _x = rhs._x;
        _y = rhs._y;
    };
    TestClass& operator=(const TestClass& rhs) {
        if(!nodebug)std::cout << "assignment\n";
        _x = rhs._x;
        _y = rhs._y;
        return *this;
    }
     std::pair<int, int> val() {
        return std::pair<int, int>(_x, _y);
    }
    int& x() {
        return _x;
    }
    int& y() {
        return _y;
    }
    ~TestClass() {
        if(!nodebug)std::cout << "dtor\n";
    }
};
```
Let us see what happens when we add objects of type TestClass to a vector.

```
std::vector<TestClass<0>> v;
TestClass a(1,2);
TestClass b(3,4);
v.push_back(a);
v.push_back(b);
```
if we run the above we get the following output
```
ctor
ctor
copy ctor
copy ctor
copy ctor
```

Obviously there are two calls for the constructor for a and b. The method push_back saves a __copy__ of the input hence the two calls for the copy constructor. The third call for the copy constructor is because the vector was resized to accommodate b.

Sometimes it is useful to preallocate memory to minimize the number of copy operations when the vector is resized. There are two ways of doing this.
1. Specifying the size when the vector is created
1. Using the vector::reserve method
```
{
    std::vector<TestClass<0>> v(2);
    TestClass a(1, 2);
    TestClass b(3, 4);
    v[0] = a;
    v[1] = b;
    std::cout << "size= " << v.size() << std::endl;
    std::cout << "----------------\n";

    }
    {
    std::vector<TestClass<0>> v;
    v.reserve(2);
    TestClass a(1, 2);
    TestClass b(3, 4);
    v.push_back(a);
    v.push_back(b);
    std::cout << "size= " << v.size() << std::endl;
    std::cout << "----------------\n";
    }
```
The output of the above code is 
```
ctor
ctor
ctor
ctor
assignment
assignment
size= 2
----------------
ctor
ctor
copy ctor
copy ctor
size= 2
----------------
```
This is because not only the vector constructor reserves space for two objects but it will also call the default constructor of the object to initialize the reserved space. In this case we use the index operator to change the values. Whereas the member function reserve does not create objects when it reserves space.
Removing elements from the __end__ of the vector is done using ```pop_back()```
```
{
    std::vector<TestClass<0>> v;
    v.push_back(TestClass<0>(1, 2));
    v.push_back(TestClass<0>(3, 4));
    std::cout << v.size() << std::endl;
    v.pop_back();
    std::cout << v.size() << std::endl;

    }
```
## insertion and deletion
So far we added and removed elements from the __end__ of the vector. We can do the same operations at arbitrary positions using iterators even though if these operations are to be done repeatedly a vector is not the best data structure to use.
### insertion
The code below uses the _insert_ function to add an element between __a__ and __b__ of the vector
```
{
std::vector<TestClass<0>> v;
v.reserve(4);
TestClass<0> a(1,2);
TestClass<0> b(3,4);
TestClass<0> c(5,6);
TestClass<0> d(7,8);
v.push_back(a);
v.push_back(b);
v.push_back(c);

 auto itr=v.insert(v.begin()+1,d);
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (i == itr)std::cout << "element inserted here: ";
        std::cout << i->x() << "," << i->y() << std::endl;

    }
}

```
If you inspect the output you will see the following happening 
1. ctor is used to create a,b,c,d.
1. copy ctor is used to to copy the values of a,b,c to the vector (push_back)
1. copy ctor is used to make a copy of d
1. copy ctor is used to copy the value of c the 4th place that was reserved in the vector.
1. Assignment is used to overwrite the 3rd place by the value of b
1. Assignment is used to overwrite the 2nd place by the value of d

This means that inserting a value in a vector any place other than the end will cause order of __n__ copy/assignments. If such insertions are done often then a vector is not the optimal data structure to use. Note that the return value of insert is an iterator to the element that was inserted.
Similarly, we can erase values from a vector at arbitrary positions
```

  {
  std::vector<TestClass<0>> v(5);
  TestClass<0> a(1, 2);
  TestClass<0> b(3, 4);
  v[0] = a;
  v[1] = b;
  std::cout << "size= " << v.size() << std::endl;
  std::cout << "----------------\n";
  v.erase(v.begin());
  std::cout << "-------done----\n";
  }


```
Since the deleted element is at the beginning of the vector it also triggers an order of __n__ assignments to move values to the left.
Because of that, if you need to remove multiple items meeting a certain criterion, it is better to use the remove/erase idiom. We illustrate with two different ways of removing elements whose __y__ value is 2 from a vector. The first, goes through a loop and when it finds an element with y==2 it erases it. Note that erase returns an iterator to the element __after__ the erased one.  

```
{
std::vector<TestClass<0>> v;
v.reserve(4);
TestClass<0> a(1, 2);
TestClass<0> b(3, 4);
TestClass<0> c(5, 2);
TestClass<0> d(5, 6);
v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
std::cout << "---searching--\n";
for (auto itr = v.begin(); itr != v.end();) {
    if (itr->y() == 2) {
        itr=v.erase(itr);
    }
    else itr++;
}
std::cout << "----done searching\n";
  }


```
The second, more efficient way is to use the std::remove_if then erase. The function std::remove_if doesn't actually remove elements, it "moves all elements meeting the criterion towards the end" of the vector and returns an iterator to the first one.

```

{
    std::vector<TestClass<0>> v;
    v.reserve(4);
    TestClass<0> a(1, 2);
    TestClass<0> b(3, 4);
    TestClass<0> c(5, 2);
    TestClass<0> d(5, 6);
    v.push_back(a); v.push_back(b); v.push_back(c); v.push_back(d);
    std::cout << "---searching--\n";
    auto itr=std::remove_if(v.begin(), v.end(), [](auto& t) { return t.y() == 2; });
    v.erase(itr, v.end());
    std::cout << "----done searching\n";
}


```

## Lists 
Lists are similar to vectors but allow us to insert elements at arbitrary
positions. So in addition to push_back() a list supports push_front() and 
insert. The insert method has the following signature
```
iterator insert(iterator itr, object o)
```
So insert adds an element **before** the element pointed to by itr
and returns an iterator to the inserted element.
### Exercise

![](step1.png)
![](step2.png)
![](step3.png)
![](step4.png)


