#include "stdafx.h"
#include "Queue.h"
#include <iostream>
Queue::Queue() {
	head = NULL;
	size = 0;
}
void Queue::push(int val) {
	if (head == NULL)
		head = new Node(val);
	else
		push(val, head);
}
void Queue::push(int val, Node* pos) {
	if (pos->next == NULL)
		pos->next = new Node(val);
	else
		push(val, pos->next);
}
int Queue::pop() {
	Node *temp = head;
	int temp1 = head->data;
	head = head->next;
	delete temp;
	return temp1;
}
void Queue::print() {
	print(head);
	std::cout << std::endl;
}
void Queue::print(Node *pos) {
	if (pos != NULL) {
		std::cout << pos->data << " ";
		print(pos->next);
	}
}
Queue::Node::Node(int val) {
	data = val;
	next = NULL;
}
Queue::Node::~Node() {
	data = NULL;
	next = NULL;
}
