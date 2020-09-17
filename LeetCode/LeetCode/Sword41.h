#pragma once
#include"LeetCodeAlgorithm.h"
#include <vector>
#include <queue>

using namespace std;

class MedianFinder {

private:
	int size;
	double midNum;
	ListNode* head;

public:
	/** initialize your data structure here. */
	MedianFinder() {
		size = 0;
		head = new ListNode(0);
	}

	void addNum(int num)
	{
		ListNode* temp = new ListNode(num);
		if (head->next == nullptr)
		{
			head->next = temp;
			size++;
			midNum = num;
			return;
		}

		ListNode* ptr = head;
		while (ptr->next != nullptr)
		{
			if (num < ptr->next->val)
			{
				temp->next = ptr->next;
				ptr->next = temp;
				size++;
				return;
			}
			ptr = ptr->next;
		}

		ptr->next = temp;
		size++;

		return;
	}

	double findMedian() 
	{
		ListNode* ptr = head;

		if (size % 2 == 1)
		{
			for (int i = 0; i <= size/2; i++)
			{
				ptr = ptr->next;
			}
			midNum = ptr->val;
		}
		else
		{
			for (int i = 0; i < size / 2; i++)
			{
				ptr = ptr->next;
			}
			int sum = ptr->val + ptr->next->val;
			midNum = (double)sum / 2;
		}
		return midNum;
	}


};

class MedianFinder1
{
private:
	struct greater {
		bool operator()(int &a, int &b)
		{
			return a < b;
		}
	};

public:
	priority_queue<int> low;
	priority_queue<int, vector<int>,  greater> high;

	void addNum(int num)
	{
		low.push(num);
		high.push(low.top());
		low.pop();
		if (low.size() < high.size())
		{
			low.push(high.top());
			high.pop();
		}
	}

	double findMedian()
	{
		return low.size() > high.size() ? (double)low.top() : (low.top() + high.top())*0.5;
	}

};
/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder* obj = new MedianFinder();
* obj->addNum(num);
* double param_2 = obj->findMedian();
*/