#include <iostream>
using namespace std;

struct tree {
	int key;
	tree* left;
	tree* right;
}*treel = NULL, * treer = NULL, * treen = NULL;

void add(int n, tree*& t);
void printNode(int n, int h);
void show(tree* t, int h);
void combine(tree*& t1, tree*& t2);
void search(int value, tree*& t);

void main() {
	int n;
	int value;
	cout << "Enter values for tree 1:\n";// add endl

	while (cin >> n) {
		add(n, treel);
	}

	cin.clear();// clear error flags;
	cin.ignore();// takes out some value from the buffer; 

	cout << "Enter values for tree 2:\n";
	while (cin >> n) {
		add(n, treer);
	}
	cin.clear();
	cin.ignore();

	cout << "Tree 1:" << endl;
	show(treel, 0);

	cout << "---------------------------------------" << endl;

	cout << "Tree 2:" << endl;
	show(treer, 0);

	//working
	//combine(treel, treer);


	combine(treen, treen);

	cout << "Tree 1 and Tree 2 combinded:" << endl;
	show(treen, 0);

	cout << "Enter a number you wish to search for in the combined tree: ";
	cin >> value;
	search(value, treen);
}


void add(int value, tree*& currentTree) {
	if (currentTree == NULL) {
		tree* p = new tree;
		p->key = value;
		p->left = p->right = NULL;
		currentTree = p;
	}
	else {
		if (currentTree->key < value)
		{
			add(value, currentTree->right);
		}
		else if (currentTree->key > value)
		{
			add(value, currentTree->left);
		}
		else
		{
			return;
		}
	}
}

void printNode(int n, int h) {
	for (int i = 0; i < h; i++) {
		cout << "	";
	}
	cout << n << '\n';
}

void show(tree* currentTree, int h) {
	if (!currentTree) {
		return;
	}

	show(currentTree->right, h + 1);
	printNode(currentTree->key, h);
	show(currentTree->left, h + 1);
}

void combine(tree*& firstTree, tree*& secondTree) {
	if (firstTree || secondTree) {

		if (firstTree == NULL) {

			// if first tree is null 
			// get the second tree key
			add(secondTree->key, treen);
			combine(firstTree, secondTree->left);
			combine(firstTree, secondTree->right);
		}
		else if (secondTree == NULL) {
			// if second tree is null 
			// get the first tree key
			add(firstTree->key, treen);
			combine(firstTree->left, secondTree);
			combine(firstTree->right, secondTree);
		}
		else if (firstTree == NULL && secondTree == NULL) {
			// if they are null stop the program
			cout << "You can't combine 2 NULLS" << endl;
			return;
		}
		else {
			if (firstTree->key < secondTree->key) {
				add(secondTree->key, treen);
				add(firstTree->key, treen);
			}
			else if (firstTree->key > secondTree->key) {
				add(firstTree->key, treen);
				add(secondTree->key, treen);
			}
			else return;
			combine(firstTree->left, secondTree->left);
			combine(firstTree->right, secondTree->right);
		}
	}
}

void search(int value, tree*& currentTree) {
	if (currentTree == NULL) {
		cout << "There is no such number in the tree or the tree has no values in it!";
	}
	else {
		if (currentTree->key == value) {
			cout << "The number you're searching for has been found in the tree!";
		}
		else if (currentTree->key < value) {
			search(value, currentTree->right);
		}
		else {
			search(value, currentTree->left);
		}
	}

}