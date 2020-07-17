#include <iostream>
#include "chapter8.h"


lgd::node* lgd::create() {
	int i = 0;
	node* head, * p, * q;
	int x = 0;
	head = (node*)malloc(sizeof(node));
	q = (node*)malloc(sizeof(node));
	while (1) {
		cout << "Please input the data:"  << endl;
		cin >> x;
		if (x == 0)
			break;
		p = (node*)malloc(sizeof(node));
		p->data = x;
		if (++i == 1)
			head->next = p;
		else
			q->next = p;
		q = p;//q指向末节点
	}
	q->next = NULL;
	return head;
}

int lgd::len(lgd::node* list) {
	int i = 0;
	node* p = list;
	while (p->next != NULL) {
		i++;
		p = p->next;
	}
	return i;
}

lgd::node* lgd::search_node(node* list, int pos) {
	int i;
	if (pos < 0) {
		cout << "incorrect position to search node!" << endl;
		return NULL;
	}
	if (pos == 0)
		return list;
	i = 0;
	node* p = list->next;
	if (p == NULL) {
		cout << "Link is empty." << endl;
		return NULL;
	}
	while (pos--) {
		if ((p = p->next) == NULL) {
			cout << "search position exceed the length of list." << endl;
			break;
		}
	}
	return p;
}

lgd::node* lgd::insert_node(node* head, int pos, int data) {
	node* item = NULL;
	item = (node*)malloc(sizeof(node));
	item->data = data;
	if (pos == 0) {
		head->next = item;
		return head;
	}
	node* p = lgd::search_node(head, pos);
	if (p != NULL) {
		item->next = p->next;
		p->next = item;
	}
	return head;
}

lgd::node* lgd::delete_node(node* head, int pos) {
	node* p = head->next;
	if (p == NULL) {
		cout << "List is empty!" << endl;
		return NULL;
	}
	p = lgd::search_node(head, pos - 1);
	if (p != NULL || p->next != NULL) {
		p->next = (p->next)->next;
	}
	return head;
}
void lgd::printlist(lgd::node* head) {
	int i=0;
	if (head->next == NULL) {
		cout << "List is empty!" << endl;
	}
	node* p = head;
	while (p->next != NULL) {
		cout << "The " << i++ << "dth node is:" << p->data << endl;
		p = p->next;
	}
}
lgd::node* lgd::reverse_list(node* head) {
	if (head->next == NULL)
		return head;
	node* p, * q, * r;//设置用于交换的node
	p = head->next;
	q = p->next;//保存第二个节点
	p->next = NULL;//原第一个节点指向NULL（末尾）
	while (q != NULL) {
		r = q->next;//缓存下一个节点
		q->next = p;//将本节点next指针指向上一个节点
		p = q;//更新当前节点
		q = r;//更新下一个节点
	}
	head->next = p;//head指向不为NULL的最后一个节点（原链表的末尾）
	return head;
}
lgd::node* lgd::search_mid(node* head) {
	int i = 0;
	int j = 0;
	node* current = NULL;
	node* middle = NULL;
	current = middle = head->next;
	while (current != NULL) {
		if ( i / 2>j) {
			j++;
			middle = middle->next;
		}
		i++;
		current = current->next;
	}
	return middle;
}

lgd::node* lgd::sort_increase(void) {
	int data = 0;
	struct node* head = NULL, * New, * Cur, * Pre;
	while (1) {
		cout << "Please input the data:" << endl;
		cin >> data;
		if (data == 0)
			break;
		New = (struct node*)malloc(sizeof(struct node));
		Pre = (struct node*)malloc(sizeof(struct node));
		New->data = data;
		New->next = NULL;
		if (head == NULL) {
			head = New;
			continue;
		}
		if (New->data <= head->data) {
			New->next = head;//在链的末尾前插入节点
			head = New;
			continue;
		}
		Cur = head;
		while (Cur->next != NULL && New->data > Cur->data) {
			//从链表头部开始寻找第一个大于data的节点
			//没有找到则将下一个节点传给Cur，保留上一个节点位置用于插入新的node
			Pre = Cur;
			Cur = Cur->next;
		}
		if (Cur->data >= New->data) {
			Pre->next = New;
			New->next = Cur;
		}
		else
			//没有找到比输入data更大的节点，遍历到链表末尾
			Cur->next = New;
	}
	return head;
}
lgd::node* lgd::MergeRecursive(node* head1, node* head2) {
	node* head = NULL;
	if (head1 == NULL) {
		return head2;
	}
	if (head2 == NULL) {
		return head1;
	}
	if (head1->data >= head2->data) {
		head = head2;
		head->next = MergeRecursive(head1, head2->next);
	}else{
		head = head1;
		head->next = MergeRecursive(head1->next, head2);
	}
	return head;
}

lgd::MyQueue* lgd::CreateMyQueue() {
	MyQueue* q;
	q = (MyQueue*)malloc(sizeof(MyQueue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

lgd::MyQueue* lgd::enqueue(MyQueue* q, int data) {
	node* NewNode = NULL;
	NewNode = (node*)malloc(sizeof(node));
	NewNode->data = data;
	NewNode->next = NULL;
	if (q->rear == NULL) {//队列为空，则新节点既是队首又是队尾
		q->front = q->rear = NewNode;
	}
	else {
		q->rear->next = NewNode;
		q->rear = NewNode;
	}
	return q;
}

lgd::MyQueue* lgd::dequeue(MyQueue* q) {
	node* pnode = NULL;
	pnode = q->front;
	if (pnode == NULL) {
		cout << "Empty Queue!" << endl;
	}
	else {
		q->front = q->front->next;//队列的front指向链表下一个位置，队列首位置是待删除的节点
		if (q->front == NULL) {
			q->rear = NULL;//队列中只剩一个点时，对队列的front和rear同时赋值NULL
		}
		free(pnode);
	}
	return q;
}

int lgd::GetLength(MyQueue* q) {
	int nlen = 0;
	node* pnode = NULL;
	pnode = q->front;
	if (pnode == NULL) {
		return nlen;
	}
	while (pnode != q->rear) {
		nlen++;
		pnode = pnode->next;
	}
	return nlen;
}

void lgd::PrintMyQueue(MyQueue* q) {
	node* pnode = NULL;
	pnode = q->front;
	if (pnode == NULL) {
		cout << "Empty Queue" << endl;
	}
	else {
		while (pnode != q->rear) {
			cout << pnode->data << endl;
			pnode = pnode->next;
		}
		cout << pnode->data << endl;//打印队列末尾
	}
}

lgd::MyData::MyData() :data(0), next(NULL) {};
lgd::MyData::MyData(int value) :data(value), next(NULL) {};
lgd::MyStack::MyStack() :top(NULL) {};
void lgd::MyStack::push(MyData data) {
	MyData* pData = NULL;
	pData = new MyData(data.data);//利用MyData的带参构造函数生成新的节点
	pData->next = top;
	top = pData;
}
void lgd::MyStack::pop(MyData* pdata) {
	if (IsEmpty()) {
		return;
	}
		pdata->data = top->data;//将栈顶的值传出
		MyData* p = top;
		top = top->next;//栈的next指向栈顶下一层
		delete p;//释放原栈顶的内存
}

bool lgd::MyStack::IsEmpty() {
	return (top == NULL);
}

lgd::BSTNode::BSTNode() :data(-1), tag(0), parent(NULL), leftchild(NULL), rightchild(NULL) {};
lgd::BSTNode::BSTNode(int num) :data(num), tag(0), parent(NULL), leftchild(NULL), rightchild(NULL) {};

lgd::Tree::Tree(int num[], int len) {
	root = new BSTNode(num[0]);//私有成员root初始化
	for (int i = 1;i < len;i++) {
		//lgd::Tree::insertNode(num[i]);//调用public函数非递归插入节点
		lgd::Tree::insertNode1(num[i]);//调用public函数递归插入节点
	}
}

void lgd::Tree::insertNode(int data) {
	lgd::BSTNode* p, * par;
	lgd::BSTNode* newNode = new BSTNode(data);

	p = par = root;//私有成员允许被内部成员函数调用
	while (p != NULL) {
		par = p;//保存节点
		if (p->data > data) {
			p = p->leftchild;
		}
		else if (p->data < data) {
			p = p->rightchild;
		}
		else if (p->data == data) {
			delete newNode;
			return;
		}
	}
	newNode->parent = par;
	if (par->data > newNode->data) {
		par->leftchild = newNode;
	}
	else {
		par->rightchild = newNode;
	}

}

void lgd::Tree::insertNode1(int data) {
	if (root != NULL) {
		insertNode(root, data);
	}
}

void lgd::Tree::insertNode(lgd::BSTNode* current, int data) {//递归函数
	if (data < current->data) {
		if (current->leftchild == NULL) {
			current->leftchild = new BSTNode(data);
			current->leftchild->parent = current;
		}
		else {
			insertNode(current->leftchild, data);
		}
	}
	else if (data > current->data) {
		if (current->rightchild == NULL) {
			current->rightchild = new BSTNode(data);
			current->rightchild->parent = current;
		}
		else {
			insertNode(current->rightchild, data);
		}
	}
	return;
}
lgd::BSTNode* lgd::Tree::searchNode(int data) {
	if (root != NULL)
		return searchNode(root, data);
}//public成员函数
lgd::BSTNode* lgd::Tree::searchNode(BSTNode* current, int data) {
	if (data < current->data) {
		if (current->leftchild == NULL)
			return current->leftchild;
		else
			searchNode(current->leftchild, data);
	}
	else if (data > current->data) {
		if (current->rightchild == NULL)
			return current->rightchild;
		else
			searchNode(current->rightchild, data);
	}
	else
		return current;
}

void lgd::Tree::deleteNode(int data) {
	BSTNode* current = NULL;
	current = searchNode(root,data);
	if (current != NULL) {
		deleteNode(current);
	}
}

void lgd::Tree::deleteNode(lgd::BSTNode* current) {//递归方法
	if (current->leftchild != NULL) {
		deleteNode(current->leftchild);
	}
	if (current->rightchild != NULL)
		deleteNode(current->rightchild);

	if (current->parent == NULL) {
		delete current;
		root = NULL;
		return;//如果是根节点，则将根节点置空
	}
	if (current->parent->data > current->data)
		current->parent->leftchild = NULL;
	if (current->parent->data < current->data)
		current->parent->rightchild = NULL;

	delete current;

}

void lgd::Tree::InOrderTree() {
	if (root == NULL) {
		return;
	}
	InOrderTree(root);
}

void lgd::Tree::InOrderTree(BSTNode* current) {
	if (current != NULL) {
		InOrderTree(current->leftchild);
		cout << current->data << " ";//先遍历所有左边，在依次返回父节点，遍历右边
		InOrderTree(current->rightchild);
	}
}

void lgd::Tree::InOrderTreeUnRec() {
	MyStack s;
	MyData data;
	BSTNode* p = root;
	while (p != NULL || !s.IsEmpty()) {
		while (p != NULL) {
			s.push(p->data);
			p = p->leftchild;//将左子树的点压入栈
		}
		if (!s.IsEmpty()) {
			p = searchNode(s.top->data);
			s.pop(&data);
			cout << data.data << " ";
			p = p->rightchild;
		}
	}
}

void lgd::Tree::PreOrderTree() {
	if (root == NULL)
		return;
	PreOrderTree(root);
}

void lgd::Tree::PreOrderTree(BSTNode* current) {
	if (current != NULL) {
		cout << current->data << " ";//先打印当前节点值
		PreOrderTree(current->leftchild);//再依次遍历其左右子树
		PreOrderTree(current->rightchild);
	}
}

void lgd::Tree::PreOrderTreeUnRec() {
	MyStack s;
	MyData data;
	BSTNode* p;
	p = root;
	while (p != NULL || !s.IsEmpty()) {
		while (p != NULL) {
			cout << p->data << " ";
			s.push(p->data);
			p = p->leftchild;
		}
		if (!s.IsEmpty()) {
			p = searchNode(s.top->data);
			s.pop(&data);
			p = p->rightchild;
		}
	}
}

void lgd::Tree::PostOrderTree() {
	if (root != NULL)
		PostOrderTree(root);
	return;
}

void lgd::Tree::PostOrderTree(BSTNode* current) {
	if (current != NULL) {
		PostOrderTree(current->leftchild);
		PostOrderTree(current->rightchild);
		cout << current->data << " ";//遍历到底后返回时依次打印
	}
}

void lgd::Tree::PostOrderTreeUnRec() {
	MyStack s;
	MyData data;
	BSTNode* p;
	p = root;
	while (p != NULL || !s.IsEmpty()) {
		while (p != NULL) {
			s.push(p->data);
			p = p->leftchild;
		}
		if (!s.IsEmpty()) {
			p = searchNode(s.top->data);
			if (p->tag) {
				cout << p->data << " ";
				s.pop(&data);
				p = NULL;//当输出该节点时表明其左右子树均已经被遍历
			}
			else {
				p->tag = 1;//从树底往上遍历，能够保证子节点都会被遍历
				p = p->rightchild;
			}

		}
	}
}