#pragma once

class btree {
public:
	btree();
	~btree();
	void insert(int val);
	void print();
	bool search(int val);
	void destroy_tree() { destroy_tree(root); root = NULL; };
private:
	class node {
	public:
		node(int val);
		~node();
		int data;
		node* left;
		node* right;
	};
	node* root;
	void insert(int val, node *leaf);
	void print(node *leaf);
	void destroy_tree(node *leaf);
	bool search(int val, node *leaf);
};