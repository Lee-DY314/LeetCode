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

