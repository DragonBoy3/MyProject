#ifndef _Chapter6_H_
#define _Chapter6_H_

namespace puddingleos {
	class Cpoint {
	private:
		int x;// default: private
		int y;// default: private
		void print();
		virtual void print2();
	protected:
		void printfProtected();
	public:
		Cpoint();
		Cpoint(int x, int y);
		Cpoint(Cpoint& x);//copy constructor
		~Cpoint();
		//virtual ~Cpoint();//虚析构函数能够进行动态联编，运行时判断指针指向并调用相应函数
		//print1();
		void print1();
		void fun();
		virtual void Dosomething();
	};

	struct SPoint {
		int x;// default public
		int y;// default public
		void print();
		SPoint(int x, int y);
	private:
		void print1();

	};

	class CDerived1:Cpoint{
	};//默认private继承
	class CDerived2:public Cpoint{
		int r;
	public:
		CDerived2();
		CDerived2(int a, int b, int c);
		CDerived2(CDerived2 &temp);
		~CDerived2();
		virtual void Dosomething();
		void print();
		void print2();
	};//指定public继承
	struct CDerived3 : Cpoint {
	};//默认public继承
	struct CDerived4: private Cpoint{
	};//指定private继承
	class CDerived5 : protected Cpoint {//protected继承
	};
	class CDerived22 :public Cpoint {
	public:
		virtual void Dosomething();
	};

	class A :public CDerived5{
		int a;
	public:
		A();
		A(int a);
		~A();
		void print();
	};
	class B :public A {
		int b;
	public:
		B(int aa, int bb);
		~B();
	};

	class C : public CDerived1{
	public:
		void print();
	};


	void fun1(Cpoint temp);
	Cpoint fun2();

	class MyString {
		char* m_String;
	public:
		MyString(const char* str = NULL);//构造函数
		MyString(const MyString& str);//复制构造函数
		~MyString(void);//析构函数
		MyString& operator = (const MyString& str);//赋值函数
	};
	//Blanks
	class Blanks {
	public:
		Blanks();
		void* operator new(size_t stAllocateBlock, char chInit);
	};

	//Engine
	class Engine {
		int numCylinders;
	public:
		Engine();
		Engine(int num);
		void start();
	};
	//Car_pri
	class Car_pri :virtual public Engine {
	public:
		Car_pri() ;
		void start();
		void car_pri_print();
	};
	//Car_comp
	class Car_comp {
		Engine engine;
	public:
		Car_comp();
		void start();
	};
	//Car_sri
	class Car_sri :virtual public Engine {
	public:
		Car_sri();
		void car_sri_print();
	};

	void printDosomething(Cpoint& cp);

	//Car_pri_comp
	class Car_pri_sri:public Car_pri,public Car_sri {
	public:
		Car_pri_sri();
	};

	class Shape {
	public:
		virtual void Display() = 0;
		virtual double Area() = 0;
	};
	class Rectangle :public Shape {
		int a;
		int b;
	public:
		Rectangle();
		Rectangle(int a, int b);
		virtual void Display();
		virtual double Area();
	};
	class Triangle :public Shape {
		int l;
		int h;
	public:
		Triangle();
		Triangle(int l, int h);
		virtual void Display();
		virtual double Area();
	};

	class BSTnode {
		int data;
		BSTnode* parent;

	};
}

int validt(int N, int* Delay, int a, int b, int k);

#endif