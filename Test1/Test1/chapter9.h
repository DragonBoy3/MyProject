#ifndef _chapter9_H_
#define _chapter9_H_
#include<iostream>
//#include "stdafx.h"
using namespace std;

namespace lgd {
	template <class T>
	T max(T a, T b) {//模板函数
		return a > b ? a : b;
	};//代码在编译时需要知道模板确认的定义（即引用什么具体的类型），因此模糊参数化的模板函数不能放在.cpp中，建议放在.h中
}
	template<class T1,class T2>
	class Point_T {//模板类
	public:
		T1 a;
		T2 b;
		Point_T() :a(0), b(0) {};
		Point_T(T1 ta, T2 tb) :a(ta), b(tb) {};
		Point_T<T1, T2>& operator=(Point_T<T1, T2> pt) {
			this->a = pt.a;
			this->b = pt.b;
			return *this;
		};
		friend Point_T<T1, T2>& operator +(Point_T<T1, T2>& pt1, Point_T<T1, T2>& pt2) {
			Point_T<T1, T2> temp;
			temp.a = pt1.a + pt2.a;
			temp.b = pt1.b + pt2.b;
			return temp;
		};
	};

	//Chapter9 Sort
	template<class T>
	void insertSort(T a[], int n) {
		int i, j;
		T temp;
		for (i = 1;i < n;i++) {
			temp = a[i];
			for (j = i - 1;j >= 0;j--) {
				if (temp < a[j]) {
					a[j + 1] = a[j];//默认从a[j+1]取数放入temp，相当于整个数列后面有一个空位置，在找到位置后将temp放入即可
				}
				else {
					break;
				}
			}
			a[j + 1] = temp;//在小于temp的最大值后面插入temp
		}
	}

	template<class T>
	void shellSort(T a[], int n) {
		int h, i, j;
		T temp;
		for (h = n / 2;h > 0;h = h / 2) {//h为分组数量，比较是每组相同位置的数进行比较和排序,最后直到每个组只剩一个元素（再进行排序后）为止
			for (i = h;i < n;i++) {
				temp = a[i];
				for (j = i - h;j >= 0 && temp < a[j];j -= h) {
					a[j + h] = a[j];
				}
				a[j + h] = temp;
			}
		}
	}
	template<class T>
	void bubbleSort(T a[],int n) {
		int i, j, exchange = 0;
		T temp;
		for (i = 0;i < n;i++) {
			exchange = 0;
			for (j = n-1 ;j > i;j--) {
				if (a[j-1] > a[j]) {
					temp = a[j-1];
					a[j-1] = a[j];
					a[j] = temp;
					exchange = 1;
				}
			}
			if (!exchange)
				return;//如果进行一次bubble遍历没有发生交换，则说明数组已经排序完毕
		}

	}

	template<class T>
	void quickSort(T a[],int low,int high) {
		int i, j;
		T pivot;
		T temp;
		if (low < high) {//递归结束条件，基准点的左右区间为0
			pivot = a[low];
			i = low;
			j = high;
			while (i<j) {
				while (i < j && a[j] >= pivot)//
					j--;
				if (i < j)
					a[i++] = a[j];//a[0]的数据缓存到pivot变量中，接下来将小于a[0]的数字从末尾提到a[0]处
				while (i<j && a[i] <= pivot)//“=”为了保证将pivot==pivot考虑进去
					i++;
				if (i < j)//保证最后一次i++不会超过j
					a[j--] = a[i];//将大于pivot的数字从队前半部分提到a[j]处，此处的值已经被提到前面了
				
			}
			a[i] = pivot;//其实i==j
			quickSort(a, low, i - 1);//左区间迭代
			quickSort(a, i + 1, high);//右区间迭代
		}
	}

	template<class T>
	void selectSort(T a[], int n) {
		int i, j, k;
		T temp;
		for (i = 0;i < n;i++) {
			temp = a[i];
			k = i;//每次搜索最小值前，将k初始化
			for (j = i;j < n;j++) {
				if (temp > a[j]) {
					temp = a[j];
					k = j;
				}
			}
			a[k] = a[i];
			a[i] = temp;
		}
	}

	static int heapSize = 0;//static声明将全局变量声明为当前文件的全局变量，以防止多文件链接到同一个全局变量
	int Left(int index);
	int Right(int index);


	template<class T>
	void swap(T* a, T* b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}

	template<class T>
	void maxHeapify(T a[], int index) {
		int Largest = 0;//最大数
		int left = Left(index);//左子节点索引
		int right = Right(index);//右子节点索引

		//将largest赋值为堆顶与其左子节点的较大者
		if ((left <= heapSize) && (a[left] > a[index]))
			Largest = left;
		else
			Largest = index;
		//取largest与堆顶右子节点的较大者
		if ((right <= heapSize) && (a[right] > a[Largest]))
			Largest = right;
		if (Largest != index) {
			swap(&a[Largest], &a[index]);
			maxHeapify(a, Largest);
		}
	}

	template<class T>
	void buildMaxHeap(T a[], int n) {
		int i;
		heapSize = n;
		for (i = (n >> 1);i >= 0;i--)
			maxHeapify(a, i);
	}

	template<class T>
	void heapSort(T a[], int n) {
		int i;
		buildMaxHeap(a, (n - 1));
		for (i = (n - 1);i >= 1;i--) {
			swap(&a[0], &a[i]);
			heapSize--;
			maxHeapify(a, 0);
		}
	}

	//归并排序
	//将数组从中间分裂，并进行左右递归分裂，直到某一端的区间长度为1
	//依次从其左右两端进行比较，标号同步增加（左端增加）减小（右端减小）
	//比较完成后，将两端数据合并成一组数据
	//合并过程调用左右比较过程
	template<class T>
	void Merge(T a[], T tmp[], int lpos, int rpos, int rEnd) {
		int i, lEnd, NumElements, tmpPos;
		lEnd = rpos - 1;
		tmpPos = lpos;
		NumElements = rEnd - lpos + 1;

		while (lpos <= lEnd && rpos <= rEnd) {
			if (a[lpos] < a[rpos])//在tmp中大值在前，小值在后
				tmp[tmpPos++] = a[lpos++];
			else
				tmp[tmpPos++] = a[rpos++];
		}
		while (lpos <= lEnd)
			tmp[tmpPos++] = a[lpos++];
		while (rpos <= rEnd)
			tmp[tmpPos++] = a[rpos++];

		for (i = 0;i < NumElements;i++, rEnd--)
			a[rEnd] = tmp[rEnd];//倒序赋值
	}

	template<class T>
	void msort(T a[], T tmp[], int low, int high) {
		if (low >= high)
			return;//递归结束条件

		int middle = (low + high) / 2;
		msort(a, tmp, low, middle);
		msort(a, tmp, middle + 1, high);
		Merge(a, tmp, low, middle + 1, high);
	}
	
	template<class T>
	void mergeSort(T a[], int n) {
		//top->down
		T* tmp = NULL;
		tmp = new T[n];
		if (tmp != NULL) {
			msort(a, tmp, 0, n - 1);
			delete []tmp;
		}
	}

	template<class T>
	void print_array(T a[], int len) {
		int i;
		for (i = 0;i < len;i++) {
			cout << a[i] << " ";
			}
		cout << endl;
	}




#endif