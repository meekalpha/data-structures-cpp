#include "stdafx.h"
#include <iostream>
#include "binary_tree.h"

btree::btree() {
	root = NULL;
}
btree::~btree() {
	root = NULL;
}
btree::node::node(int val) {
	data = val;
	left = NULL;
	right = NULL;
}
btree::node::~node() {
	data = NULL;
	left = NULL;
	right = NULL;
}
void btree::insert(int val) {
	if (root == NULL)
		root = new node(val);
	else 
		insert(val, root);
}
void btree::insert(int val, node *leaf) {
	if (val < leaf->data)
		if (leaf->left == NULL)
			leaf->left = new node(val);
		else
			insert(val, leaf->left);
	else //if val is >= leaf
		if (leaf->right == NULL)
			leaf->right = new node(val);
		else
			insert(val, leaf->right);
}
void btree::print() {
	print(root);
}
void btree::print(node *leaf) {
	if (leaf != NULL) {
		std::cout << leaf->data << ' ';
		print(leaf->left);
		print(leaf->right);
	}
	else
		std::cout << std::endl;
}

void btree::destroy_tree(node *leaf) {
	if (leaf != NULL) {
		destroy_tree(leaf->left);
		destroy_tree(leaf->right);
		delete leaf;
	}
}

bool btree::search(int val) {
	return search(val, root);
}

bool btree::search(int val, node *leaf) {
	if (leaf == NULL)
		return false;
	else {
		if (val == leaf->data)
			return true;
		if (val < leaf->data)
			return search(val, leaf->left);
		else //if val >= leaf->data
			return search(val, leaf->right);
	}

}