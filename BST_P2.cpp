// Implementation file for BST
#include <iostream>
#include <stdexcept>
#include "BST_P2.h"


BST::BST() {
length = 0;
root = nullptr;
}


void BST::InsertBST(BoardGame*& curnode, BoardGame newitem) { //Helper function to insert an item into (sub-)tree denoted by curnode
	if (curnode == nullptr) {
		curnode = new BoardGame(newitem.name, newitem.year, newitem.time, newitem.rating);
		curnode->right = nullptr;
		curnode->left = nullptr;
	} else if (newitem.year < curnode->year) {
	    InsertBST(curnode->left, newitem);
	} else {
		InsertBST(curnode->right, newitem);
	}
}


void BST::AfterYear(BoardGame* node, int targetYear) {
	if (node != nullptr) {
		AfterYear(node->left, targetYear);
		if (node->year >= targetYear) {
			std::cout << "Name: " << node->name << ", Year: " << node->year << ", Play Time " << node->time << ", Users Rated: " << node->rating << std::endl;
		}
		AfterYear(node->right, targetYear);
	}
}

void BST::AfterYear(int targetYear) {
	AfterYear(root, targetYear);
}

BoardGame*& BST::GetRoot() {
	return root;
}

//In order traversal
void BST::PrintAll(BoardGame* node) {
	if (node != nullptr) {
		PrintAll(node->left);
		std::cout << "Name: " << node->name << ", Year: " << node->year << ", Play Time " << node->time << ", Users Rated: " << node->rating << std::endl;
		PrintAll(node->right);
	}
}

void BST::PrintAll() {
	PrintAll(root);
}