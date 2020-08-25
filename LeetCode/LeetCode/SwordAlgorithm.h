#pragma once
#include<vector>
#include<cstdlib>
#include"LeetCodeAlgorithm.h"

using namespace std;


class Sword {
public:
	Sword();
	~Sword();


	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//04.二维数组中的查找

																	  
	vector<int> reversePrint(ListNode* head);//06.从尾到头打印链表

											
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder); //07.重建二叉树
	TreeNode* setNode(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd);

	int fib(int n);// 10.1.斐波那契数列

	int numWays(int n);//10.2.青蛙跳台阶问题

	int minArray(vector<int>& numbers);//11. 旋转数组的最小数字
};