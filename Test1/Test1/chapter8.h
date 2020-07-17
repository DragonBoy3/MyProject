#ifndef _chapter8_H_
#define _chapter8_H_
using namespace std;

namespace lgd {
	typedef struct node {
		int data;//节点内容
		node* next;//下一个节点的指针
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

	typedef struct DbNode {//双向链表
		int data;
		DbNode* left;
		DbNode* right;
	}DbNode;

	//队列的头部指向单链表的头部，队列的尾部指向单链表末尾倒数第二个节点
	//MyQueue->rear->next = NULL
	typedef struct _Queue {//链表的队列
		node* front;
		node* rear;
	}MyQueue;

	MyQueue* CreateMyQueue();//创建空队列
	MyQueue* enqueue(MyQueue* q, int data);//入队
	MyQueue* dequeue(MyQueue* q);//出队
	int GetLength(MyQueue* q);//测长
	void PrintMyQueue(MyQueue* q);//打印

	//栈
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
		void push(MyData data);//压入单个节点，传入实参
		void pop(MyData* pData);//pop出最后一个节点，传入栈顶指针
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
		void insertNode(BSTNode* current, int data);//递归方法插入节点
		void deleteNode(BSTNode* current);//递归方法删除节点及其子树
		BSTNode* searchNode(BSTNode* current, int data);//递归方法寻找节点
		void InOrderTree(BSTNode* current);
		void PreOrderTree(BSTNode* current);
		void PostOrderTree(BSTNode* current);
	public:
		Tree(int num[], int len);
		void insertNode1(int data);//递归方法插入节点
		void insertNode(int data);//非递归方法插入节点
		void deleteNode(int data);//删除节点及其子树
		BSTNode* searchNode(int data);
		void InOrderTree();//中序遍历：若二叉树非空，则先遍历左子树，访问根节点，再遍历右子树
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
