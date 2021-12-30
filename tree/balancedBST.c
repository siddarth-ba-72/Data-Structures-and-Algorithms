#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX 20

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

typedef struct node *Node;

// ? Creating a new Tree Node
Node newNode(int value)
{
	Node temp = (Node)malloc(sizeof(struct node));
	temp->data = value;
	temp->left = temp->right = NULL;
	return temp;
}

// ? Inserting a new Node into the tree
Node insert(Node root, int value)
{
	if (root == NULL)
		return newNode(value);
	if (value < root->data)
		root->left = insert(root->left, value);
	else if (value > root->data)
		root->right = insert(root->right, value);
	return root;
}

// ? Inorder Traversal of Tree
void inorderTraversal(Node root)
{
	if (root != NULL)
	{
		inorderTraversal(root->left);
		printf("%d ", root->data);
		inorderTraversal(root->right);
	}
}

// ? Preorder traversal of a node
void preorderTraversal(Node root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
	printf("\n");
}

// ? Postorder traversal of a node
void postorderTraversal(Node root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->data);
	printf("\n");
}

// ? Level order traversal of a tree
void levelOrderTraversal(Node root)
{
	Node qu[MAX], curr;
	int front = 0, rear = -1;
	qu[++rear] = root;
	while (front <= rear)
	{
		curr = qu[front++];
		printf("%d ", curr->data);
		if (curr->left != NULL)
			qu[++rear] = curr->left;
		if (curr->right != NULL)
			qu[++rear] = curr->right;
	}
	printf("\n");
}

// ? Maximum value in a tree
int maxNum(Node root)
{
	if (root == NULL)
		return -1;
	Node curr = root;
	while (curr->right != NULL)
		curr = curr->right;
	return curr->data;
}

// ? Max value node
Node maxNode(Node root)
{
	Node curr = root;
	while (curr && curr->right != NULL)
		curr = curr->right;
	return curr;
}

// ? Minimum value in a tree
int minNum(Node root)
{
	if (root == NULL)
		return -1;
	Node curr = root;
	while (curr->left != NULL)
		curr = curr->left;
	return curr->data;
}

// ? Min value node
Node minValueNode(Node root)
{
	Node curr = root;
	while (curr && curr->left != NULL)
		curr = curr->left;
	return curr;
}

// ? Finding the height of a tree
int heightBST(Node root)
{
	if (root == NULL)
		return 0;
	int lDeapth = heightBST(root->left);
	int rDeapth = heightBST(root->right);
	return (lDeapth > rDeapth) ? lDeapth + 1 : rDeapth + 1;
}

// ? Number of nodes in the tree
int numOfNodes(Node root)
{
	return (root == NULL) ? 0 : 1 + numOfNodes(root->left) + numOfNodes(root->right);
}

// ? Number of leaf nodes in a tree
int numOfLeafNodes(Node root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return numOfLeafNodes(root->left) + numOfLeafNodes(root->right);
}

// ? Delete a node from the tree
Node deleteNode(Node root, int key)
{
	if (root == NULL)
		return root;
	if (key < root->data)
		root->left = deleteNode(root->left, key);
	else if (key > root->data)
		root->right = deleteNode(root->right, key);
	else
	{
		if (root->left == NULL)
		{
			Node temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			Node temp = root->left;
			free(root);
			return temp;
		}
		Node temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right, temp->data);
	}
}

// ? Sorting an array of integers
void sort(int arr[], int n)
{
	int i, j, temp;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// ? Convert to balanced BST from given array of integers
Node arrToBst(int arr[], int low, int high, int n)
{
	sort(arr, n);
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	Node root = newNode(arr[mid]);
	root->left = arrToBst(arr, low, mid - 1, n);
	root->right = arrToBst(arr, mid + 1, high, n);
	return root;
}

int main()
{
	Node root = NULL;
	root = insert(root, 50);
	insert(root, 30);
	insert(root, 20);
	insert(root, 40);
	insert(root, 70);
	insert(root, 60);
	insert(root, 80);
	inorderTraversal(root);
	printf("\n");

	int del = 40;
	printf("Deleting Node = %d\n", del);
	root = deleteNode(root, del);
	inorderTraversal(root);
	printf("\n");
	levelOrderTraversal(root);

	printf("\n\t\t-:Array to BST:-\n");
	int arr[] = {8, 6, 7, 9, 11, 2, 5, 13, 16, 19};
	int n = sizeof(arr) / sizeof(arr[0]);
	printf("Array:-\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Node rootFromArray = arrToBst(arr, 0, n - 1, n);
	printf("BST(inOrder traversal):-\n");
	inorderTraversal(rootFromArray);
	printf("\n");

	return 0;
}
