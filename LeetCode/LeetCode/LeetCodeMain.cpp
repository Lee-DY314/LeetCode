#include "LeetCodeAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include<String>

using namespace std;



//15.����֮��

//int main()
//{
//	int array[] = { -1,0,1,2,-1,-4 };
//	vector<int> input(array,array+6);
//
//	Solution sol;
//	vector<vector<int>> ans;
//	ans = sol.threeSum(input);
//
//	for (int i = 0; i < ans.size(); i++)
//	{
//		for (int j = 0; j < 3; j++)
//		{
//			cout << ans[i][j];
//		}
//		cout << endl;
//	}
//
//	return 0;
//}

//16.��ӽ�������֮��

//int main()
//{
//	int array[] = { -1,2,1,-4 };
//	vector<int> input(array, array + 4);
//
//	Solution sol;
//	int ans;
//	ans = sol.threeSumClosest(input,1);
//
//	cout << ans << endl;
//
//	return 0;
//}

//17.�绰�������ĸ���

//int main()
//{
//	string str = "235";
//	Solution sol;
//	vector<string> ans = sol.letterCombinations(str);
//	for (vector<string>::iterator it = ans.begin(); it != ans.end(); it++)
//	{
//		string temp = *it;
//		cout << temp;
//	}
//	return 0;
//}

//18.����֮��

//int main()
//{
//	vector<int> nums = { 1,0,-1,0,-2,2 };
//	Solution sol;
//	vector<vector<int>> ans = sol.fourSum(nums,0);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		for (int j = 0; j < 4; j++)
//		{
//			cout << ans[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}

//19.ɾ������ĵ�����n���ڵ�
//û�����Ϊɶ����

//int main()
//{
//	ListNode *head, *p, *q = NULL;
//	head = new ListNode(0);
//	int a = 5, i = 1;
//	while (a)
//	{
//		p = new ListNode(0);
//		p->val = a;
//		if (i == 1)
//		{
//			head->next = p;
//			i++;
//		}
//		else
//		{
//			q->next = p;
//		}
//		q = p;
//	}
//	q->next = NULL;
//
//	Solution sol;
//	sol.removeNthFromEnd(head, 2);
//	ListNode* it;
//	it = head->next;
//
//	while (it!= NULL)
//	{
//		cout << it->val;
//		it = it->next;
//	}
//	return 0;
//}

//22.��������

//int main()
//{
//	vector<string> ans;
//	Solution sol;
//	ans = sol.generateParenthesis(3);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << endl;
//	}
//	return 0;
//}

//24.�������������еĽڵ�
//�ò�����Ҫ�Ľ����������������ͷû�ˣ�����leetcode�Ϲ��ˡ�����

//int main()
//{
//	ListNode *head, *p, *q = NULL;
//	head = new ListNode(0);
//	int a = 5, i = 1;
//	while (a)
//	{
//		p = new ListNode(0);
//		p->val = a;
//		a--;
//		if (i == 1)
//		{
//			head = p;
//			i++;
//		}
//		else
//		{
//			q->next = p;
//		}
//		q = p;
//	}
//	q->next = NULL;
//
//	Solution sol;
//	sol.swapPairs(head);
//	ListNode* it;
//	it = head;
//	
//	while (it!= NULL)
//	{
//		cout << it->val;
//		it = it->next;
//	}
//	return 0;
//}

//29.�������

//int main()
//{
//	Solution sol;
//	int a =sol.divide(INT_MIN, 1);
//	cout << a << endl;
//}

//31.��һ������

//int main()
//{
//	vector<int> nums;
//	int num[] = {1,3,2 };
//	int n = sizeof(num) / 4;
//	for (int i = 0; i < n; i++)
//	{
//		nums.push_back(num[i]);
//	}
//
//	Solution sol;
//	sol.nextPermutation(nums);
//
//	for (int i = 0; i < n; i++)
//	{
//		cout << nums[i] << "";
//	}
//	return 0;
//}


//33.������ת��������

//int main()
//{
//	int num[] = { 4,5,6,7,8,9,10,0,1,2,3 };
//	vector<int> nums;
//	int n = sizeof(num) / 4;
//	for (int i = 0; i < n; i++)
//	{
//		nums.push_back(num[i]);
//	}
//
//	Solution sol;
//	int ans = sol.search(nums, 0);
//	cout << ans;
//	return 0;
//}

//43.�ַ������

//int main()
//{
//	string num1 = "123";
//	string num2 = "456";
//	Solution sol;
//	string ans = sol.multiply(num1, num2);
//	cout << ans << endl;
//	return 0;
//}

//46.ȫ����

//int main()
//{
//	vector<int> nums = { 1,2,3,4 };
//	Solution sol;
//	vector<vector<int>> ans = sol.permute(nums);
//	sol.printMatrix(ans);
//	return 0;
//}


//109.��������ת��������������ƽ���������

//int main()
//{
//	Solution sol;
//	TreeNode* root;
//	sol.createTree(root);
//
//	return 0;
//}

//110.ƽ�������

//int main()
//{
//
//}

//130.����Χ������

//int main()
//{
//	vector<vector<char>> board;
//	board.push_back({ 'X','X','X','X' });
//	board.push_back({ 'X','O','O','X' });
//	board.push_back({ 'X','X','O','X' });
//	board.push_back({ 'X','O','X','X' });
//
//	Solution sol;
//	sol.solve(board);
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		for (int j = 0; j < board[0].size(); j++)
//		{
//			cout << board[i][j];
//		}
//		cout << endl;
//	}
//	return 0;
//}