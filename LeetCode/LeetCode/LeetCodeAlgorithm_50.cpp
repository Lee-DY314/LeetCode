#include "LeetCodeAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map> 
#include <cstdlib>
#include <string>

using namespace std;

Solution::Solution()
{
}

Solution::~Solution()
{
}


//15. 三数之和
vector<vector<int>> Solution::threeSum(vector<int>& nums) 
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	vector<vector<int>> res;
	for (int first = 0; first<n; first++)
	{
		if (first > 0 && nums[first] == nums[first - 1])
		{
			continue;
		}
		int third = n - 1;
		int target = -nums[first];
		for (int second = first + 1; second<n; second++)
		{
			if (second > first + 1 && nums[second] == nums[second - 1])
			{
				continue;
			}
			while (second<third && nums[second] + nums[third] > target)
			{
				third--;
				continue;
			}
			if (second == third)
			{
				break;
			}
			if (nums[second] + nums[third] == target)
			{
				res.push_back({ nums[first],nums[second],nums[third] });
			}
		}
	}
	return res;
}


//16. 最接近的三数之和
int Solution::threeSumClosest(vector<int>& nums, int target)
{
	int n = nums.size();
	sort(nums.begin(), nums.end());
	int min = 1e7;

	// 定义一个小函数的新方法
	// 根据差值的绝对值来更新答案
	auto update = [&](int cur) {
		if (abs(cur - target) < abs(min - target)) {
			min = cur;
		}
	};

	for (int first = 0; first < n; first++)
	{
		if (first > 0 && nums[first] == nums[first - 1])
		{
			continue;
		}
		int second = first + 1;
		int third = n - 1;
		while (second < third)
		{
			int sum = nums[first] + nums[second] + nums[third];
			if (sum == target)    return target;
			update(sum);

			if (sum < target)
			{
				int temp = second + 1;
				while (temp < third && nums[second] == nums[temp])
					temp++;
				second = temp;
			}
			else
			{
				int temp = third - 1;
				while (second < temp && nums[third] == nums[temp])
					temp--;
				third = temp;
			}
		}
	}
	return min;
}


//17.电话号码的字母组合
map<char, string> phoneMap = {
	{ '2',"abc" },
	{ '3',"def" },
	{ '4',"ghi" },
	{ '5',"jkl" },
	{ '6',"mno" },
	{ '7',"pqrs" },
	{ '8',"tuv" },
	{ '9',"wxyz" }
};

vector<string> ans_17;
string current_17;

void Solution::DFS(int index , string digits)
{
	//出口
	if (index == digits.size())
	{
		ans_17.push_back(current_17);
		return;
	}

	//递归调用
	//对于当前输入的第index号数字(digits[index])
	//枚举其对应的所有字母(M[digits[index]][i])
	for (int i = 0; i < phoneMap[digits[index]].size(); i++)
	{
		current_17.push_back(phoneMap[digits[index]][i]);
		DFS(index + 1, digits);
		current_17.pop_back();
	}
}

vector<string> Solution::letterCombinations(string digits)
{
	int n = digits.size();
	if (n == 0) return ans_17;
	DFS(0, digits);
	return ans_17;
}


//18.四数之和
vector<vector<int>> Solution::fourSum(vector<int>& nums, int target)
{
	vector<vector<int>> ans;
	int n = nums.size();
	sort(nums.begin(), nums.end());
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && nums[i] == nums[i - 1])
			continue;
		for (int j = i + 1; j < n-1; j++)
		{
			if (j > i + 1 && nums[j] == nums[j - 1])
				continue;
			int k = j + 1;
			int l = n - 1;
			int sum = target - nums[i] - nums[j];
			while (k < l)
			{
				if (k > j + 1 && nums[k] == nums[k - 1])
				{
					k++;
					continue;
				}
				if (l < n - 1 && nums[l] == nums[l + 1])
				{
					l--;
					continue;
				}
				if (sum > nums[k] + nums[l])
				{
					k++;
					continue;
				}
				if (sum < nums[k] + nums[l])
				{
					l--;
					continue;
				}
				ans.push_back({nums[i], nums[j], nums[k], nums[l]});
				k++;
			}
		}
	}
	return ans;
}


//19.删除链表的倒数第n个节点
ListNode* Solution::removeNthFromEnd(ListNode* head, int n)
{
	ListNode* dummyhead = new ListNode(0);
	dummyhead->next = head;

	ListNode* p = dummyhead;
	ListNode* q = dummyhead;

	for (int i = 0; i <= n; i++)
	{
		p = p->next;
	}

	while (p)
	{
		p = p -> next;
		q = q -> next;
	}

	ListNode* delNode = q->next;
	q->next = delNode->next;
	delete delNode;

	ListNode* curNode = dummyhead->next;
	delete dummyhead;

	return curNode;
}

//22.括号生成
vector<string> Solution::generateParenthesis(int n)
{
	vector<string> ans;
	string cur;
	generateParenthesisHelper(ans, cur, 0, 0, n);
	return ans;
};

void Solution::generateParenthesisHelper(vector<string>& ans,string& cur,int left,int right,int n)
{
	if (cur.size() == n*2)
	{
		ans.push_back(cur);
		return;
	}
	if (left < n)
	{
        cur += '(';
		generateParenthesisHelper(ans, cur, left + 1, right, n);
		cur.pop_back();
	}
	if (right < left)
	{
		cur += ')';
		generateParenthesisHelper(ans, cur, left, right + 1, n);
		cur.pop_back();
	}
	
}

//24.两两交换链表中的节点
ListNode* Solution::swapPairs(ListNode* head) 
{
	if (!head || !(head->next)) return head;
	ListNode* dummy = new ListNode(-1);
	dummy->next = head;
	ListNode* preNode = dummy;
	
	while((head != NULL) && (head->next != NULL))
	{
		ListNode* p = head;
		ListNode* q = head->next;


		preNode->next = q;
		p->next = q->next;
		q->next = p;

		preNode = p;
		head = p->next;
		
	}
	return dummy->next;
}

//29.两数相除
int Solution::divide(int dividend, int divisor)
{
	if (dividend == 0) return 0;
	if (divisor == 0) return INT_MAX;
	int count = -1;

	int sign = 1;
	if (dividend>0)
	{
		if (divisor>0)
		{
			dividend = 0 - dividend;
			divisor = 0 - divisor;
		}
		else
		{
			dividend = 0 - dividend;
			sign = -1;
		}
	}
	else
	{
		if (divisor>0)
		{
			divisor = 0 - divisor;
			sign = -1;
		}
	}

	while (dividend <= 0)
	{
		dividend = dividend - divisor;
		if (count == INT_MAX)
			return INT_MAX;
		count++;
	}
	if (sign<0)
	{
		count = 0 - count;
	}
	return count;
}

//31.下一个排列
void Solution::nextPermutation(vector<int>& nums) 
{
	int n = nums.size();
	int sign = 0;
	int i = n - 1;
	while (i > 0 && nums[i] <= nums[i - 1])
	{
		i--;
	}
	if (i == 0)
	{
		sort(nums.begin(), nums.end());
		return ;
	}
	reverse(nums.begin() + i, nums.end());

	for (int j = i; j < n; j++)
	{
		if (nums[j] > nums[i - 1])
		{
			int temp = nums[i - 1];
			nums[i - 1] = nums[j];
			nums[j] = temp;
			break;
		}
	}

	return;

}

//33.搜索旋转排序数组
int Solution::search(vector<int>& nums, int target) 
{
	int n = nums.size();
	if (n == 0) return -1;
	int left = 0, right = n - 1;
	int mid = (left + right + 1) / 2;
	while (left < right)
	{
		if (target == nums[left]) return left;
		if (target == nums[right]) return right;
		mid = (left + right + 1) / 2;
		if (target == nums[mid]) return mid;
		if (nums[left] < target)
		{
			if (nums[left] > nums[mid])
			{
				right = mid - 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		else if (nums[right] > target)
		{
			if (nums[right] < nums[mid])
			{
				left = mid + 1;
			}
			else if (nums[mid] < target)
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		else
		{
			return -1;
		}

	}
	return -1;
}

//43.字符串相乘
string Solution::multiply(string num1, string num2)
{
	int n1 = num1.size();
	int n2 = num2.size();
	vector<string> sum;
	string ans;
	if (num1 == "0" || num2 == "0") {
		return "0";
	}
	int sign = 0;
	for (int i = n1 - 1; i >= 0; i--)
	{
		int curNum1 = num1[i] - '0';
		string tempstr;
		for (int j = n2 - 1; j >= 0; j--)
		{
			int curNum2 = num2[j] - '0';
			int mult = curNum1 * curNum2 + sign;
			sign = mult / 10;
			mult = mult % 10;

			tempstr = to_string(mult) + tempstr;
		}
		if (sign != 0)
		{
			tempstr = to_string(sign) + tempstr;
			sign = 0;
		}
		for (int k = 0; k < n1 - i -1; k++)
		{
			tempstr = tempstr + '0';
		}
		sum.push_back(tempstr);
	}
	int size = sum.size();
	int len = sum[size-1].size();
	for (int i= 0; i < size-1; i++)
	{
		int n = len - sum[i].size();
		for (int j = 0; j < n; j++)
		{
			sum[i] = '0' + sum[i];
		}
	}
	sign = 0;
	for (int i = len-1; i >= 0; i--)
	{
		int temp = sign;
		for (int j = 0; j < size; j++)
		{
			temp += sum[j][i] -'0';
		}
		sign = temp / 10;
		temp = temp % 10;

		ans = to_string(temp) + ans;
	}
	if (sign != 0)
	{
		ans = to_string(sign) + ans;
	}
	return ans;
}



