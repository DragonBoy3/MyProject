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
		q = p;//qָ��ĩ�ڵ�
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
	node* p, * q, * r;//�������ڽ�����node
	p = head->next;
	q = p->next;//����ڶ����ڵ�
	p->next = NULL;//ԭ��һ���ڵ�ָ��NULL��ĩβ��
	while (q != NULL) {
		r = q->next;//������һ���ڵ�
		q->next = p;//�����ڵ�nextָ��ָ����һ���ڵ�
		p = q;//���µ�ǰ�ڵ�
		q = r;//������һ���ڵ�
	}
	head->next = p;//headָ��ΪNULL�����һ���ڵ㣨ԭ�����ĩβ��
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
			New->next = head;//������ĩβǰ����ڵ�
			head = New;
			continue;
		}
		Cur = head;
		while (Cur->next != NULL && New->data > Cur->data) {
			//������ͷ����ʼѰ�ҵ�һ������data�Ľڵ�
			//û���ҵ�����һ���ڵ㴫��Cur��������һ���ڵ�λ�����ڲ����µ�node
			Pre = Cur;
			Cur = Cur->next;
		}
		if (Cur->data >= New->data) {
			Pre->next = New;
			New->next = Cur;
		}
		else
			//û���ҵ�������data����Ľڵ㣬����������ĩβ
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
	if (q->rear == NULL) {//����Ϊ�գ����½ڵ���Ƕ������Ƕ�β
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
		q->front = q->front->next;//���е�frontָ��������һ��λ�ã�������λ���Ǵ�ɾ���Ľڵ�
		if (q->front == NULL) {
			q->rear = NULL;//������ֻʣһ����ʱ���Զ��е�front��rearͬʱ��ֵNULL
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
		cout << pnode->data << endl;//��ӡ����ĩβ
	}
}

lgd::MyData::MyData() :data(0), next(NULL) {};
lgd::MyData::MyData(int value) :data(value), next(NULL) {};
lgd::MyStack::MyStack() :top(NULL) {};
void lgd::MyStack::push(MyData data) {
	MyData* pData = NULL;
	pData = new MyData(data.data);//����MyData�Ĵ��ι��캯�������µĽڵ�
	pData->next = top;
	top = pData;
}
void lgd::MyStack::pop(MyData* pdata) {
	if (IsEmpty()) {
		return;
	}
		pdata->data = top->data;//��ջ����ֵ����
		MyData* p = top;
		top = top->next;//ջ��nextָ��ջ����һ��
		delete p;//�ͷ�ԭջ�����ڴ�
}

bool lgd::MyStack::IsEmpty() {
	return (top == NULL);
}

lgd::BSTNode::BSTNode() :data(-1), tag(0), parent(NULL), leftchild(NULL), rightchild(NULL) {};
lgd::BSTNode::BSTNode(int num) :data(num), tag(0), parent(NULL), leftchild(NULL), rightchild(NULL) {};

lgd::Tree::Tree(int num[], int len) {
	root = new BSTNode(num[0]);//˽�г�Աroot��ʼ��
	for (int i = 1;i < len;i++) {
		//lgd::Tree::insertNode(num[i]);//����public�����ǵݹ����ڵ�
		lgd::Tree::insertNode1(num[i]);//����public�����ݹ����ڵ�
	}
}

void lgd::Tree::insertNode(int data) {
	lgd::BSTNode* p, * par;
	lgd::BSTNode* newNode = new BSTNode(data);

	p = par = root;//˽�г�Ա�����ڲ���Ա��������
	while (p != NULL) {
		par = p;//����ڵ�
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

void lgd::Tree::insertNode(lgd::BSTNode* current, int data) {//�ݹ麯��
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
}//public��Ա����
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

void lgd::Tree::deleteNode(lgd::BSTNode* current) {//�ݹ鷽��
	if (current->leftchild != NULL) {
		deleteNode(current->leftchild);
	}
	if (current->rightchild != NULL)
		deleteNode(current->rightchild);

	if (current->parent == NULL) {
		delete current;
		root = NULL;
		return;//����Ǹ��ڵ㣬�򽫸��ڵ��ÿ�
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
		cout << current->data << " ";//�ȱ���������ߣ������η��ظ��ڵ㣬�����ұ�
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
			p = p->leftchild;//���������ĵ�ѹ��ջ
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
		cout << current->data << " ";//�ȴ�ӡ��ǰ�ڵ�ֵ
		PreOrderTree(current->leftchild);//�����α�������������
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
		cout << current->data << " ";//�������׺󷵻�ʱ���δ�ӡ
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
				p = NULL;//������ýڵ�ʱ�����������������Ѿ�������
			}
			else {
				p->tag = 1;//���������ϱ������ܹ���֤�ӽڵ㶼�ᱻ����
				p = p->rightchild;
			}

		}
	}
}