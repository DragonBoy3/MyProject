#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "chapter6.h"
#include <malloc.h>
#include <memory.h>


//Cpoint
void puddingleos::Cpoint::printfProtected() {
	cout << "print Protected" << endl;
}
void puddingleos::Cpoint::print() {// default: private
	cout << "CPoint: (" << x << "," << y << ")" << endl;
};
//puddingleos::Cpoint::Cpoint() {};//默认构造函数
puddingleos::Cpoint::Cpoint():x(0),y(0) {};
puddingleos::Cpoint::Cpoint(int a, int b) :x(a), y(b) {//普通构造函数
	cout << "Cpoint(int)" << endl;
};
puddingleos::Cpoint::Cpoint(puddingleos::Cpoint &temp) {//复制构造函数
	puddingleos::Cpoint::x = temp.x;
	puddingleos::Cpoint::y = temp.y;
	cout << "Copy Constructor" << endl;
}
puddingleos::Cpoint::~Cpoint() {
	cout << "Output from the destructor of class Cpoint!" << endl;
};
void puddingleos::Cpoint::print1() {
	print();
	cout << "CPoint:(" << x << "," << y << ")" << endl;
};
void puddingleos::Cpoint::Dosomething() {
	cout << "Do something in class Cpoint!" << endl;
};
void puddingleos::Cpoint::print2() {
	cout << "I am a Base`s private function" << endl;
}
void puddingleos::Cpoint::fun() {
	print2();
}

//Spoint
void puddingleos::SPoint::print() {// default: private
	cout << "CPoint: (" << x << "," << y << ")" << endl;
};
puddingleos::SPoint::SPoint(int x, int y) {// default: public
	this->x = x;
	this->y = y;
};
 void puddingleos::SPoint::print1() {
	 cout << "CPoint:(" << x << "," << y << ")" << endl;
 };

 //CDerived2
puddingleos::CDerived2::CDerived2():puddingleos::Cpoint(0,0),puddingleos::CDerived2::r(0) {//默认构造函数（初始化）
	cout << "Derived2()" << endl;
};
puddingleos::CDerived2::CDerived2(int a = 0, int b = 0, int c = 0) : puddingleos::Cpoint(a, b),puddingleos::CDerived2::r(c){
	cout << "CDerived2: p1=" << a << ", p2=" << b << ", p3=" << r << endl;
};
puddingleos::CDerived2::CDerived2(puddingleos::CDerived2 &temp):puddingleos::Cpoint(temp), puddingleos::CDerived2::r(temp.r) {
	cout << "Derived2(Derived2&)" << endl; // 复制构造函数，调用基类Cpoint
};
puddingleos::CDerived2::~CDerived2() {
	cout << "Output from the destructor of class CDerived2!" << endl;
};
void puddingleos::CDerived2::Dosomething() {
	cout << "Do something in class CDerived2!" << endl;
};
void puddingleos::CDerived2::print2() {
	cout << "I am a derived function" << endl;
}
void puddingleos::CDerived2::print() {
	cout << "tt" << endl;
}

//CDerived22
void puddingleos::CDerived22::Dosomething() {
	cout << "Do something in class CDerived22!" << endl;
}

//A
puddingleos::A::A() {};
puddingleos::A::A(int a) {
	this->a = a;
};
puddingleos::A::~A() {
	cout << "Destructor A!" << a << endl;
};
void puddingleos::A::print() {
	printfProtected();
	print1();
}
//B
puddingleos::B::B(int aa = 0, int bb = 0) :A(aa) {
	b = bb;
};
puddingleos::B::~B() {
	cout << "Destructor B!" << b << endl;
};
//C
void puddingleos::C::print() {
	//printfProtected();//C类public继承的CDerived1是Cpoint的private继承，public*private*public=private，无法读取
	//print1();//同上
	cout << "No function can be executed" << endl;
}


void puddingleos::fun1(puddingleos::Cpoint temp) {
	cout << "fun1()..." << endl;
};
puddingleos::Cpoint puddingleos::fun2() {
	puddingleos::Cpoint temp(1, 2);
	cout << "fun2()..." << endl;
	return temp;
};

//MyString
puddingleos::MyString::MyString(const char* str) {
	cout << "Constructing" << endl;
	if (str == NULL) {
		m_String = new char[1];
		*m_String = '\0';
	}
	else {
		m_String = new char[strlen(str) + 1];
		strcpy(m_String, str);
	}
};
puddingleos::MyString::MyString(const puddingleos::MyString& str) {
	cout << "Constructing" << endl;
	m_String = new char[strlen(str.m_String) + 1];
	strcpy(m_String, str.m_String);
}
puddingleos::MyString::~MyString(void) {
	cout << "Destroying" << endl;
	if (m_String != NULL) {
		delete[]m_String;
		m_String = NULL;
	}
};
puddingleos::MyString & puddingleos::MyString::operator=(const puddingleos::MyString &str) {
	cout << "Operating = Function" << endl;
	if (this == &str) {
		return *this;
	}
	delete[]m_String;
	m_String = new char[strlen(str.m_String) + 1];
	strcpy(m_String, str.m_String);

	return *this;
};

// Blanks
puddingleos::Blanks::Blanks() {};//default constructor
void* puddingleos::Blanks::operator new(size_t stAllocateBlock, char cInit) {
	void* pvTemp = malloc(stAllocateBlock);
	if (pvTemp != 0)
		memset(pvTemp, cInit, stAllocateBlock);
	return pvTemp;
}

//Engine
puddingleos::Engine::Engine() :numCylinders(5) {};
puddingleos::Engine::Engine(int num) :numCylinders(num) {
};
void puddingleos::Engine::start() {
	cout << "Engine Start, " << numCylinders << " Cylinders" << endl;
}
//Car_pri
puddingleos::Car_pri::Car_pri() :Engine(8) {};
void puddingleos::Car_pri::start() {
	Engine::start();
}
void puddingleos::Car_pri::car_pri_print() {
	cout << "Car pri is started"<< endl;
	Engine::start();
}
//Car_comp
puddingleos::Car_comp::Car_comp() :engine(8) {};
void puddingleos::Car_comp::start() {
	engine.start();
}

void puddingleos::printDosomething(puddingleos::Cpoint &cp) {
	cp.Dosomething();
}

//Car_sri
puddingleos::Car_sri::Car_sri() :Engine(8) {};
void puddingleos::Car_sri::car_sri_print() {
	cout << "Car sri is started" << endl;
	Engine::start();
}

//Car_pri_sri
puddingleos::Car_pri_sri::Car_pri_sri() :Engine(6){};

//Shape

//Rectangle
puddingleos::Rectangle::Rectangle() :a(0), b(0) {};
puddingleos::Rectangle::Rectangle(int x, int y) :a(x), b(y) {};
void puddingleos::Rectangle::Display() {
		cout << "Rectangle Area = " << a * b << endl;
}
double puddingleos::Rectangle::Area() {
	return a * b;
}
//Triangle
puddingleos::Triangle::Triangle() :l(0), h(0) {};
puddingleos::Triangle::Triangle(int x, int y) :l(x), h(y) {};
void puddingleos::Triangle::Display() {
	cout << "Triangle Area = " << l * h / 2 << endl;
}
double puddingleos::Triangle::Area() {
	return l * h / 2;
}

int validt(int N, int* Delay, int a, int b, int k) {
	if ((N > 1000) || (k >= 1e9) || (a > N) || (b > N))
		return -1;
	int Delay_ab = Delay[(a - 1) * N + b - 1];
	return k > Delay_ab ? (k - Delay_ab-1) : -1;
}

void puddingleos2::CBase::print() {
	cout << "CBase: print()..." << endl;
}

puddingleos2::Obj::Obj(int k) :j(k), i(j) {};//构造函数
void puddingleos2::Obj::print() {
	cout << i << endl << j << endl;
}

int puddingleos2::Myclass::Sum = 0;//Myclass类的静态成员变量为类的全局变量，继承该类的所有对象均可访问
puddingleos2::Myclass::Myclass(int a, int b, int c) :A(a), B(b), C(c) {
	Num = A + B + C;
	Sum = A + B + C;
};

void puddingleos2::Myclass::GetNumber() {
	cout << "Number = " << Num << endl;
}

void puddingleos2::Myclass::GetSum() {
	cout << "Sum = " << Sum << endl;
}
puddingleos2::Test1::Test1(int n) {
	num = n;
}
puddingleos2::Test2::Test2(int n) {
	num = n;
}

puddingleos2::Number::Number() :type("void") {};
puddingleos2::Number::Number(int) :type("int") {};
puddingleos2::Number::Number(short) :type("short") {};

void puddingleos2::Show(const Number& n) {
	cout << n.type << endl;
}
//B
int puddingleos2::B::count = 0;
puddingleos2::B::B() {
	count++;
	cout << "default constructor" << endl;
};
puddingleos2::B::B(int i) :data(i) {
	count++;
	cout << "constructor by parameter" << data << endl;
};
puddingleos2::B::B(const B& t) {
	count++;
	data = t.data;
	cout << "copy constructor " << data << endl;
};
puddingleos2::B::~B() {
	count--;
	cout << "Destroy constructor" << endl;
	print();
};
void puddingleos2::B::print() {
	cout << "count = " << count << endl;
}
//play
puddingleos2::B puddingleos2::play(B b) {
	b.print();
	return b;
}
puddingleos2::B puddingleos2::playx(B& b) {
	b.print();
	return b;
}

//MyString
puddingleos2::MyString::MyString() {};
puddingleos2::MyString::MyString(char* s) {
	str = new char[strlen(s) + 1];
	strcpy(str, s);
}
puddingleos2::MyString::~MyString() {
	delete[]str;
}
puddingleos2::MyString& puddingleos2::MyString::operator=(puddingleos2::MyString& string) {
	if (this == &string)//重载自身则直接返回MyString类的指针
		return *this;
	if (str != NULL) {//否则将string.str赋值给this.str，并返回this的指针（引用本质上为指针）
		delete[] str;
	}
	str = new char[strlen(string.str) + 1];
	strcpy(str, string.str);
	return *this;
}
//puddingleos2::MyString& puddingleos2::MyString::operator+(puddingleos2::MyString& string) {
//	char* temp = str;//字符串拼接，重载“+”（改变被加对象）
//	str = new char[strlen(temp) + strlen(string.str) + 1];
//	strcpy(str, temp);
//	delete[]temp;
//	strcat(str, string.str);
//	return *this;
//}
puddingleos2::MyString& puddingleos2::MyString::operator+(puddingleos2::MyString& string) {
	char* s_t = (char*)"";
	MyString* pString = new puddingleos2::MyString(s_t);//重载+(不改变被加对象，在堆中新建一个构造)
	pString->str = new char[strlen(str) + strlen(string.str) + 1];
	strcpy(pString->str, str);
	strcat(pString->str, string.str);
	return *pString;
}

void puddingleos2::MyString::print() {
	cout << str << endl;
}
