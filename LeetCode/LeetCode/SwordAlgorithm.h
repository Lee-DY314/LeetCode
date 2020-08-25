#pragma once
#include<vector>
#include<cstdlib>
#include"LeetCodeAlgorithm.h"

using namespace std;


class Sword {
public:
	Sword();
	~Sword();


	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//04.��ά�����еĲ���

																	  
	vector<int> reversePrint(ListNode* head);//06.��β��ͷ��ӡ����

											
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder); //07.�ؽ�������
	TreeNode* setNode(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd);

	int fib(int n);// 10.1.쳲���������

	int numWays(int n);//10.2.������̨������

	int minArray(vector<int>& numbers);//11. ��ת�������С����
};