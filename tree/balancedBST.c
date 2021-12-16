#include <stdio.h>
#include <stdlib.h>
#define SIZEOF(arr) sizeof(arr) / sizeof(*arr)

struct Tree
{
	int data;
	struct Tree *left;
	struct Tree *right;
};

typedef struct Tree *tree;

// ? Function to create a new tree node
tree newNode(int data)
{
	tree root = (tree)malloc(sizeof(struct Tree));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	return root;
}

// ? Insert a key in a tree
tree insert(tree root, int key)
{
	tree temp = (tree)malloc(sizeof(struct Tree));
	printf("Enter the key: ");
	scanf("%d", key);
	temp->data = key;
	temp->left = temp->right = NULL;
	if (root == NULL)
		return temp;
	if (key < root->data)
		root->left = insert(root->left, key);
	else
		root->right = insert(root->right, key);
	return root;
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

// ? Convert balanced BST from given array of integers
tree arrToBst(int arr[], int low, int high, int n)
{
	sort(arr, n);
	if (low > high)
		return NULL;
	int mid = (low + high) / 2;
	tree root = newNode(arr[mid]);
	root->left = arrToBst(arr, low, mid - 1, n);
	root->right = arrToBst(arr, mid + 1, high, n);
	return root;
}

// ? Inorder traversal of a tree
void inorderTraversal(tree root)
{
	if (root == NULL)
		return;
	inorderTraversal(root->left);
	printf("%d ", root->data);
	inorderTraversal(root->right);
}

// ? Preorder traversal of a tree
void preorderTraversal(tree root)
{
	if (root == NULL)
		return;
	printf("%d ", root->data);
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

// ? Postorder traversal of a tree
void postorderTraversal(tree root)
{
	if (root == NULL)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	printf("%d ", root->data);
}

int main()
{
	int arr[] = {15, 10, 20, 8, 12, 16, 25};
	int n = sizeof(arr) / sizeof(arr[0]);
	tree root = arrToBst(arr, 0, n - 1, n);
	printf("Inorder: ");
	inorderTraversal(root);
	printf("\n");
	printf("Preorder: ");
	preorderTraversal(root);
	printf("\n");
	printf("Postorder: ");
	postorderTraversal(root);
	printf("\n");
	return 0;
}
