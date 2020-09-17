#include "SwordAlgorithm.h"
#include "LeetCodeAlgorithm.h"
#include "sword09.h"
#include "sword30.h"
#include "sword41.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <String>

using namespace std;


//04.��ά�����еĲ���

//int main()
//{
//	vector<int> a1 = { 1 ,4 ,7 ,11,15 };
//	vector<int> a2 = { 2 ,5 ,8 ,12,19 };
//	vector<int> a3 = { 3 ,6 ,9 ,16,22 };
//	vector<int> a4 = { 10,13,14,17,24 };
//	vector<int> a5 = { 18,21,23,26,30 };
//
//	vector<vector<int>> matrix;
//	matrix.push_back(a1);
//	matrix.push_back(a2);
//	matrix.push_back(a3);
//	matrix.push_back(a4);
//	matrix.push_back(a5);
//
//	Sword sword;
//	bool ans = sword.findNumberIn2DArray(matrix, 20);
//
//	cout << ans;
//	return 0;
//}

//06.��β��ͷ��ӡ����

//int main()
//{
//	ListNode* a = new ListNode(2);
//	ListNode* b = new ListNode(3,a);
//	ListNode* c = new ListNode(1,b);
//
//	Sword sword;
//	vector<int> ans = sword.reversePrint(c);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << " ";
//	}
//	return 0;
//}


//07.�ؽ�������

//int main()
//{
//	vector<int> preorder = { 1,2,4,5,3,6,7 };
//	vector<int> inorder = { 4,2,5,1,6,3,7 };
//	Sword sword;
//	TreeNode* root;
//	root = sword.buildTree(preorder, inorder);
//
//	Solution sol;
//	sol.postTraversal(root);
//
//	return 0;
//}


//09.������ջʵ�ֶ���

//int main()
//{
//	CQueue* que = new CQueue();
//	int p1 = que->deleteHead();
//	que->appendTail(5);
//	que->appendTail(2);
//	int p2 = que->deleteHead();
//	int p3 = que->deleteHead();
//
//	cout << p1 << " ";
//	cout << p2 << " ";
//	cout << p3 << endl;
//	return 0;
//}


//10.1.쳲���������

//int main()
//{
//	Sword sword;
//	int ans = sword.fib(100);
//	cout << ans;
//	return 0;
//}

//10.2.������̨������

//int main()
//{
//    Sword sword;
//	int ans = sword.numWays(2);
//	cout << ans;
//	return 0;
//}


//11. ��ת�������С����

//int main()
//{
//	vector<int> numbers = { 2,2,2,0,1 };
//	Sword sword;
//	int ans = sword.minArray(numbers);
//	cout << ans;
//	return 0;
//}


//12.�����е�·��

//int main()
//{
//	vector<vector<char>> board =
//	//{ { 'A','B','C','E' },
//	//  { 'S','F','C','S' },
//	//  { 'A','D','E','E' },
//	//};
//	{
//		{'a','b'}
//	};
//	Sword sword;
//	bool ans = sword.exist(board, "ba");
//	cout << ans;
//	return 0;
//}

//13.�����˵��˶���Χ

//int main()
//{
//	Sword sword;
//	int ans = sword.movingCount(2, 3, 1);
//	cout << ans;
//	return 0;
//}

//14.1.������1

//int main()
//{
//	Sword sword;
//	int ans = sword.cuttingRope_1(10);
//	cout << ans << endl;
//	return 0;
//}

//14.2.������2

//int main()
//{
//	Sword sword;
//	int ans = sword.cuttingRope_2(990);
//	cout << ans << endl;
//	return 0;
//}

//15.��������1�ĸ���

//int main()
//{
//	Sword sword;
//	int ans = sword.hammingWeight(4294967293,1,2);
//	cout << ans << endl;
//	return 0;
//}

//16.��ֵ�������η�

//int main()
//{
//	Sword sword;
//	double ans = sword.myPow(0.1,10);
//	cout << ans << endl;
//	return 0;
//}

//17. ��ӡ��1������nλ��

//int main()
//{
//	Sword sword;
//	vector<int> ans = sword.printNumbers(3);
//	for (int i = 0; i < ans.size(); i++)
//	{
//		cout << ans[i] << endl;
//	}
//	return 0;
//}

//18.ɾ������Ľڵ�

//int main()
//{
//	//ListNode* a3 = new ListNode(9);
//	ListNode* a2 = new ListNode(-99);
//	ListNode* a1 = new ListNode(5, a2);
//	ListNode* head = new ListNode(-3,a1);
//
//	Sword sword;
//	ListNode* ans;
//	ans = sword.deleteNode(head, -3);
//	while (ans != nullptr)
//	{
//		cout << ans->val << endl;
//		ans = ans->next;
//	}
//	return 0;
//}

//19.������ʽ��ƥ��

//int main()
//{
//	string s = "aaa";
//	string p = "ab*a*c*a";
//	Sword sword;
//	bool ans = sword.isMatch(s, p);
//	cout << ans << endl;
//	return 0;
//}

//20. ��ʾ��ֵ���ַ���

//int main()
//{
//	string s = "12e";
//	Sword sword;
//	bool ans = sword.isNumber(s);
//	cout << ans << endl;
//	return 0;
//}

//21.��������˳��ʹ����λ��ż��ǰ��

//int main()
//{
//	vector<int> nums = { 2,4,6};
//	Sword sword;
//	vector<int> ans = sword.exchange(nums);
//	for (int i=0;i<ans.size();i++)
//	{
//		cout << nums[i] << ' ';
//	}
//	return 0;
//}


//27.�������ľ���

//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	TreeNode* a1 = new TreeNode(4);
//	TreeNode* a2 = new TreeNode(5);
//	TreeNode* a3 = new TreeNode(1);
//	TreeNode* a4 = new TreeNode(2);
//	root->left = a1;
//	root->right = a2;
//	a1->left = a3;
//	a1->right = a4;
//	Sword sword;
//	TreeNode* ans = sword.mirrorTree(root);
//	Solution sol;
//	sol.midTraversal(ans);
//	cout << ans << endl;
//	return 0;
//}

//28.�ԳƵĶ�����

//int main()
//{
//	TreeNode* root = new TreeNode(1);
//	TreeNode* a1 = new TreeNode(2);
//	TreeNode* a2 = new TreeNode(2);
//	TreeNode* a3 = new TreeNode(3);
//	TreeNode* a4 = new TreeNode(3);
//	root->left = a1;
//	root->right = a2;
//	a1->right = a3;
//	a2->right = a4;
//	Sword sword;
//	bool ans = sword.isSymmetric(root);
//	cout << ans << endl;
//	return 0;
//}

//29.˳ʱ���ӡ����

//int main()
//{
//	vector<vector<int>> matrix = {
//		{1 ,2 ,3 ,4},
//		{5 ,6 ,7 ,8},
//		{9 ,10,11,12},
//		{13,14,15,16}
//	};
//	Sword sword;
//	vector<int> ans = sword.spiralOrder(matrix);
//	for (int i : ans)
//		cout << i << " ";
//	return 0;
//}

//30. ����min������ջ

//int main()
//{
//	MinStack min;
//	min.push(-2);
//	min.push(0);
//	min.push(-3);
//	cout << min.min();
//	min.pop();
//	cout<< min.top();
//	cout << min.min();
//}

//31. ջ��ѹ�롢��������

//int main()
//{
//	vector<int> pushed = { 1,2,3,4,5 };
//	vector<int> popped = { 4,5,3,2,1 };
//	Sword sword;
//	bool ans = sword.validateStackSequences(pushed, popped);
//	cout << ans;
//  return 0;
//}

//32 - I. ���ϵ��´�ӡ������

//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	TreeNode* a1 = new TreeNode(9);
//	TreeNode* a2 = new TreeNode(20);
//	TreeNode* a3 = new TreeNode(15);
//	TreeNode* a4 = new TreeNode(7);
//	root->left = a1;
//	root->right = a2;
//	a2->left = a3;
//	a2->right = a4;
//
//	Sword sword;
//	vector<int> ans = sword.levelOrder_1(root);
//	for (int i : ans)
//	{
//		cout << i << " ";
//	}
//	return 0;
//}

//32 - II.���ϵ��´�ӡ������II

//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	TreeNode* a1 = new TreeNode(9);
//	TreeNode* a2 = new TreeNode(20);
//	TreeNode* a3 = new TreeNode(15);
//	TreeNode* a4 = new TreeNode(7);
//	root->left = a1;
//	root->right = a2;
//	a2->left = a3;
//	a2->right = a4;
//
//	Sword sword;
//	vector<vector<int>> ans = sword.levelOrder_2(root);
//	for (int i=0;i<ans.size();i++)
//	{
//		for (int j = 0; j < ans[i].size(); j++)
//		{
//			cout << ans[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//32 - II.���ϵ��´�ӡ������II

//int main()
//{
//	TreeNode* root = new TreeNode(3);
//	TreeNode* a1 = new TreeNode(9);
//	TreeNode* a2 = new TreeNode(20);
//	TreeNode* a3 = new TreeNode(15);
//	TreeNode* a4 = new TreeNode(7);
//	root->left = a1;
//	root->right = a2;
//	a2->left = a3;
//	a2->right = a4;
//
//	Sword sword;
//	vector<vector<int>> ans = sword.levelOrder_3(root);
//	for (int i = 0; i<ans.size(); i++)
//	{
//		for (int j = 0; j < ans[i].size(); j++)
//		{
//			cout << ans[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//33.�����������ĺ����������

//int main()
//{
//	vector<int> postorder = { 1,3,2,6,5 };
//	Sword sword;
//	bool ans = sword.verifyPostorder(postorder);
//	cout << ans << endl;
//	return 0;
//}

//34. �������к�Ϊĳһֵ��·��

//int main()
//{
//	TreeNode* root = new TreeNode(5);
//	TreeNode* a1 = new TreeNode(4);
//	TreeNode* a2 = new TreeNode(8);
//	TreeNode* a3 = new TreeNode(11);
//	TreeNode* a4 = new TreeNode(13);
//	TreeNode* a5 = new TreeNode(4);
//	TreeNode* a6 = new TreeNode(7);
//	TreeNode* a7 = new TreeNode(2);
//	TreeNode* a8 = new TreeNode(5);
//	TreeNode* a9 = new TreeNode(1);
//	root->left = a1;
//	root->right = a2;
//	a1->left = a3;
//	a2->left = a4;
//	a2->right = a5;
//	a3->left = a6;
//	a3->right = a7;
//	a5->left = a8;
//	a5->right = a9;
//
//	Sword sword;
//	vector<vector<int>> ans = sword.pathSum(root,22);
//	for (int i = 0; i<ans.size(); i++)
//	{
//		for (int j = 0; j < ans[i].size(); j++)
//		{
//			cout << ans[i][j] << " ";
//		}
//		cout << endl;
//	}
//	return 0;
//}

//35. ��������ĸ���

//int main()
//{
//	Node* a0 = new Node(7);
//	Node* a1 = new Node(13);
//	Node* a2 = new Node(11);
//	Node* a3 = new Node(10);
//	Node* a4 = new Node(1);
//
//	a0->next = a1;
//	a1->next = a2;
//	a2->next = a3;
//	a3->next = a4;
//	a4->next = nullptr;
//
//	a0->random = nullptr;
//	a1->random = a0;
//	a2->random = a4;
//	a3->random = a2;
//	a4->random = a0;
//
//	Sword sword;
//	Node* ans = sword.copyRandomList(a0);
//	while (ans!=nullptr)
//	{
//		cout << ans->val;
//		if (ans->next != nullptr)
//			cout << " next:" << ans->next->val;
//		else
//			cout << " next: null" ;
//		if (ans->random != nullptr)
//			cout << " random:" << ans->random->val;
//		else
//			cout << " random: null";
//		ans = ans->next;
//		cout << endl;
//	}
//	return 0;
//}

//38.�ַ���������

//int main()
//{
//	string s = "aab";
//	Sword sword;
//	vector<string> ans = sword.permutation(s);
//	for (auto i : ans)
//		cout << i << endl;
//	return 0;
//	system("pause");
//}

//39. �����г��ִ�������һ�������

//int main()
//{
//	vector<int> nums = {1,2,3,2,2,2,5,4,2};
//	Sword sword;
//	int ans = sword.majorityElement(nums);
//	cout << ans << endl;
//	return 0;
//	system("pause");
//}

//40. ��С��k����

//int main()
//{
//	vector<int> nums = { 1,2,3,2,2,2,5,4,2 };
//	Sword sword;
//	vector<int> ans = sword.getLeastNumbers(nums,3,true);
//	for (auto num : ans)
//		cout << num << endl;
//	return 0;
//	system("pause");
//}

//41. �������е���λ��

//int main()
//{
//	MedianFinder1* mid = new MedianFinder1();
//	mid->addNum(2);
//	double a1 = mid->findMedian();
//	mid->addNum(3);
//	double a2 = mid->findMedian();
//	cout << a1 << endl;
//	cout << a2 << endl;
//}

//42. ���������������

//int main()
//{
//	vector<int> nums = { -2,1,-3,4,-1,2,1,-5,4 };
//	Sword sword;
//	int ans = sword.maxSubArray(nums);
//	cout << ans << endl;
//	return 0;
//	system("pause");
//}

//43. 1��n������1���ֵĴ���

//int main()
//{
//	Sword sword;
//	int ans = sword.countDigitOne(12);
//	cout << ans << endl;
//	return 0;
//	system("pause");
//}


//44. ����������ĳһλ������

//int main()
//{
//	Sword sword;
//	int ans = sword.findNthDigit(1000000000);
//	cout << ans << endl;
//	return 0;
//	system("pause");
//}


//45. �������ų���С����

int main()
{
	vector<int> nums = {3,30,34,5,9 };
	Sword sword;
	string ans = sword.minNumber(nums);
	cout << ans << endl;
	return 0;
	system("pause");
}

//50. ��һ��ֻ����һ�ε��ַ�

//int main()
//{
//	string str = "abcbadfhhgs";
//	Sword sword;
//	char ans = sword.firstUniqChar(str);
//	cout << ans << endl;
//	return 0;
//	system("pause");
//}

//KMP�㷨

//int main()
//{
//	Sword sword;
//	int next[10];
//	string T = "ababaaaba";
//	sword.getNext(T, next);
//	for (int i: next)
//	{
//		cout << i << " ";
//	}
//}