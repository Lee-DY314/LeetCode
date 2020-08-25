#include "LeetCodeAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map> 

using namespace std;

void Solution::createVector(vector<int>& nums,int num[])
{
	int n = sizeof(num) / 4;
	for (int i = 0; i < n; i++)
	{
		nums.push_back(num[i]);
	}
}

TreeNode* Solution::createTree(TreeNode* root)
{
	char data;
	cin >> data;
	if (data == '#')
	{
		root = nullptr;
	}
	else
	{
		root = new TreeNode(data);
		createTree(root->left);
		createTree(root->right);
	}
	return root;
}

void Solution::visit(TreeNode* node)
{
	if (node != nullptr)
	{
		cout << node->val << " ";
	}
}

//前序遍历 递归方法
void Solution::preTraversal(TreeNode* root)
{
	if (root != nullptr)
	{
		visit(root);
		preTraversal(root->left);
		preTraversal(root->right);
	}
}

//中序遍历 递归方法
void Solution::midTraversal(TreeNode* root)
{
	if (root != nullptr)
	{
		midTraversal(root->left);
		visit(root);
		midTraversal(root->right);
	}
}

//后序遍历 递归方法
void Solution::postTraversal(TreeNode* root)
{
	if (root != nullptr)
	{
		postTraversal(root->left);
		postTraversal(root->right);
		visit(root);
	}
}