// LinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// List nodeclass
class Node {
public:
	Node(double);	//constructor
	double data;	//data item
	Node* next;		//pointer to next node
};

Node::Node(double value) {
	data = value;
	next = NULL;
}

// Linked list class
class LinkedList {
public:
	LinkedList() { head = NULL; };
	LinkedList(const LinkedList &);
    ~LinkedList() {}
    void addNode(double);
	void print();
	void reverse();

	//Operator functions
	LinkedList operator+(LinkedList&); //joins two linked lists
	const LinkedList &operator=(const LinkedList &);

private:
    Node* head;
};

LinkedList::LinkedList(const LinkedList &inList) {
	Node* temp = inList.head;
	while (temp != NULL) {
		this->addNode(temp->data);
		temp = temp->next;
	}
}

void LinkedList::addNode(double value) {
	Node* temp = new Node(value);
	if (head == NULL)
		head = temp;
	else {
		Node* temp1 = head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = temp;
	}
}

void LinkedList::print() {
	Node* temp;
	temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

void LinkedList::reverse() {
	Node* n1 = head;
	Node* n2 = NULL;
	Node* n3 = NULL;

	while (n1 != NULL) {
		head = n1;
		n2 = n1->next;
		n1->next = n3;
		n3 = n1;
		n1 = n2;
	}
}

LinkedList LinkedList::operator+(LinkedList &inList) {
	LinkedList* first = new LinkedList(*this);
	LinkedList* second = new LinkedList(inList);
	Node* temp = first->head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = second->head;
	return *first;
}

// Test program 
int main() {    
	vector<int> vec;
	for (int i = 0; i < 5; ++i)
		vec.push_back(i);
	for (auto itr = vec.begin(); itr != vec.end(); ++itr) {
		cout << *itr;
	}
	return 0;
}

