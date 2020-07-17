#ifndef _Chapter6_H_
#define _Chapter6_H_

using namespace std;

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
		//virtual ~Cpoint();//�����������ܹ����ж�̬���࣬����ʱ�ж�ָ��ָ�򲢵�����Ӧ����
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
	};//Ĭ��private�̳�
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
	};//ָ��public�̳�
	struct CDerived3 : Cpoint {
	};//Ĭ��public�̳�
	struct CDerived4: private Cpoint{
	};//ָ��private�̳�
	class CDerived5 : protected Cpoint {//protected�̳�
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
		MyString(const char* str = NULL);//���캯��
		MyString(const MyString& str);//���ƹ��캯��
		~MyString(void);//��������
		MyString& operator = (const MyString& str);//��ֵ����
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

}

int validt(int N, int* Delay, int a, int b, int k);


namespace puddingleos2 {
	class BSTnode {
		int data;
		BSTnode* parent;

	};

	class CBase {
		int a;
	public:
		void print();
	};
	//class��struct��Ĭ�ϼ̳й�ϵ���Լ��̳й�ϵ�Ķ������Ȩ��
	class CDerived1 :CBase {};//Ĭ��private�̳�
	class CDerived2 :public CBase {};//ָ��public�̳�
	struct CDerived3 :CBase {};//Ĭ��public�̳�
	struct CDerived4 : private CBase {};//ָ��private�̳�
	//���캯����ֵ˳���ճ�Ա�����Ķ���˳����У������Ǻ�������˳��
	class Obj {
		int i;
		int j;
	public:
		Obj(int k);
		void print();
	};
	//��̬��Ա
	//��̬��Ա���Ƕ����Ա����̬��Ա����ľֲ���������Ҫ�������ʼ��
	//��̬������Ա���ܵ��÷Ǿ�̬��Ա��������Ϊ��̬������Ա����thisָ����
	class Myclass {
		int A;
		int B;
		int C;
		int Num;
		static int Sum;
	public:
		Myclass(int a, int b, int c);
		void GetNumber();
		void GetSum();
	};

	//���ø��๹�캯��ʱֻ��ʹ��initial list���б��ʼ����
	//ͬ��const��reference����Ҳ������assignment��ʼ��
	//���캯����main֮ǰִ�У�Ĭ��ȱʡ
	//�����������ڳ�����������ǰִ�У����򴥷�


	//explicit���������캯������ʽ����
	class Test1 {
		int num;
	public:
		Test1(int n);
	};
	class Test2 {
		int num;
	public:
		explicit Test2(int n);
	};
	class Number {
	public:
		string type;
		Number();
		explicit Number(short);
		Number(int);
	};

	void Show(const Number& n);

	class B {
		int data;
	public:
		static int count;
		B();
		B(int i);
		B(const B& t);
		~B();
		void print();
	};
	B play(B b);
	B playx(B& b);

	class MyString {
		char* str;
	public:
		MyString();
		MyString(char* s);//��ͨ���캯��
		~MyString();//��������
		MyString& operator = (MyString& string);//����=������
		MyString& operator + (MyString& string);//����+������

		//MyString& operator + (MyString& string);
		//MyString& operator + (MyString& string);
		void print();
	};
}
#endif