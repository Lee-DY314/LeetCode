#include "SwordAlgorithm.h"
#include "sword09.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <String>

using namespace std;


//04.二维数组中的查找

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

//06.从尾到头打印链表

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


//09.用两个栈实现队列

int main()
{
	CQueue* que = new CQueue();
	int p1 = que->deleteHead();
	que->appendTail(5);
	que->appendTail(2);
	int p2 = que->deleteHead();
	int p3 = que->deleteHead();

	cout << p1 << " ";
	cout << p2 << " ";
	cout << p3 << endl;
	return 0;
}