/// @brief 
struct TestClass {
	int _x, _y;
	TestClass() { std::cout << "default ctor\n"; }
	TestClass(int x, int y) :_x(x), _y(y) { std::cout << "ctor\n"; }
	TestClass(const TestClass& rhs) {
		_x = rhs._x;
		_y = rhs._y;
		std::cout << "copy ctor\n";
	}
	TestClass(TestClass&& rhs) {
		_x = rhs._x;
		_y = rhs._y;
		std::cout << "move ctor\n";
	}
	~TestClass() {
		std::cout << "dtor\n";
	}

};
