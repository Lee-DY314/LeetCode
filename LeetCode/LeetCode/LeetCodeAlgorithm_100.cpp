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

//55. Ã¯‘æ”Œœ∑
bool Solution::canJump(vector<int>& nums)
{
	int len = nums.size();
	int farpos = nums[0];
	if (len == 1 && farpos == 0) return true;
	for (int i = 1; i <= farpos; i++)
	{
		if (farpos >= len - 1)
			return true;
		farpos = max(farpos, i + nums[i]);
	}
	return false;
}