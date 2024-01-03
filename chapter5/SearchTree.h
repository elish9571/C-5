#pragma once
#include "Tree.h"
#include <iostream>
using namespace std;

template<class T>
class SearchTree : public Tree<T>
{

public:
	void add(T value) override;
	bool search(T value) override;
	void remove(T value) override;

private:
	void add(typename Tree<T>::Node* current, T val);
	bool search(typename Tree<T>::Node* current, T val);
	//help functions for remove
	void removeLeaf(typename Tree<T>::Node* current);
	void removeWith2Children(typename Tree<T>::Node* current);
	void removeWith1Child(typename Tree<T>::Node* current);
};

template <class T>
void SearchTree<T>::add(T val)
{
	// add value to binary search tree 
	if (!Tree<T>::root)
	{
		Tree<T>::root = new typename Tree<T>::Node(val);
		return;
	}
	add(Tree<T>::root, val);
}

template <class T>
void SearchTree<T>::add(typename Tree<T>::Node* current, T val)
{
	if (current->value < val)

		if (!current->right)
		{
			current->right = new typename Tree<T>::Node(val);
			current->right->parent = current;
			return;
		}
		else add(current->right, val);
	else

		if (!current->left)
		{
			current->left = new  typename Tree<T>::Node(val);
			current->left->parent = current;
			return;
		}
		else add(current->left, val);
}

template <class T>
bool SearchTree<T>::search(T value)
{
	return search(Tree<T>::root, value);
}
template <class T>
bool SearchTree<T>::search(typename Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false;	// not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}
template <class T>
void SearchTree<T>::removeLeaf(typename Tree<T>::Node* n) {
	if (n->parent == nullptr)
	{
		delete n;
		Tree<T> ::root = nullptr;
	}
	else
	{
		if (n->parent->left == n)
			n->parent->left = nullptr;
		else
			n->parent->right = nullptr;
		delete n;
	}
}
template <class T>
void SearchTree<T>::removeWith1Child(typename Tree<T>::Node* n) {

	typename Tree<T>::Node* child;
	if (n->left == nullptr)
		child = n->right;
	else
		child = n->left;

	if (n->parent == nullptr)
	{
		Tree<T>::root = child;
		child->parent = nullptr;
	}
	else
	{
		if (n->parent->left == n)
			n->parent->left = child;
		else
			n->parent->right = child;
		child->parent = n->parent;

	}
	delete n;
}
template <class T>
void SearchTree<T>::removeWith2Children(typename Tree<T>::Node* n) {

	typename Tree<T>::Node* following = n->right;
	while (following->left != nullptr)
		following = following->left;

	n->value = following->value;

	if (following->parent->left == n)
		following->parent->left = following->right;
	else
		following->parent->right = following->right;
	
	if (following->right != nullptr)
		following->right->parent = following->parent;

	delete following;
}
template <class T>
void SearchTree<T>::remove(T val)
{
	typename Tree<T> ::Node* n = Tree<T>::root;
	while (n != nullptr && n->value != val) {
		if (val < n->value)
			n = n->left;
		else
			n = n->right;
	}
	//n not exist
	if (n == nullptr)
		return;
	//n is a leaf
	if (n->left == nullptr && n->right == nullptr)
		removeLeaf(n);
	//n has 1 child
	else if (n->left == nullptr || n->right == nullptr)
		removeWith1Child(n);
	//n has 2 children
	else
		removeWith2Children(n);
}
