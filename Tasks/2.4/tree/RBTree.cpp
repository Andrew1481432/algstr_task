#include <queue>
#include <cmath>
#include "RBTree.h"
#include "../../../Utils/Utils.h"

using namespace Utils;

namespace fourth2Task {

	RBTree::RBTree() {
		this->nil = new RBNode("nil");
		this->nil->parent = nil;
		this->nil->left = nil;
		this->nil->right = nil;
		root = nil;
	}

	int RBTree::getHeight() {
		return 2*log2(size+1);
	}

	void RBTree::InsertNode(RBNode* node) {
		node->parent = nil;
		node->left = nil;
		node->right = nil;

		RBNode* tmp = root;
		if(root == nil) {
			root = node;
		} else {
			node->color = true;
			bool running = true;
			while(running) {
				if(node->name > tmp->name) {
					if(tmp->right != nil) {
						tmp = tmp->right;
					} else {
						node->parent = tmp;
						tmp->right = node;
						running = false;
					}
				} else {
					if(tmp->left != nil) {
						tmp = tmp->left;
					} else {
						node->parent = tmp;
						tmp->left = node;
						running = false;
					}
				}
			}
		}
		fixUp(node);
		size++;
	}

	void RBTree::fixUp(RBNode *node) {
		while (node->parent->color) {
			RBNode *uncle = nil;
			if (node->parent == node->parent->parent->left) {
				uncle = node->parent->parent->right;
				if (uncle != nil && uncle->color) {  //Первый случай: перекрашиваем и ползем вверх
					node->parent->color = false;
					uncle->color = false;

					node->parent->parent->color = true;
					node = node->parent->parent;
					continue;
				}

				if (node == node->parent->right) {  //Второй случай
					node = node->parent;
					leftRotate(node);
				}

				node->parent->color = false;  //Переход к третьему случаю
				node->parent->parent->color = true;
				rightRotate(node->parent->parent);
			} else {  //Здесь те же случаи, но симметрично
				uncle = node->parent->parent->left;
				if (uncle != nil && uncle->color) {
					node->parent->color = false;
					uncle->color = false;
					node->parent->parent->color = true;
					node = node->parent->parent;
					continue;
				}

				if (node == node->parent->left) {
					node = node->parent;
					rightRotate(node);
				}

				node->parent->color = false;
				node->parent->parent->color = true;
				leftRotate(node->parent->parent);
			}
		}
	}

	void RBTree::leftRotate(RBNode *node) {
		if (node->parent == nil) {
			RBNode *right = root->right;
			root->right = right->left;
			right->left->parent = root;
			root->parent = right;

			right->left = root;
			right->parent = nil;
			root = right;
		} else {
			if (node->parent->left == node) {
				node->parent->left = node->right;
			} else {
				node->parent->right = node->right;
			}
			node->right->parent = node->parent;
			node->parent = node->right;
			if (node->right->left != nil)
				node->right->left->parent = node;
			node->right = node->right->left;
			node->parent->left = node;
		}
	}

	void RBTree::rightRotate(RBNode *node) {
		if (node->parent == nil) {
			RBNode *left = root->left;
			root->left = root->left->right;
			if(left->right != nil) {
				left->right->parent = root;
			}
			root->parent = left;
			left->right = root;
			left->parent = nil;

			root = left;
		} else {
			if (node->parent->left == node) {
				node->parent->left = node->left;
			} else {
				node->parent->right = node->left;
			}
			node->left->parent = node->parent;
			node->parent = node->left;
			if (node->left->right != nil)
				node->left->right->parent = node;
			node->left = node->left->right;
			node->parent->right = node;
		}
	}

	void RBTree::symmetry(RBNode *node) {
		if (root == nil) {
			cout << "Создаейте вначале дерево!\n";
			return;
		}
		if (node != nil) {
			symmetry(node->left);
			cout << node->name << " ";
			symmetry(node->right);
		}
	}

	void RBTree::symmetry() {
		this->symmetry(root);
	}

	void RBTree::width() {
		if (root == nil) {
			cout << "Создаейте вначале дерево!\n";
			return;
		}
		std::deque<RBNode*> q;
		q.push_back(root);
		while (q.size() != 0) {
			RBNode* next = q.front();
			q.pop_front();
			cout << next->name << ' ';

			if (next->left != nil) q.push_back(next->left);
			if (next->right != nil) q.push_back(next->right);
		}
	}

	void RBTree::print(RBNode* node, int tabs) {
		if (node == nil) {
			return;
		}

		string color = "";
		if(node->color) { // красный
			color = Utils::getColor(foreGroundColor::RED);
		} else {
			color = Utils::getColor(foreGroundColor::BLACK);
		}

		cout << color << node->name << Utils::getColor(foreGroundColor::COLOR_RESET) << "; Родитель: " << (node->parent != nil ? node->parent->name : "NILL") << endl;
		print(node->left, 0);
		print(node->right, 0);
	}

	void RBTree::printTest(RBNode *node, int tabs) {
		if (node == nil) {
			return;
		}

		string color = "";
		this->printTest(node->left, ++tabs);
		for (int i = 0; i < tabs; ++i) {
			cout << "   ";
		}

		if(node->color) { // красный
			color = Utils::getColor(foreGroundColor::RED);
		} else {
			color = Utils::getColor(foreGroundColor::BLACK);
		}

		cout << color << node->name << Utils::getColor(foreGroundColor::COLOR_RESET) << endl;

		tabs--;
		this->printTest(node->right, ++tabs);
	}

	void RBTree::print() {
		this->print(root, 0);

		this->printTest(root, 0);
	}

}