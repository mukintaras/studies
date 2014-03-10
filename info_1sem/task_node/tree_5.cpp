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

int tree_height (struct Node * tree)
{
	if (tree ==  NULL)
		return 0;
	else
	{
		int ret1 = 1, ret2 = 1;
		if (tree->left != NULL)
			ret1 += tree_height(tree->left);
		if (tree->right != NULL)
			ret2 += tree_height(tree->right);
		return (ret1 > ret2)?ret1:ret2;
	}
};

void tree_printl (struct Node * tree)
{
	if ((tree->left == NULL) && (tree->right == NULL))
		printf("%d ", tree->val);
	if (tree->left != NULL)
		tree_printl(tree->left);
	if (tree->right != NULL)
		tree_printl(tree->right);
};

int tree_balanced (struct Node * tree)
{
	if (tree == NULL)
		return 1;
	else
		if (tree_balanced(tree->left) && tree_balanced(tree->right) && ((tree_height(tree->left) - tree_height(tree->right)) <= 1) && ((tree_height(tree->left) - tree_height(tree->right)) >= -1))
			return 1;
		else
			return 0;
		
}

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

	printf("%s\n", tree_balanced(tree)?"YES":"NO");

	tree_destroy(tree);

	return 0;
}