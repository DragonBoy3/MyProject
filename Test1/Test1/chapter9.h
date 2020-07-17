#ifndef _chapter9_H_
#define _chapter9_H_
#include<iostream>
//#include "stdafx.h"
using namespace std;

namespace lgd {
	template <class T>
	T max(T a, T b) {//ģ�庯��
		return a > b ? a : b;
	};//�����ڱ���ʱ��Ҫ֪��ģ��ȷ�ϵĶ��壨������ʲô��������ͣ������ģ����������ģ�庯�����ܷ���.cpp�У��������.h��
}
	template<class T1,class T2>
	class Point_T {//ģ����
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
					a[j + 1] = a[j];//Ĭ�ϴ�a[j+1]ȡ������temp���൱���������к�����һ����λ�ã����ҵ�λ�ú�temp���뼴��
				}
				else {
					break;
				}
			}
			a[j + 1] = temp;//��С��temp�����ֵ�������temp
		}
	}

	template<class T>
	void shellSort(T a[], int n) {
		int h, i, j;
		T temp;
		for (h = n / 2;h > 0;h = h / 2) {//hΪ�����������Ƚ���ÿ����ͬλ�õ������бȽϺ�����,���ֱ��ÿ����ֻʣһ��Ԫ�أ��ٽ��������Ϊֹ
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
				return;//�������һ��bubble����û�з�����������˵�������Ѿ��������
		}

	}

	template<class T>
	void quickSort(T a[],int low,int high) {
		int i, j;
		T pivot;
		T temp;
		if (low < high) {//�ݹ������������׼�����������Ϊ0
			pivot = a[low];
			i = low;
			j = high;
			while (i<j) {
				while (i < j && a[j] >= pivot)//
					j--;
				if (i < j)
					a[i++] = a[j];//a[0]�����ݻ��浽pivot�����У���������С��a[0]�����ִ�ĩβ�ᵽa[0]��
				while (i<j && a[i] <= pivot)//��=��Ϊ�˱�֤��pivot==pivot���ǽ�ȥ
					i++;
				if (i < j)//��֤���һ��i++���ᳬ��j
					a[j--] = a[i];//������pivot�����ִӶ�ǰ�벿���ᵽa[j]�����˴���ֵ�Ѿ����ᵽǰ����
				
			}
			a[i] = pivot;//��ʵi==j
			quickSort(a, low, i - 1);//���������
			quickSort(a, i + 1, high);//���������
		}
	}

	template<class T>
	void selectSort(T a[], int n) {
		int i, j, k;
		T temp;
		for (i = 0;i < n;i++) {
			temp = a[i];
			k = i;//ÿ��������Сֵǰ����k��ʼ��
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

	static int heapSize = 0;//static������ȫ�ֱ�������Ϊ��ǰ�ļ���ȫ�ֱ������Է�ֹ���ļ����ӵ�ͬһ��ȫ�ֱ���
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
		int Largest = 0;//�����
		int left = Left(index);//���ӽڵ�����
		int right = Right(index);//���ӽڵ�����

		//��largest��ֵΪ�Ѷ��������ӽڵ�Ľϴ���
		if ((left <= heapSize) && (a[left] > a[index]))
			Largest = left;
		else
			Largest = index;
		//ȡlargest��Ѷ����ӽڵ�Ľϴ���
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

	//�鲢����
	//��������м���ѣ����������ҵݹ���ѣ�ֱ��ĳһ�˵����䳤��Ϊ1
	//���δ����������˽��бȽϣ����ͬ�����ӣ�������ӣ���С���Ҷ˼�С��
	//�Ƚ���ɺ󣬽��������ݺϲ���һ������
	//�ϲ����̵������ұȽϹ���
	template<class T>
	void Merge(T a[], T tmp[], int lpos, int rpos, int rEnd) {
		int i, lEnd, NumElements, tmpPos;
		lEnd = rpos - 1;
		tmpPos = lpos;
		NumElements = rEnd - lpos + 1;

		while (lpos <= lEnd && rpos <= rEnd) {
			if (a[lpos] < a[rpos])//��tmp�д�ֵ��ǰ��Сֵ�ں�
				tmp[tmpPos++] = a[lpos++];
			else
				tmp[tmpPos++] = a[rpos++];
		}
		while (lpos <= lEnd)
			tmp[tmpPos++] = a[lpos++];
		while (rpos <= rEnd)
			tmp[tmpPos++] = a[rpos++];

		for (i = 0;i < NumElements;i++, rEnd--)
			a[rEnd] = tmp[rEnd];//����ֵ
	}

	template<class T>
	void msort(T a[], T tmp[], int low, int high) {
		if (low >= high)
			return;//�ݹ��������

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