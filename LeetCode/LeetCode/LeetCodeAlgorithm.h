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


class Solution
{
public:
	Solution();
	~Solution();

	vector<vector<int>> threeSum(vector<int>& nums);  //15.三数之和

	int threeSumClosest(vector<int>& nums, int target); //16.最接近的三数之和

	vector<string> letterCombinations(string digits);//17.电话号码的字母组合
	void DFS(int index, string digits);

	vector<vector<int>> fourSum(vector<int>& nums, int target);//18.四数之和

	ListNode* removeNthFromEnd(ListNode* head, int n);//19.删除链表的倒数第n个节点

	vector<string> generateParenthesis(int n);//22.括号生成
	void generateParenthesisHelper(vector<string>& ans, string& cur, int left, int right,int n);

	ListNode* swapPairs(ListNode* head);//24.两两交换链表中的节点

	int divide(int dividend, int divisor);//29.两数相除

	void nextPermutation(vector<int>& nums);//31.下一个排列

	int search(vector<int>& nums, int target);//33.搜索旋转排序数组
	
	string multiply(string num1, string num2);//43.字符串相乘
											  
	vector<vector<int>> permute(vector<int>& nums);//46.全排列
	void generatePermute(vector<int>& nums, vector<int>& cur, vector<bool>& used);

	TreeNode* sortedListToBST(ListNode* head);//109.有序链表转换二叉搜索树（平衡二叉树）
	TreeNode* buildTree_109(ListNode* left, ListNode* right);
	ListNode* getMidNum_109(ListNode* left, ListNode* right);

	bool isBalanced(TreeNode* root);//110.平衡二叉树
	int height_110(TreeNode* root);

	void solve(vector<vector<char>>& board);//130.被围绕的区域
	void search_130(vector<vector<char>>& board, int i, int j);



	//helper
	void createVector(vector<int>& nums,int num[]);
	void printMatrix(vector<vector<int>>& nums);

	TreeNode* createTree(TreeNode* root);
	void visit(TreeNode* node);
	void preTraversal(TreeNode* root);
	void midTraversal(TreeNode* root);
	void postTraversal(TreeNode* root);
};

