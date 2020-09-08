#pragma once
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include "SwordAlgorithm.h"

using namespace std;

/**
* Your MinStack object will be instantiated and called as such:
* MinStack* obj = new MinStack();
* obj->push(x);
* obj->pop();
* int param_3 = obj->top();
* int param_4 = obj->min();
*/

class MinStack {
public:
	/** initialize your data structure here. */
	MinStack() {

	}

	void push(int x) {
		data.push_back(x);
		int len1 = data.size();
		int len2 = minNum.size();
		if (len2 == 0)
		{
			minNum.push_back(x);
			return;
		}

		int a = minNum[len2 - 1];
		if (a > x)
		{
			minNum.push_back(x);
		}
		else
		{
			minNum.push_back(a);
		}
	}

	void pop() {
		data.pop_back();
		minNum.pop_back();
	}

	int top() {
		int len = data.size();
		return data[len - 1];
	}

	int min() {
		int len = data.size();
		return minNum[len-1];
	}
private:
	vector<int> data;
	vector<int> minNum;
};