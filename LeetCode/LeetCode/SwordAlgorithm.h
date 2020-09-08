#pragma once
#include<vector>
#include<cstdlib>
#include"LeetCodeAlgorithm.h"

using namespace std;


class Sword {
public:
	Sword();
	~Sword();

	enum State {
		STATE_INITIAL,
		STATE_INT_SIGN,
		STATE_INTEGER,
		STATE_POINT,
		STATE_POINT_WITHOUT_INT,
		STATE_FRACTION,
		STATE_EXP,
		STATE_EXP_SIGN,
		STATE_EXP_NUMBER,
		STATE_END,
	};

	enum CharType {
		CHAR_NUMBER,
		CHAR_EXP,
		CHAR_POINT,
		CHAR_SIGN,
		CHAR_SPACE,
		CHAR_ILLEGAL,
	};


	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//04.二维数组中的查找

																	  
	vector<int> reversePrint(ListNode* head);//06.从尾到头打印链表

											
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder); //07.重建二叉树
	TreeNode* setNode(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd);

	int fib(int n);// 10.1.斐波那契数列

	int numWays(int n);//10.2.青蛙跳台阶问题

	int minArray(vector<int>& numbers);//11. 旋转数组的最小数字
			   
	bool exist(vector<vector<char>>& board, string word);//12.矩阵中的路径
	bool dfs_12(vector<vector<char>>& board, string word, int i, int j, int k);

	int movingCount(int m, int n, int k);//13.机器人的运动范围
	void dfs_13(int i, int j, int m, int n, int k, vector<vector<int>>& arr);


	int cuttingRope_1(int n);//14.1.剪绳子1

	int cuttingRope_2(int n);//14.2.剪绳子2

    int hammingWeight(uint32_t n);//15.二进制中1的个数
	int hammingWeight(uint32_t n, int a);//位运算
	int hammingWeight(uint32_t n, int a, int b);//升级版位运算

	double myPow(double x, int n);//16.数值的整数次方

	vector<int> printNumbers(int n);//17. 打印从1到最大的n位数

	ListNode* deleteNode(ListNode* head, int val);//18.删除链表的节点

	bool isMatch(string s, string p);//19.正则表达式的匹配
									 
	bool isNumber(string s);//20. 表示数值的字符串
	CharType toCharType(char ch);
	
	vector<int> exchange(vector<int>& nums);//21.调整数组顺序使奇数位于偶数前面
											
	ListNode* getKthFromEnd(ListNode* head, int k);//22.链表中的倒数第k个节点

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);//25.合并两个排序链表

	bool isSubStructure(TreeNode* A, TreeNode* B);//26. 树的子结构
	bool helper_26(TreeNode* A, TreeNode* B);

	TreeNode* mirrorTree(TreeNode* root);//27.二叉树的镜像
	bool helper_28(TreeNode* t1, TreeNode* t2);
										
	bool isSymmetric(TreeNode* root); //28. 对称的二叉树
									
	vector<int> spiralOrder(vector<vector<int>>& matrix);//29.顺时针打印矩阵

	bool validateStackSequences(vector<int>& pushed, vector<int>& popped);//31. 栈的压入、弹出序列
					  
	vector<int> levelOrder_1(TreeNode* root);//32 - I.从上到下打印二叉树

	vector<vector<int>> levelOrder_2(TreeNode* root);//32 - II.从上到下打印二叉树II
													 
	vector<vector<int>> levelOrder_3(TreeNode* root);//32 - III. 从上到下打印二叉树 III
													
	bool verifyPostorder(vector<int>& postorder);//33.二叉搜索树的后序遍历序列
	bool helper_33(vector<int>& poetorder, int start, int end);

	vector<vector<int>> pathSum(TreeNode* root, int sum);//34. 二叉树中和为某一值的路径
	void helper_34(TreeNode* root, int sum);

	void getNext(string T, int *next);//KMP算法
};