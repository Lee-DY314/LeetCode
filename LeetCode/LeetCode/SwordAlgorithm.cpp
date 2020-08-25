#include "SwordAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map> 
#include <cstdlib>
#include <string>

using namespace std;

Sword::Sword()
{
}

Sword::~Sword()
{
}


//04.二维数组中的查找

//bool Sword::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
//{
//	int n = matrix.size();
//	if (n == 0) return false;
//	int m = matrix[0].size();
//	if (m == 0) return false;
//	for (int i = 0; i<n; i++)
//	{
//		for (int j = 0; j < m; j++)
//		{
//			if (target < matrix[i][j])
//			{
//				m = j + 1;
//			}
//			else if (target == matrix[i][j])
//			{
//				return true;
//			}
//		}
//	}
//	return false;
//}

bool Sword::findNumberIn2DArray(vector<vector<int>>& matrix, int target)
{
	int n = matrix.size();
	if (n == 0) return false;
	int m = matrix[0].size();
	if (m == 0) return false;
	int i = 0, j = m - 1;
	while (i<n && j>=0)
	{
		if (target == matrix[i][j])
		{
			return true;
		}
		else if (target > matrix[i][j])
		{
			i++;
		}
		else
		{
			j--;
		}
	}
	return false;
}


//06.从尾到头打印链表
vector<int> Sword::reversePrint(ListNode* head) 
{
	vector<int> temp;
	ListNode* tempNode = head;
	while (tempNode != nullptr)
	{
		temp.push_back(tempNode->val);
		tempNode = tempNode->next;
	}

	vector<int> ans;
	for (int i = temp.size()-1; i >= 0; i--)
	{
		ans.push_back(temp[i]);
	}
	return ans;
}

//07.重建二叉树
map<int, int> searchmap;

TreeNode* Sword::buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	for (int i = 0; i < inorder.size(); i++)
	{
		searchmap.insert(pair<int, int>(inorder[i],i));
		//另一种方式
		//searchmap[i] = inorder[i];
	}

	return setNode(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

//可以通过 传入原向量的迭代器代替新建向量 减少空间复杂度
TreeNode* Sword::setNode(vector<int>& preorder,int preBegin,int preEnd, vector<int>& inorder,int inBegin,int inEnd)
{
	if (preBegin > preEnd)
		return nullptr;
	int rootval = preorder[preBegin];
	int rootpos = searchmap[rootval];
	TreeNode* root = new TreeNode(rootval);
	if (preBegin == preEnd)
	{
		return root;
	}
	else
	{
		int leftNodes = rootpos - inBegin, rightNodes = inEnd - rootpos;
		root->left = setNode(preorder, preBegin + 1, preBegin+leftNodes, inorder, inBegin, rootpos-1);
		root->right = setNode(preorder, preBegin + 1+leftNodes, preEnd, inorder, rootpos + 1, inEnd);
		return root;
	}
	
}

//10.1.斐波那契数列
int Sword::fib(int n)
{
	if (n <= 1)
		return n;
	int num1 = 0;
	int num2 = 1;
	int num3;
	for (int i = 1; i < n; i++)
	{
		num3 = (num1 + num2) % 1000000007;
		num1 = num2;
		num2 = num3;
	}
	return num3;
}

//10.2.青蛙跳台阶问题
int Sword::numWays(int n)
{
	if (n <= 1) return 1;
	int a = 1, b = 1;
	int sum;
	for (int i = 1; i < n; i++)
	{
		sum = (a + b) % 1000000007;
		a = b;
		b = sum;
	}
	return sum;
}

//11. 旋转数组的最小数字
int Sword::minArray(vector<int>& numbers)
{
	int left = 0;
	int right = numbers.size() - 1;

	while (left < right)
	{
		int mid = left + (right - left) / 2;
        if (numbers[mid] < numbers[right])
		{
			right = mid;
		}
		else if (numbers[mid] > numbers[right])
		{
			left = mid + 1;
		}
		else
		{
			right -= 1;
		}
	}
	return numbers[left];
}