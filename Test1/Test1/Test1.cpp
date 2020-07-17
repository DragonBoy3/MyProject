#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "chapter6.h"
#include "chapter8.h"
#include "chapter9.h"

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

	//test2
	puddingleos::CDerived1 cd1;
	puddingleos::CDerived2 cd2(1,2,3);
	puddingleos::CDerived3 cd3;
	puddingleos::CDerived4 cd4;
	//cd1.print1();//class的private继承（默认继承），public的函数将不能被对象调用
	cd2.print1();
	cd3.print1();//struct的public继承（默认继承），public的函数保持public性质
	//cd4.print1();//struct的private继承同class的private继承

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

	 ////std::cout << "Hello World!\n";
	//puddingleos2::CDerived1 cd1;
	//puddingleos2::CDerived2 cd2;
	//puddingleos2::CDerived3 cd3;
	//puddingleos2::CDerived4 cd4;
	//cout << sizeof(cd1) << endl;
	////cd1.print();//成员私有化，不能通过对象来调用
	//cd2.print();
	//cd3.print();
	////cd4.print();//成员私有化，不能通过对象来调用

	//puddingleos2::Obj obj(2);
	//obj.print();

	//puddingleos2::Myclass M(3, 4, 5), N(6, 8, 10);
	//M.GetNumber();
	//M.GetSum();
	//N.GetNumber();
	//N.GetSum();

	////test1
	////explicit修饰的构造函数不能被隐式调用
	//puddingleos2::Test1 t1 = 12;
	////puddingleos2::Test2 t2 = 12;//编译出错
	//puddingleos2::Test2 t3(12);

	////test2
	////临时变量在调用构造函数（包括普通、复制构造参数）时生成，并在生成实际对象后销毁
	////构造函数与析构函数成对出现
	////puddingleos2::B t0(1);
	//puddingleos2::B t1 = puddingleos2::play(5);
	//puddingleos2::B t2 = puddingleos2::play(t1);
	//puddingleos2::B t3 = puddingleos2::play(5);
	//puddingleos2::B t4 = puddingleos2::play(10);

	////test3
	////临时变量与静态成员
	////调用复制构造函数时就会生成临时变量，因此尽量避免class间复制行为
	////或者采用引用的方式传递参数
	//puddingleos2::B b1;
	//b1.print();
	//puddingleos2::B b2 = puddingleos2::play(b1);
	//b2.print();
	//puddingleos2::B b3 = puddingleos2::playx(b1);
	//b3.print();

	////test4
	////重载操作符实现字符串拼接
	//puddingleos2::MyString a((char *)"Hello ");
	//puddingleos2::MyString b((char *)"World");
	//puddingleos2::MyString c((char *)"");
	//c = c + a;
	//c.print();
	//c = c + b;
	//c.print();
	//c = a + b;
	//a.print();
	//c.print();

	//chapter8
	//test1
	//单链表
	//int pos;
	//int data;
	//lgd::node* list1 = lgd::create();
	//int list_len = lgd::len(list1);
	//cout << "Please input the position to search in list:" << endl;
	//cin >> pos;
	//lgd::node* search_result = lgd::search_node(list1, pos);
	//cout << "Please input the position to insert note:" << endl;
	//cin >> pos >> data;
	//lgd::node* insert_result = lgd::insert_node(list1, pos, data);
	//cout << "Please input the delete position:" << endl;
	//cin >> pos;
	//lgd::node* delete_result = lgd::delete_node(list1, pos);
	//lgd::printlist(list1);
	//lgd::node* list2 = lgd::sort_increase();
	//lgd::printlist(list2);

	////test2 列队实现栈操作
	//lgd::MyData data(0);
	//lgd::MyStack s;
	//s.push(lgd::MyData(1));//进栈一次
	//s.push(lgd::MyData(2));//进栈二次
	//s.push(lgd::MyData(3));//进栈三次

	//s.pop(&data);
	//cout << "pop" << data.data << endl;
	//s.pop(&data);
	//cout << "pop" << data.data << endl;
	//s.pop(&data);
	//cout << "pop" << data.data << endl;
	//cout << "Empty=" << s.IsEmpty() << endl;
	//return 0;

	////test3 中序遍历（递归与非递归）
	//int num[] = { 5,3,7,2,4,6,8,1 };
	//lgd::Tree tree(num, 8);
	//cout << "InOder: ";
	//tree.InOrderTree();
	//cout << "\nInOrderUnRec: ";
	//tree.InOrderTreeUnRec();
	//cout << "\nPreOrder: ";
	//tree.PreOrderTree();
	//cout << "\nPreOrderUnRec: ";
	//tree.PreOrderTreeUnRec();
	//cout << "\nPostOrder: ";
	//tree.PostOrderTree();
	//cout << "\nPostOrderUnRec: ";
	//tree.PostOrderTreeUnRec();

	//cout << lgd::max(1, 2) << endl;
	//cout << lgd::max(1.1f, 2.2f) << endl;//隐式调用float类型的max
	//cout << lgd::max(1.11l, 2.22l) << endl;//隐式调用double类型的max
	//cout << lgd::max('A', 'C') << endl;//隐式调用char类型的max
	//cout << lgd::max<int>(1, 2.0) << endl;//指定为int类型
	//
	////test 5 泛型编程 模板类
	//Point_T<int, int> intPt1(1, 2);
	//Point_T<int, int> intPt2(3, 4);
	//Point_T<float, float> floatPt1(1.1f, 2.2f);
	//Point_T<float, float> floatPt2(3.3f, 4.4f);
	//Point_T<int, int> intPt3;
	//Point_T<float, float> floatPt3;
	//intPt3 = (intPt1+intPt2);//括号不能去掉，重载运算符优先级与原运算符不同
	//floatPt3 =(floatPt1 + floatPt2);
	//cout << "(" << (intPt3.a) << "," << (intPt3.b) << ")" << endl;
	//cout << "(" << floatPt3.a << "," << floatPt3.b << ")" << endl;


	//int a[] = { 7,3,5,8,9,1,2,4,6 };
	//cout << "before insert sort: ";
	//print_array(a, sizeof(a) / sizeof(a[0]));
	////insertSort(a, sizeof(a) / sizeof(a[0]));
	////shellSort(a, sizeof(a) / sizeof(a[0]));
	////bubbleSort(a, sizeof(a) / sizeof(a[0]));
	////quickSort(a, 0, sizeof(a) / sizeof(a[0])-1);
	////selectSort(a, sizeof(a) / sizeof(a[0]));
	////heapSort(a, sizeof(a) / sizeof(a[0]));//利用堆的性质，将堆顶的数据与堆尾进行调换，并重建前n个数据堆，最后只剩下堆顶，即完成一次堆排序
	//mergeSort(a, sizeof(a) / sizeof(a[0]));
	//cout << "after insert sort: ";
	//print_array(a, sizeof(a) / sizeof(a[0]));

	//int N, a, b, k, t;
	//scanf("%d\n", &N);
	//int* Delay;
	//Delay = (int*)malloc(sizeof(int)*N*N);
	//for (int i = 0; i < N * N; i++) {
	//	scanf("%d", &Delay[i]);
	//}
	//scanf("%d %d %d", &a, &b, &k);
	//t = validt(N, Delay, a, b, k);
	//printf("The Max Delay is %d", t);


	return 0;
}