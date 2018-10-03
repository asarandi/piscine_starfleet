#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <string.h>
#include <limits.h>


int	minvalue(struct s_node *root, int save)
{
	if (!root)
		return (save);
	if (root->value < save)
		save = root->value;
	if (root->left)
		save = minvalue(root->left, save);
	if (root->right)
		save = minvalue(root->right, save);
	return (save);
}

int	maxvalue(struct s_node *root, int save)
{
	if (!root)
		return (save);
	if (root->value > save)
		save = root->value;
	if (root->left)
		save = maxvalue(root->left, save);
	if (root->right)
		save = maxvalue(root->right, save);
	return (save);
}

int	numnodes(struct s_node *root, int save)
{
	if (!root)
		return (save);
	save++;
	if (root->left)
		save = numnodes(root->left, save);
	if (root->right)
		save = numnodes(root->right, save);
	return (save);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	getHeight(struct s_node *root)
{
	if ((!root) || ((!root->left) && (!root->right)))
		return (0);
	int	maxDepth = 0;
	maxDepth = max(maxDepth, getHeight(root->left));
	maxDepth = max(maxDepth, getHeight(root->right));
	return (maxDepth + 1);
}

int	isBST(struct s_node *root)
{
	if (root == NULL)
		return (1);
	if (root->left)
	{
		if (maxvalue(root->left, INT_MIN) > root->value)
			return (0);
	}
	if (root->right)
	{
		if (minvalue(root->right, INT_MAX) < root->value)
			return (0);
	}
	if (isBST(root->left) == 0)
		return (0);
	if (isBST(root->right) == 0)
		return (0);
	return (1);
}

int	isBalanced(struct s_node *root)
{
	if (root == NULL)
		return (1);
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	int	height = left - right;
	if (height < 0)
		height = -height;
	if (height > 1)
		return (0);
	if (isBalanced(root->left) == 1)
		return (isBalanced(root->right));
	return (0);

}

struct s_info	getInfo(struct s_node *root)
{
	struct	s_info	info1;
	struct	s_info	*info;


	info = &info1;
	bzero(info, sizeof(struct s_info));

	if (root == NULL)
		return (info1);

	info->min = minvalue(root, INT_MAX);
	info->max = maxvalue(root, INT_MIN);
	info->elements = numnodes(root, 0);
	info->height = getHeight(root);
	info->isBST = isBST(root);
	info->isBalanced = isBalanced(root);

	return (info1);
}
