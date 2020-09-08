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


	bool findNumberIn2DArray(vector<vector<int>>& matrix, int target);//04.��ά�����еĲ���

																	  
	vector<int> reversePrint(ListNode* head);//06.��β��ͷ��ӡ����

											
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder); //07.�ؽ�������
	TreeNode* setNode(vector<int>& preorder, int preBegin, int preEnd, vector<int>& inorder, int inBegin, int inEnd);

	int fib(int n);// 10.1.쳲���������

	int numWays(int n);//10.2.������̨������

	int minArray(vector<int>& numbers);//11. ��ת�������С����
			   
	bool exist(vector<vector<char>>& board, string word);//12.�����е�·��
	bool dfs_12(vector<vector<char>>& board, string word, int i, int j, int k);

	int movingCount(int m, int n, int k);//13.�����˵��˶���Χ
	void dfs_13(int i, int j, int m, int n, int k, vector<vector<int>>& arr);


	int cuttingRope_1(int n);//14.1.������1

	int cuttingRope_2(int n);//14.2.������2

    int hammingWeight(uint32_t n);//15.��������1�ĸ���
	int hammingWeight(uint32_t n, int a);//λ����
	int hammingWeight(uint32_t n, int a, int b);//������λ����

	double myPow(double x, int n);//16.��ֵ�������η�

	vector<int> printNumbers(int n);//17. ��ӡ��1������nλ��

	ListNode* deleteNode(ListNode* head, int val);//18.ɾ������Ľڵ�

	bool isMatch(string s, string p);//19.������ʽ��ƥ��
									 
	bool isNumber(string s);//20. ��ʾ��ֵ���ַ���
	CharType toCharType(char ch);
	
	vector<int> exchange(vector<int>& nums);//21.��������˳��ʹ����λ��ż��ǰ��
											
	ListNode* getKthFromEnd(ListNode* head, int k);//22.�����еĵ�����k���ڵ�

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);//25.�ϲ�������������

	bool isSubStructure(TreeNode* A, TreeNode* B);//26. �����ӽṹ
	bool helper_26(TreeNode* A, TreeNode* B);

	TreeNode* mirrorTree(TreeNode* root);//27.�������ľ���
	bool helper_28(TreeNode* t1, TreeNode* t2);
										
	bool isSymmetric(TreeNode* root); //28. �ԳƵĶ�����
									
	vector<int> spiralOrder(vector<vector<int>>& matrix);//29.˳ʱ���ӡ����

	bool validateStackSequences(vector<int>& pushed, vector<int>& popped);//31. ջ��ѹ�롢��������
					  
	vector<int> levelOrder_1(TreeNode* root);//32 - I.���ϵ��´�ӡ������

	vector<vector<int>> levelOrder_2(TreeNode* root);//32 - II.���ϵ��´�ӡ������II
													 
	vector<vector<int>> levelOrder_3(TreeNode* root);//32 - III. ���ϵ��´�ӡ������ III
													
	bool verifyPostorder(vector<int>& postorder);//33.�����������ĺ����������
	bool helper_33(vector<int>& poetorder, int start, int end);

	vector<vector<int>> pathSum(TreeNode* root, int sum);//34. �������к�Ϊĳһֵ��·��
	void helper_34(TreeNode* root, int sum);

	void getNext(string T, int *next);//KMP�㷨
};