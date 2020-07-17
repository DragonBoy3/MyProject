#ifndef _chapter8_H_
#define _chapter8_H_
using namespace std;

namespace lgd {
	typedef struct node {
		int data;//�ڵ�����
		node* next;//��һ���ڵ��ָ��
	}node;

	node* create();
	int len(node* list);
	node* search_node(node* head, int pos);
	node* insert_node(node* head, int pos, int data);
	node* delete_node(node* head, int pos);
	void printlist(node* head);
	node* reverse_list(node* head);
	node* search_mid(node* head);
	node* sort_increase(void);
	node* MergeRecursive(node* head1, node* head2);

	typedef struct DbNode {//˫������
		int data;
		DbNode* left;
		DbNode* right;
	}DbNode;

	//���е�ͷ��ָ�������ͷ�������е�β��ָ������ĩβ�����ڶ����ڵ�
	//MyQueue->rear->next = NULL
	typedef struct _Queue {//����Ķ���
		node* front;
		node* rear;
	}MyQueue;

	MyQueue* CreateMyQueue();//�����ն���
	MyQueue* enqueue(MyQueue* q, int data);//���
	MyQueue* dequeue(MyQueue* q);//����
	int GetLength(MyQueue* q);//�ⳤ
	void PrintMyQueue(MyQueue* q);//��ӡ

	//ջ
	class MyData {
	public:
		MyData();
		MyData(int data);
		int data;
		MyData* next;
	};
	class MyStack {
	public:
		MyStack();
		void push(MyData data);//ѹ�뵥���ڵ㣬����ʵ��
		void pop(MyData* pData);//pop�����һ���ڵ㣬����ջ��ָ��
		bool IsEmpty();
		MyData* top;
	};

	class BSTNode {
	public:
		int data;
		int tag;
		BSTNode* parent;
		BSTNode* leftchild;
		BSTNode* rightchild;
		BSTNode();
		BSTNode(int num);
	};

	class Tree {
		BSTNode* root;
		void insertNode(BSTNode* current, int data);//�ݹ鷽������ڵ�
		void deleteNode(BSTNode* current);//�ݹ鷽��ɾ���ڵ㼰������
		BSTNode* searchNode(BSTNode* current, int data);//�ݹ鷽��Ѱ�ҽڵ�
		void InOrderTree(BSTNode* current);
		void PreOrderTree(BSTNode* current);
		void PostOrderTree(BSTNode* current);
	public:
		Tree(int num[], int len);
		void insertNode1(int data);//�ݹ鷽������ڵ�
		void insertNode(int data);//�ǵݹ鷽������ڵ�
		void deleteNode(int data);//ɾ���ڵ㼰������
		BSTNode* searchNode(int data);
		void InOrderTree();//������������������ǿգ����ȱ��������������ʸ��ڵ㣬�ٱ���������
		void InOrderTreeUnRec();
		void PreOrderTree();
		void PreOrderTreeUnRec();
		void PostOrderTree();
		void PostOrderTreeUnRec();
	};


	
	
}

namespace puddingleos {
	typedef struct node{
		int data;
		node* next;
	}node;
}



#endif // !_chapter8_H_
