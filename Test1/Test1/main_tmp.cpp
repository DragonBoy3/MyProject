#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "chapter6.h"
#include "chapter8.h"
#include "chapter9.h"
#include "newCoder.h"

using namespace std;

//int main() {
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
//puddingleos::CDerived2 cd2(1,2,3);
//puddingleos::CDerived3 cd3;
//puddingleos::CDerived4 cd4;
////cd1.print1();//class��private�̳У�Ĭ�ϼ̳У���public�ĺ��������ܱ��������
//cd2.print1();
//cd3.print1();//struct��public�̳У�Ĭ�ϼ̳У���public�ĺ�������public����
////cd4.print1();//struct��private�̳�ͬclass��private�̳�

////test3
//puddingleos::CDerived2 *cd2 = new puddingleos::CDerived2();
//cd2->Dosomething();
//delete cd2;
//cout << endl;
//puddingleos::Cpoint* cp1 = new puddingleos::CDerived2();
//cp1->Dosomething();
//delete cp1;//���������������û����virtual���Σ���ɾ��ʱ������ö���CDerived2�����������������ڴ�й©

////test4:������������ִ��˳�򣺵���ִ�С����Ӻ�
//puddingleos::B obj1(1, 2);
//puddingleos::B obj2(3, 4);

////test5
//puddingleos::Cpoint cp1(1,2);
//puddingleos::Cpoint cp2 = cp1;
//cout << "before fun1()..." << endl;
//puddingleos::fun1(cp1);
//puddingleos::Cpoint cp3 = puddingleos::fun2(); //����Ĭ�ϵĸ��ƹ��캯����cp3��fun2()���ɵ�classָ���ڴ��ͬһ��λ��
//cout << "After fun2()..." << endl;
////ǳ���ƣ��¾���������ָ��ͬһ���ⲿ���ݣ���ƣ�Ϊ�¶����������ⲿ����Ķ�������

////test6
////�̳���ĸ��ƺ��������Ƹ���private����
//puddingleos::Cpoint cp1(1, 2);
//puddingleos::CDerived2 cd1(3, 4, 5);
//cout << "-----------" << endl;
//puddingleos::CDerived2 cd2(cd1);
//cout << "-----------" << endl;

////test7
//// C++�ַ������͵ļ̳�
//puddingleos::MyString s1("Hello");
//puddingleos::MyString s2("World");
//puddingleos::MyString s3(s1);
//s3 = s2;

////test8
////new����ʱ������һ����ʱ�������СĬ��Ϊ1���ع���������ö����С
////�ȵ���new���������洢����ĵ�ַ���ٵ���Ĭ�Ϲ��캯������ʱ�������
//puddingleos::Blanks* a5 = new (0xa5) puddingleos::Blanks;

////test9
////protected�̳���private��public�̳е�����
//class puddingleos::A a;
//class puddingleos::C c;
//a.print();
//c.print();

////test10
////�����private�麯�����Ա�����public��д������̬��
//puddingleos::Cpoint cp1;
//puddingleos::CDerived2 cd2;
//puddingleos::Cpoint* p = &cd2;
//cp1.fun();
//cd2.fun();
//p->fun();
//cp1.print1();//�����麯�����ᱻ��д��ֻ�ܵ���
//cd2.print1();
//p->print1();

////test11
////�̳�����ϵ�����
//puddingleos::Car_pri car_pri;
//puddingleos::Car_comp car_comp;
//car_pri.start();
//car_comp.start();
////��������û�����������й��̺���������
////�̳��ܹ���д������麯��public virtual�����ֱ������еĶ�̬�ԣ�

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
////һ����˵��̬�������඼Ҫ��virtual������������Բ��ӣ�һ��Ҳ���Ϸ������������������

////test13
////���ؼ̳У�����ļ̳У���������ຯ����ͻ���⣬����ͨ��ָ�����������߸���virtual�̳л��������
//puddingleos::Car_pri_sri cps1;
//cps1.car_pri_print();
//cps1.car_sri_print();
//cps1.start();
////cps1.Car_pri::start();
////cps1.Car_sri::start();

////test14
////����̳���Ҫ��������ʵ��
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
////cd1.print();//��Ա˽�л�������ͨ������������
//cd2.print();
//cd3.print();
////cd4.print();//��Ա˽�л�������ͨ������������

//puddingleos2::Obj obj(2);
//obj.print();

//puddingleos2::Myclass M(3, 4, 5), N(6, 8, 10);
//M.GetNumber();
//M.GetSum();
//N.GetNumber();
//N.GetSum();

////test1
////explicit���εĹ��캯�����ܱ���ʽ����
//puddingleos2::Test1 t1 = 12;
////puddingleos2::Test2 t2 = 12;//�������
//puddingleos2::Test2 t3(12);

////test2
////��ʱ�����ڵ��ù��캯����������ͨ�����ƹ��������ʱ���ɣ���������ʵ�ʶ��������
////���캯�������������ɶԳ���
////puddingleos2::B t0(1);
//puddingleos2::B t1 = puddingleos2::play(5);
//puddingleos2::B t2 = puddingleos2::play(t1);
//puddingleos2::B t3 = puddingleos2::play(5);
//puddingleos2::B t4 = puddingleos2::play(10);

////test3
////��ʱ�����뾲̬��Ա
////���ø��ƹ��캯��ʱ�ͻ�������ʱ��������˾�������class�临����Ϊ
////���߲������õķ�ʽ���ݲ���
//puddingleos2::B b1;
//b1.print();
//puddingleos2::B b2 = puddingleos2::play(b1);
//b2.print();
//puddingleos2::B b3 = puddingleos2::playx(b1);
//b3.print();

////test4
////���ز�����ʵ���ַ���ƴ��
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
//������
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

////test2 �ж�ʵ��ջ����
//lgd::MyData data(0);
//lgd::MyStack s;
//s.push(lgd::MyData(1));//��ջһ��
//s.push(lgd::MyData(2));//��ջ����
//s.push(lgd::MyData(3));//��ջ����

//s.pop(&data);
//cout << "pop" << data.data << endl;
//s.pop(&data);
//cout << "pop" << data.data << endl;
//s.pop(&data);
//cout << "pop" << data.data << endl;
//cout << "Empty=" << s.IsEmpty() << endl;
//return 0;

////test3 ����������ݹ���ǵݹ飩
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
//cout << lgd::max(1.1f, 2.2f) << endl;//��ʽ����float���͵�max
//cout << lgd::max(1.11l, 2.22l) << endl;//��ʽ����double���͵�max
//cout << lgd::max('A', 'C') << endl;//��ʽ����char���͵�max
//cout << lgd::max<int>(1, 2.0) << endl;//ָ��Ϊint����
//
////test 5 ���ͱ�� ģ����
//Point_T<int, int> intPt1(1, 2);
//Point_T<int, int> intPt2(3, 4);
//Point_T<float, float> floatPt1(1.1f, 2.2f);
//Point_T<float, float> floatPt2(3.3f, 4.4f);
//Point_T<int, int> intPt3;
//Point_T<float, float> floatPt3;
//intPt3 = (intPt1+intPt2);//���Ų���ȥ����������������ȼ���ԭ�������ͬ
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
////heapSort(a, sizeof(a) / sizeof(a[0]));//���öѵ����ʣ����Ѷ����������β���е��������ؽ�ǰn�����ݶѣ����ֻʣ�¶Ѷ��������һ�ζ�����
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

/*int a = 24;
printf("%o\n", a);

a = 9;

printf("%d\n", a += a -= a + a);


int count = 0;
for (int i = 10, j = 1;i = j = 0;i++, j--)
	count++;
printf("%d\n", count);*/
//
//cout << "Please tap the fabonacci number:" << endl;
//int n;
//cin >> n;
//int result[] = { 0,1 };
//int n_dup = n;
//cout << "Fabonacci Serial :";
//if (n < 2) {
//	while (n-- > 0)
//		cout << n << " ";
//	cout << "\nreslut is" << n << endl;
//}
//	
//else {
//	long long Fb0 = 0;
//	long long Fb1 = 1;
//	long long FbN = 0;
//	cout << "0 1 ";
//	for (int i = 2;i < n;i++) {
//		FbN = Fb0 + Fb1;
//		Fb0 = Fb1;
//		Fb1 = FbN;
//		cout << FbN << " ";
//	}
//	cout << "\nresult is " << FbN << endl;
//}
//cout << "Please input a num:";
//int n;
//cin >> n;
//Solution* ptr1 = new Solution;
//cout << "message count is:" << (*ptr1).messageCount(n) << endl;

//}