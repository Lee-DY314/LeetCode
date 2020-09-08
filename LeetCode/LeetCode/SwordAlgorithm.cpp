#include "SwordAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map> 
#include <cstdlib>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>

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

//12.矩阵中的路径
bool Sword::exist(vector<vector<char>>& board, string word)
{
	//遍历找到路径的起始位置，找不到直接返回false
	int xlen = board.size();
	int ylen = board[0].size();
	for (int i = 0; i < xlen; i++)
	{
		for (int j = 0; j < ylen; j++)
		{
			if (dfs_12(board,word,i,j,0))
			{
				return true;
			}
		}
	}
	return false;
}

bool Sword::dfs_12(vector<vector<char>>& board, string word, int i, int j, int k)
{
	if (i >= board.size() || i < 0 
		|| j >= board[0].size() || j < 0 
		|| board[i][j] != word[k])
		return false;
	if (k == word.size() - 1) return true;
	char temp = board[i][j];
	board[i][j] = '/';
	bool res = dfs_12(board, word, i + 1, j, k + 1) 
		|| dfs_12(board, word, i - 1, j, k + 1)
		|| dfs_12(board, word, i, j + 1, k + 1)
		|| dfs_12(board, word, i, j - 1, k + 1);
	board[i][j] = temp;
	return res;
}

//13.机器人的运动范围
//深度优先搜索
int count_13 = 0;
int Sword::movingCount(int m, int n, int k)
{
	vector<vector<int>> arr(m, vector<int>(n, 0));
	if (k == 0) return 1;
	dfs_13(0, 0, m, n, k,arr);
	return count_13;
}

void Sword::dfs_13(int i,int j,int m, int n, int k, vector<vector<int>>& arr)
{
	if (i<0 || i>=m || j<0 || j>=n) return;
	if (arr[i][j] == 1) return;
	int sum = i / 10 + i % 10 + j / 10 + j % 10;
	if (sum > k) return;
	arr[i][j] = 1;
	count_13++;
	dfs_13(i + 1, j, m, n, k, arr);
	dfs_13(i - 1, j, m, n, k, arr);
	dfs_13(i, j + 1, m, n, k, arr);
	dfs_13(i, j - 1, m, n, k, arr);
	return;
}

//广度优先搜索

//int Sword::movingCount(int m, int n, int k)
//{
//	if (k == 0) return 1;
//	vector<vector<int>> visited(m, vector<int>(n, 0));
//	queue<pair<int, int>> que;
//	vector<pair<int, int>> directions = { { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 } };
//	que.push({ 0,0 });
//	visited[0][0] = 1;
//	int ans = 0;
//	while (!que.empty())
//	{
//		auto front = que.front();
//		que.pop();
//		int x = front.first;
//		int y = front.second;
//		ans++;
//		for (auto d : directions)
//		{
//			int new_x = x + d.first;
//			int new_y = y + d.second;
//			if (new_x < 0 || new_x >= m || new_y<0 || new_y >= n
//				|| visited[new_x][new_y] == 1
//				|| new_x / 10 + new_x % 10 + new_y / 10 + new_y % 10 >k)
//			{
//				continue;
//			}
//			que.push({ new_x,new_y });
//			visited[new_x][new_y] = 1;
//		}
//	}
//	return ans;
//}

//14.1.剪绳子1
int Sword::cuttingRope_1(int n)
{
	if (n < 4)
		return n - 1;
	else if (n == 4)
		return 4;

	int mult = 1;
	while (n > 4)
	{
		mult *= 3;
		n -= 3;
	}
	if (n == 0)
		return mult;
	else
		return mult*n;
}

//14.2.剪绳子2
int Sword::cuttingRope_2(int n)
{
	if (n < 4)
		return n - 1;
	else if (n == 4)
		return 4;
	int b = n % 3, a = n / 3 - 1, p = 1000000007;
	long mult = 1, x = 3;
	
	//快速幂
	for(;a>0;a/=2)
	{
		if (a % 2 == 1) mult = (mult * x) % p;
		x = (x*x) % p;
	}

	if (b == 0)
		return (int)(mult * 3 % p);
	else if (b == 1)
		return (int)(mult * 4 % p);
	else
		return (int)(mult * 6 % p);
}

//15.二进制中1的个数
int Sword::hammingWeight(uint32_t n) 
{
	int count = 0;
	while (n > 0)
	{
		if (n < 3)
		{
			count++;
			break;
		}
		uint64_t a = 1;
		while (n >= a * 2)
		{
			if (a!=1 && (n / a > a))
			{
				a = a*a;
				continue;
			}
			a *= 2;
		}
		int sign = n / a;
		if (sign != 0) count++;
		n = n - a;
	}
	return count;
}

//上面的太麻烦了，考的应该是位运算
int Sword::hammingWeight(uint32_t n,int a)
{
	int count = 0;
	//for (int i=0;i<32;i++)
	//{
	//	if ((n & 1) == 1)
	//	{
	//		count++;
	//	}
	//	n = n >> 1;
	//}
	while (n != 0)
	{
		if ((n & 1) == 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}

//进阶版
int Sword::hammingWeight(uint32_t n, int a, int b)
{
	int count = 0;
	while (n)
	{
		n = n&(n - 1);
		count++;
	}
	return count;
}

//16.数值的整数次方
double Sword::myPow(double x, int n)
{
	if (x == 0) return 0;
	long b = n;
	if (n < 0)
	{
		x = 1 / x;
		b = 0 - b;
	}
	double ans = 1;
	while (b > 0)
	{
		if (b & 1)
			ans *= x;
		x *= x;
		b=b >> 1;
	}
	return ans;
}

//17. 打印从1到最大的n位数
vector<int> Sword::printNumbers(int n)
{
	vector<int> ans;
	int num = pow(10,n) - 1;
	for (int i = 0; i < num; i++)
	{
		ans.push_back(i + 1);
	}
	return ans;
}
//还可以用char或者string来做

//18.删除链表的节点
ListNode* Sword::deleteNode(ListNode* head, int val)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = head;
	ListNode* first = head;
	ListNode* second = dummy;
	while (first != nullptr)
	{
		if (first->val == val)
		{
			second->next = first->next;
			delete first;//在leetcode的ide上，为啥这里如果delete了头结点，之后就会报错？明明vs里没问题
			break;
		}
		first = first->next;
		second = second->next;
	}
	return dummy->next;
}

//19.正则表达式的匹配
bool Sword::isMatch(string s, string p)
{
	if (p.empty()) {
		return s.empty();
	}

	// 前面加某一相同字符，
	// 防止 (ab, c*ab) 这样的匹配，
	// 避免复杂的初始化操作
	s = " " + s;
	p = " " + p;
	int m = s.size(), n = p.size();

	// 定义记忆数组，并初始化为false
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

	// 设添加的字符为真
	dp[0][0] = true;

	// 记忆数组能保持字符串上一个字符的状态
	// 因此可以对下一个字符进行判断
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			// 不带 '*' 号时的匹配
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') {
				// 考虑 '*' 时的两种情况
				if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
					dp[i][j] = dp[i][j - 2];
				}
				else {
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
				}
			}
		}
	}

	// 返回最后字符的匹配状态
	return dp[m][n];

	//作者：OOOffer
	//	链接：https ://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/hui-su-fa-dong-tai-gui-hua-by-luo-jing-yu-yu/
	//来源：力扣（LeetCode）
	//	著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
}

//20. 表示数值的字符串public:	

Sword::CharType Sword::toCharType(char ch) {
	if (ch >= '0' && ch <= '9') {
		return CHAR_NUMBER;
	}
	else if (ch == 'e' || ch == 'E') {
		return CHAR_EXP;
	}
	else if (ch == '.') {
		return CHAR_POINT;
	}
	else if (ch == '+' || ch == '-') {
		return CHAR_SIGN;
	}
	else if (ch == ' ') {
		return CHAR_SPACE;
	}
	else {
		return CHAR_ILLEGAL;
	}
}

bool Sword::isNumber(string s) {
	unordered_map<State, unordered_map<CharType, State>> transfer{
		{
			STATE_INITIAL,{
				{ CHAR_SPACE, STATE_INITIAL },
				{ CHAR_NUMBER, STATE_INTEGER },
				{ CHAR_POINT, STATE_POINT_WITHOUT_INT },
				{ CHAR_SIGN, STATE_INT_SIGN },
			}
		},{
			STATE_INT_SIGN,{
				{ CHAR_NUMBER, STATE_INTEGER },
				{ CHAR_POINT, STATE_POINT_WITHOUT_INT },
			}
		},{
			STATE_INTEGER,{
				{ CHAR_NUMBER, STATE_INTEGER },
				{ CHAR_EXP, STATE_EXP },
				{ CHAR_POINT, STATE_POINT },
				{ CHAR_SPACE, STATE_END },
			}
		},{
			STATE_POINT,{
				{ CHAR_NUMBER, STATE_FRACTION },
				{ CHAR_EXP, STATE_EXP },
				{ CHAR_SPACE, STATE_END },
			}
		},{
			STATE_POINT_WITHOUT_INT,{
				{ CHAR_NUMBER, STATE_FRACTION },
			}
		},{
			STATE_FRACTION,
			{
				{ CHAR_NUMBER, STATE_FRACTION },
				{ CHAR_EXP, STATE_EXP },
				{ CHAR_SPACE, STATE_END },
			}
		},{
			STATE_EXP,
			{
				{ CHAR_NUMBER, STATE_EXP_NUMBER },
				{ CHAR_SIGN, STATE_EXP_SIGN },
			}
		},{
			STATE_EXP_SIGN,{
				{ CHAR_NUMBER, STATE_EXP_NUMBER },
			}
		},{
			STATE_EXP_NUMBER,{
				{ CHAR_NUMBER, STATE_EXP_NUMBER },
				{ CHAR_SPACE, STATE_END },
			}
		},{
			STATE_END,{
				{ CHAR_SPACE, STATE_END },
			}
		}
	};

	int len = s.length();
	State st = STATE_INITIAL;

	for (int i = 0; i < len; i++) {
		CharType typ = toCharType(s[i]);
		if (transfer[st].find(typ) == transfer[st].end()) {
			return false;
		}
		else {
			st = transfer[st][typ];
		}
	}
	return st == STATE_INTEGER || st == STATE_POINT || st == STATE_FRACTION || st == STATE_EXP_NUMBER || st == STATE_END;
}

//作者：LeetCode - Solution
//链接：https ://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/biao-shi-shu-zhi-de-zi-fu-chuan-by-leetcode-soluti/
//来源：力扣（LeetCode）

//21.调整数组顺序使奇数位于偶数前面
vector<int> Sword::exchange(vector<int>& nums) 
{
	int len = nums.size();
	int left = 0, right = len - 1;
	while (left < right)
	{
		while (left<len && nums[left] % 2 == 1)
		{
			left++;
		}
		while (right>=0 && nums[right] % 2 == 0)
		{
			right--;
		}
		if (left >= right) break;
		int temp = nums[left];
		nums[left] = nums[right];
		nums[right] = temp;
	}
	return nums;
}

//22.链表中的倒数第k个节点
ListNode* Sword::getKthFromEnd(ListNode* head, int k)
{
	ListNode* fast = head;
	ListNode* slow = head;
	for (int i = 0; i < k; i++)
	{
		fast = fast->next;
	}
	while (fast != nullptr)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

//25.合并两个排序链表
ListNode* Sword::mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* dummy = new ListNode(0);
	dummy->next = l1;
	ListNode* cur1 = l1;
	ListNode* pre = dummy;
	ListNode* cur2 = l2;
	while (cur2 != nullptr)
	{
		if (cur1 != nullptr)
		{
			int a = cur1->val;
			int b = cur2->val;
			if (a>b)
			{
				pre->next = cur2;
				pre = pre->next;
				cur2 = cur2->next;
				pre->next = cur1;
			}
			else
			{
				cur1 = cur1->next;
				pre = pre->next;
			}
		}
		else
		{
			pre->next = cur2;
			pre = pre->next;
			cur2 = cur2->next;
		}
	}
	return dummy->next;
}

//26. 树的子结构
bool Sword::isSubStructure(TreeNode* A, TreeNode* B)
{
	if (A == nullptr || B == nullptr)
		return false;
	bool ans = false;
	if (A->val == B->val)
	{
		ans = helper_26(A, B);
	}
	if (!ans)
	{
		ans = isSubStructure(A->left, B);
	}
	if (!ans)
	{
		ans = isSubStructure(A->right, B);
	}
	return ans;
}

bool Sword::helper_26(TreeNode* A, TreeNode* B)
{
	if (B == nullptr)
	{
		return true;
	}
	if (A == nullptr)
	{
		return false;
	}
	if (A->val != B->val)
	{
		return false;
	}
	return helper_26(A->left, B->left) && helper_26(A->right, B->right);
}

//27.二叉树的镜像
TreeNode* Sword::mirrorTree(TreeNode* root)
{
	if (root == nullptr) return root;
	if (root->left == nullptr && root->right == nullptr)
	{
		return root;
	}
	TreeNode* temp = root->left;
	root->left = root->right;
	root->right = temp;
	mirrorTree(root->left);
	mirrorTree(root->right);
	return root;
}

//28. 对称的二叉树
bool Sword::isSymmetric(TreeNode* root)
{
	if (root == nullptr) return true;
	if (root->left == nullptr && root->right == nullptr)
		return true;

	return helper_28(root->left,root->right);

}

bool Sword::helper_28(TreeNode* t1, TreeNode* t2)
{
	if (t1 == nullptr && t2 == nullptr)
		return true;
	else if (t1 == nullptr || t2 == nullptr)
		return false;
	else if (t1->val != t2->val)
	{
		return false;
	}
	else
		return helper_28(t1->left,t2->right) && helper_28(t1->right,t2->left);
}

//29.顺时针打印矩阵
vector<int> Sword::spiralOrder(vector<vector<int>>& matrix)
{
	vector<int> ans;
	int size = matrix.size();
	if (size == 0) return ans;
	int len = matrix[0].size();
	vector<vector<bool>> used(size, vector<bool>(len));
	int dir[4][2] = { {0,1},{1,0},{0,-1},{-1,0} };
	int c = 0, r = 0, tur = 0;
	for (int i = 0; i < size*len; i++)
	{
		if (r == size || c == len || (r== size-1 && c<0) || used[r][c] == true)
		{
			r -= dir[tur][0];
			c -= dir[tur][1];
			tur++;
			tur = tur % 4;
			r += dir[tur][0];
			c += dir[tur][1];
		}
		ans.push_back(matrix[r][c]);
		used[r][c] = true;
		r += dir[tur][0];
		c += dir[tur][1];
	}
	return ans;
}

//31. 栈的压入、弹出序列
bool Sword::validateStackSequences(vector<int>& pushed, vector<int>& popped) 
{
	stack<int> op;
	int len = popped.size();
	int index = 0;
	for(int i=0;i<len;i++)
	{
		op.push(pushed[i]);
		while (!op.empty() && op.top() == popped[index])
		{
			op.pop();
			index++;
		}
	}
	return op.empty();
}

//32 - I.从上到下打印二叉树
vector<int> Sword::levelOrder_1(TreeNode* root)
{
	queue<TreeNode*> que;
	vector<int> ans;
	if (root != nullptr)
	{
		que.push(root);
	}
	while (!que.empty())
	{
		TreeNode* temp = que.front();
		ans.push_back(temp->val);
		if(temp->left != nullptr)
		    que.push(temp->left);
		if (temp->right != nullptr)
		    que.push(temp->right);
		que.pop();
	}
	return ans;
}

//32 - II.从上到下打印二叉树II
vector<vector<int>> Sword::levelOrder_2(TreeNode* root)
{
	queue<TreeNode*> que;
	vector<vector<int>> ans;
	if (root == nullptr)
		return ans;
	que.push(root);
	int index;
	while (!que.empty())
	{
		int len = que.size();
		vector<int> tempVec;
		for (int i = 0; i < len; i++)
		{
			TreeNode* temp = que.front();
			tempVec.push_back(temp->val);
			que.pop();
			if (temp->left != nullptr)
			{
				que.push(temp->left);
			}
			if (temp->right != nullptr)
			{
				que.push(temp->right);
			}
		}
		ans.push_back(tempVec);
	}
	return ans;
}

//32 - III. 从上到下打印二叉树 III
vector<vector<int>> Sword::levelOrder_3(TreeNode* root)
{
	if (root == nullptr)
	{
		return{};
	}
	deque<TreeNode*> dq;
	vector<vector<int>> ans;
	dq.push_back(root);
	int level = 0;
	while (!dq.empty())
	{
		int len = dq.size();
		vector<int> temp;
		if(level == 0)
		{
			while (len > 0)
			{
				TreeNode* node = dq.front();
				temp.push_back(node->val);
				dq.pop_front();
				if (node->left != nullptr)
					dq.push_back(node->left);
				if (node->right != nullptr)
					dq.push_back(node->right);
				len--;
			}
			level = 1;
		}
		else
		{
			while (len > 0)
			{
				TreeNode* node = dq.back();
				temp.push_back(node->val);
				dq.pop_back();
				if (node->right != nullptr)
					dq.push_front(node->right);
				if (node->left != nullptr)
					dq.push_front(node->left);
				len--;
			}
			level = 0;
		}
		ans.push_back(temp);
	}
	return ans;
}

//33.二叉搜索树的后序遍历序列
bool Sword::verifyPostorder(vector<int>& postorder)
{
	int len = postorder.size();
	if (len < 3)
	{
		return true;
	}
	bool ans = helper_33(postorder, 0, len - 1);
	return ans;
}

bool Sword::helper_33(vector<int>& postorder, int start, int end)
{
	if (postorder.size() == 0 || start > end)
		return true;
	int root = postorder[end];
	int index = start;

	for (;index<end;index++)
	{
		if (postorder[index] > root)
		{
			break;
		}
	}

	for (int i = index; i < end; i++)
	{
		if (postorder[i] < root)
			return false;
	}
	bool left = true;
	if (index > start)
	{
		left = helper_33(postorder, start, index - 1);
	}
	bool right = true;
	if (index < end)
		right = helper_33(postorder, index, end - 1);
	return left && right;
}

//34. 二叉树中和为某一值的路径
vector<vector<int>> ans_34;
vector<int> temp_34;
vector<vector<int>> Sword::pathSum(TreeNode* root, int sum)
{
	if (root == nullptr)
		return ans_34;

	helper_34(root, sum);
	return ans_34;
}

void Sword::helper_34(TreeNode* root, int target)
{
	if (root == nullptr)
		return;

	int cur = root->val;
    temp_34.emplace_back(cur);
	target = target - cur;

	if (root->left == nullptr && root->right == nullptr && target == 0)
	{
		ans_34.emplace_back(temp_34);
	}
	helper_34(root->left, target);
	helper_34(root->right, target);
	temp_34.pop_back();
	return;
}


//KMP
void Sword::getNext(string T, int *next)
{
	int i = 1, j = 0;
	int len = T.size();
	next[1] = 0;
	while (i < len)
	{
		if (j == 0 || T[i] == T[j])
		{
			i++;
			j++;
			next[i] = j;
		}
		else
		{
			j = next[j];
		}
	}
}
