#include "LeetCodeAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map> 

using namespace std;

//109.有序链表转换二叉搜索树（平衡二叉树）
TreeNode* Solution::sortedListToBST(ListNode* head)
{
	return buildTree_109(head,nullptr);
}

TreeNode* Solution::buildTree_109(ListNode* left, ListNode* right)
{
	if (left == right)
		return nullptr;
	ListNode* mid = getMidNum_109(left, right);
	TreeNode* root = new TreeNode(mid->val);
	root->left = buildTree_109(left, mid);
	root->right = buildTree_109(mid->next, right);
	
	return root;
}

ListNode* Solution::getMidNum_109(ListNode* left, ListNode* right)
{
	ListNode* fast = left;
	ListNode* slow = left;
	while (fast != right && fast->next != right)
	{
		fast = fast->next;
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}


//110.平衡二叉树
bool Solution::isBalanced(TreeNode* root)
{
	return height_110(root) >= 0;
};

int Solution::height_110(TreeNode* root)
{
	if (root == NULL)
	{
		return 0;
	}

	int leftHeight = height_110(root->left);
	int rightHeight = height_110(root->right);

	if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
	{
		return -1;
	}
	else
	{
		return max(leftHeight, rightHeight) + 1;
	}
}


//130.被围绕的区域
int n, m;
void Solution::solve(vector<vector<char>>& board) {
	n = board.size();
	if (n == 0) return;
	m = board[0].size();
	for (int i = 0; i<n; i++)
	{
		search_130(board, i, 0);
		search_130(board, i, m - 1);
	}
	for (int j = 1; j<m - 1; j++)
	{
		search_130(board, 0, j);
		search_130(board, n - 1, j);
	}
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<m; j++)
		{
			if (board[i][j] == 'A')
				board[i][j] = 'O';
			else if (board[i][j] == 'O')
				board[i][j] = 'X';
		}
	}
}

void Solution::search_130(vector<vector<char>>& board, int i, int j)
{
	if (i<0 || i >= n || j<0 || j >= m || board[i][j] != 'O')
		return;
	board[i][j] = 'A';
	search_130(board, i + 1, j);
	search_130(board, i - 1, j);
	search_130(board, i, j + 1);
	search_130(board, i, j - 1);
}
