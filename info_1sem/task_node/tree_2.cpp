#include <stdlib.h>
#include <stdio.h>

typedef int Data;

struct Node 
{
    Data val;            // данные в узле
    struct Node * left;  // левый ребенок
    struct Node * right; // правый ребенок
};

struct Node * tree_add(struct Node * tree, Data x)
{
	if (tree == NULL)
	{
		tree = (struct Node *) malloc(sizeof(struct Node));
		tree->left = NULL;
		tree->right = NULL;
		tree->val = x;
	}
	else
	{	
		if (x < tree->val)
		{	
			if (tree->left != NULL)
				tree_add(tree->left, x);
			else
			{
				tree->left = (struct Node *) malloc(sizeof(struct Node));
				tree->left->left = NULL;
				tree->left->right = NULL;
				tree->left->val = x;

			};
		}
		else 
		{
			if (x > tree->val)
			{
				if (tree->right != NULL)
					tree_add(tree->right, x);
				else
				{
					tree->right = (struct Node *) malloc(sizeof(struct Node));
					tree->right->left = NULL;
					tree->right->right = NULL;
					tree->right->val = x;
				};
			}
		};
	};
	return tree;
};

void tree_print (struct Node * tree)
{
	if (tree->left != NULL)
		tree_print(tree->left);
	printf("%d ", tree->val);
	if (tree->right != NULL)
		tree_print(tree->right);
};

void tree_destroy (struct Node * tree)
{
	if (tree->left != NULL)
		tree_destroy(tree->left);
	if (tree->right != NULL)
		tree_destroy(tree->right);
	free((void*)tree);
};

int main()
{
	struct Node * tree = NULL;
	
	int nn;
	scanf("%d", &nn);
	while (nn > 0)
	{
		tree = tree_add(tree, nn);
		scanf("%d", &nn);
	};

	tree_print(tree);

	tree_destroy(tree);

	return 0;
}