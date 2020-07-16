#include <iostream>
#include "chapter6.h"

using namespace std;

int main() {
	//// test1
	//puddingleos::Cpoint cpt(1, 2);
	//puddingleos::SPoint spt(3, 4);
	////cout << cpt.x << " " << cpt.y << endl;
	////cpt.print();
	//cpt.print1();
	//spt.print();
	///*spt.print1();*/
	//cout << spt.x << " " << spt.y << endl;

	////test2
	//puddingleos::CDerived1 cd1;
	//puddingleos::CDerived2 cd2(1,2);
	//puddingleos::CDerived3 cd3;
	//puddingleos::CDerived4 cd4;
	////cd1.print1();//class的private继承（默认继承），public的函数将不能被对象调用
	//cd2.print1();
	//cd3.print1();//struct的public继承（默认继承），public的函数保持public性质
	////cd4.print1();//struct的private继承同class的private继承

	////test3
	//puddingleos::CDerived2 *cd2 = new puddingleos::CDerived2();
	//cd2->Dosomething();
	//delete cd2;
	//cout << endl;
	//puddingleos::Cpoint* cp1 = new puddingleos::CDerived2();
	//cp1->Dosomething();
	//delete cp1;//如果基类析构函数没有用virtual修饰，则删除时不会调用对象CDerived2的析构函数，导致内存泄漏

	////test4:考察析构函数执行顺序：倒序执行、先子后父
	//puddingleos::B obj1(1, 2);
	//puddingleos::B obj2(3, 4);

	////test5
	//puddingleos::Cpoint cp1(1,2);
	//puddingleos::Cpoint cp2 = cp1;
	//cout << "before fun1()..." << endl;
	//puddingleos::fun1(cp1);
	//puddingleos::Cpoint cp3 = puddingleos::fun2(); //采用默认的复制构造函数，cp3与fun2()生成的class指向内存的同一个位置
	//cout << "After fun2()..." << endl;
	////浅复制：新旧两个对象指向同一个外部内容；深复制：为新对象制作了外部对象的独立复制

	////test6
	////继承类的复制函数，复制父类private变量
	//puddingleos::Cpoint cp1(1, 2);
	//puddingleos::CDerived2 cd1(3, 4, 5);
	//cout << "-----------" << endl;
	//puddingleos::CDerived2 cd2(cd1);
	//cout << "-----------" << endl;

	////test7
	//// C++字符串类型的继承
	//puddingleos::MyString s1("Hello");
	//puddingleos::MyString s2("World");
	//puddingleos::MyString s3(s1);
	//s3 = s2;

	////test8
	////new对象时会生成一个临时对象，其大小默认为1，重构后可以设置对象大小
	////先调用new生成用来存储对象的地址，再调用默认构造函数将临时对象放入
	//puddingleos::Blanks* a5 = new (0xa5) puddingleos::Blanks;

	////test9
	////protected继承与private、public继承的区别
	//class puddingleos::A a;
	//class puddingleos::C c;
	//a.print();
	//c.print();

	////test10
	////基类的private虚函数可以被子类public重写，并动态绑定
	//puddingleos::Cpoint cp1;
	//puddingleos::CDerived2 cd2;
	//puddingleos::Cpoint* p = &cd2;
	//cp1.fun();
	//cd2.fun();
	//p->fun();
	//cp1.print1();//不是虚函数不会被重写，只能调用
	//cd2.print1();
	//p->print1();

	////test11
	////继承与组合的区别
	//puddingleos::Car_pri car_pri;
	//puddingleos::Car_comp car_comp;
	//car_pri.start();
	//car_comp.start();
	////上述代码没有区别，在运行过程和输出结果上
	////继承能够覆写基类的虚函数public virtual（体现编译运行的多态性）

	////test12
	//puddingleos::CDerived2 cd2;
	//puddingleos::CDerived22 cd22;
	//puddingleos::Cpoint cp1;
	////cd2.Dosomething();
	////cd22.Dosomething();
	////cp1.Dosomething();
	//puddingleos::printDosomething(cd2);
	//puddingleos::printDosomething(cd22);
	//puddingleos::printDosomething(cp1);
	////一般来说多态函数基类都要加virtual，派生子类可以不加，一般也加上方便派生子类继续派生

	////test13
	////多重继承，子类的继承，会出现子类函数冲突问题，可以通过指定父类名或者父类virtual继承基类来解决
	//puddingleos::Car_pri_sri cps1;
	//cps1.car_pri_print();
	//cps1.car_sri_print();
	//cps1.start();
	////cps1.Car_pri::start();
	////cps1.Car_sri::start();

	////test14
	////抽象继承需要在子类里实现
	//puddingleos::Shape* sp;
	//sp = &puddingleos::Rectangle(3,4);
	//sp->Display();
	//cout << "Area is " << sp->Area() << endl;
	//sp = &puddingleos::Triangle(4, 6);
	//sp->Display();
	//cout << "Area is " << sp->Area() << endl;

	int N, a, b, k, t;
	scanf("%d\n", &N);
	int* Delay;
	Delay = (int*)malloc(sizeof(int)*N*N);
	for (int i = 0; i < N * N; i++) {
		scanf("%d", &Delay[i]);
	}
	scanf("%d %d %d", &a, &b, &k);
	t = validt(N, Delay, a, b, k);
	printf("The Max Delay is %d", t);
	return 0;
}