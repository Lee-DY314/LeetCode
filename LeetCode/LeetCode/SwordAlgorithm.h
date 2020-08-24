#pragma once
#include<vector>
#include<cstdlib>

using namespace std;


//Definition for singly-linked list.
typedef struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
}ListNode;


//Definition for a binary tree node.
typedef struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() :val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) :val(x), left(left), right(right) {}
}TreeNode;


class Sword {
public:
	Sword();
	~Sword();


	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//04.二维数组中的查找

																	  
	vector<int> reversePrint(ListNode* head);//06.从尾到头打印链表
};