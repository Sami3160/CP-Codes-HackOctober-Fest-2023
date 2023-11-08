#include <iostream>
using namespace std;
struct node {
	int key;
	struct node *left, *right;
};
struct node* newNode(int item)
{
	struct node* temp
		= new struct node;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}
struct node* insert(struct node* node, int key)
{
	// If the tree is empty, return a new node
	if (node == NULL)
		return newNode(key);

	// Otherwise, recur down the tree
	if (key < node->key)
		node->left = insert(node->left, key);
	else if (key > node->key)
		node->right = insert(node->right, key);

	return node;
}

struct node* search(struct node* root, int key)
{
//Cxeck if node is greater that root
	if (root == NULL || root->key == key)
		return root;
	if (root->key < key)
		return search(root->right, key);
	return search(root->left, key);
}
int main()
{
	struct node* root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);

	// Unknown Key,  will not be found
	int key = 69;

	// Searching wala logic
	if (search(root, key) == NULL)
		cout << key << " not found" << endl;
	else
		cout << key << " found" << endl;


//This key would be found
	key = 70;
	if (search(root, key) == NULL)
		cout << key << " not found" << endl;
	else
		cout << key << " found" << endl;
	return 0;
}
