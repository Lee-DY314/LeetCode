#include "SwordAlgorithm.h"
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cmath>
#include <map> 
#include <cstdlib>
#include <string>
#include <queue>
#include <unordered_map>
#include <stack>
#include <set>

using namespace std;

Sword::Sword()
{
}

Sword::~Sword()
{
}


//04.��ά�����еĲ���

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


//06.��β��ͷ��ӡ����
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

//07.�ؽ�������
map<int, int> searchmap;

TreeNode* Sword::buildTree(vector<int>& preorder, vector<int>& inorder) 
{
	for (int i = 0; i < inorder.size(); i++)
	{
		searchmap.insert(pair<int, int>(inorder[i],i));
		//��һ�ַ�ʽ
		//searchmap[i] = inorder[i];
	}

	return setNode(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
}

//����ͨ�� ����ԭ�����ĵ����������½����� ���ٿռ临�Ӷ�
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

//10.1.쳲���������
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

//10.2.������̨������
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

//11. ��ת�������С����
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

//12.�����е�·��
bool Sword::exist(vector<vector<char>>& board, string word)
{
	//�����ҵ�·������ʼλ�ã��Ҳ���ֱ�ӷ���false
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

//13.�����˵��˶���Χ
//�����������
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

//�����������

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

//14.1.������1
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

//14.2.������2
int Sword::cuttingRope_2(int n)
{
	if (n < 4)
		return n - 1;
	else if (n == 4)
		return 4;
	int b = n % 3, a = n / 3 - 1, p = 1000000007;
	long mult = 1, x = 3;
	
	//������
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

//15.��������1�ĸ���
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

//�����̫�鷳�ˣ�����Ӧ����λ����
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

//���װ�
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

//16.��ֵ�������η�
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

//17. ��ӡ��1������nλ��
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
//��������char����string����

//18.ɾ������Ľڵ�
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
			delete first;//��leetcode��ide�ϣ�Ϊɶ�������delete��ͷ��㣬֮��ͻᱨ������vs��û����
			break;
		}
		first = first->next;
		second = second->next;
	}
	return dummy->next;
}

//19.������ʽ��ƥ��
bool Sword::isMatch(string s, string p)
{
	if (p.empty()) {
		return s.empty();
	}

	// ǰ���ĳһ��ͬ�ַ���
	// ��ֹ (ab, c*ab) ������ƥ�䣬
	// ���⸴�ӵĳ�ʼ������
	s = " " + s;
	p = " " + p;
	int m = s.size(), n = p.size();

	// ����������飬����ʼ��Ϊfalse
	std::vector<std::vector<bool>> dp(m + 1, std::vector<bool>(n + 1, false));

	// ����ӵ��ַ�Ϊ��
	dp[0][0] = true;

	// ���������ܱ����ַ�����һ���ַ���״̬
	// ��˿��Զ���һ���ַ������ж�
	for (int i = 1; i < m + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			// ���� '*' ��ʱ��ƥ��
			if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
				dp[i][j] = dp[i - 1][j - 1];
			}
			else if (p[j - 1] == '*') {
				// ���� '*' ʱ���������
				if (s[i - 1] != p[j - 2] && p[j - 2] != '.') {
					dp[i][j] = dp[i][j - 2];
				}
				else {
					dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
				}
			}
		}
	}

	// ��������ַ���ƥ��״̬
	return dp[m][n];

	//���ߣ�OOOffer
	//	���ӣ�https ://leetcode-cn.com/problems/zheng-ze-biao-da-shi-pi-pei-lcof/solution/hui-su-fa-dong-tai-gui-hua-by-luo-jing-yu-yu/
	//��Դ�����ۣ�LeetCode��
	//	����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������
}

//20. ��ʾ��ֵ���ַ���public:	

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

//���ߣ�LeetCode - Solution
//���ӣ�https ://leetcode-cn.com/problems/biao-shi-shu-zhi-de-zi-fu-chuan-lcof/solution/biao-shi-shu-zhi-de-zi-fu-chuan-by-leetcode-soluti/
//��Դ�����ۣ�LeetCode��

//21.��������˳��ʹ����λ��ż��ǰ��
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

//22.�����еĵ�����k���ڵ�
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

//25.�ϲ�������������
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

//26. �����ӽṹ
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

//27.�������ľ���
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

//28. �ԳƵĶ�����
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

//29.˳ʱ���ӡ����
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

//31. ջ��ѹ�롢��������
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

//32 - I.���ϵ��´�ӡ������
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

//32 - II.���ϵ��´�ӡ������II
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

//32 - III. ���ϵ��´�ӡ������ III
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

//33.�����������ĺ����������
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

//34. �������к�Ϊĳһֵ��·��
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

//35.��������ĸ���
Node* Sword::copyRandomList(Node* head)
{
	if (head == nullptr)
	{
		return head;
	}
	unordered_map<Node*, Node*> map;
	Node* t = head;
	while (t != nullptr)
	{
		map[t] = new Node(t->val);
		t = t->next;
	}
	t = head;
	while (t != nullptr)
	{
		if (t->next != nullptr)
		{
			map[t]->next = map[t->next];
		}
		if (t->random != nullptr)
		{
			map[t]->random = map[t->random];
		}
		t = t->next;
	}
	return map[head];
}

//36. ������������˫������
DLNode* pre, *head;
DLNode* Sword::treeToDoublyList(DLNode* root)
{
	if (root == nullptr) return nullptr;
	helper_36(root);
	head->left = pre;
	pre->right = head;
	return head;
}

void Sword::helper_36(DLNode* cur)
{
	if (cur == nullptr) return;
	helper_36(cur->left);

	if (pre != nullptr)
	{
		pre -> right = cur;
	}
	else
	{
		head = cur;
	}
	cur->left = pre;
	pre = cur;

	helper_36(cur->right);
}


//37. ���л�������(̫���ˣ�ֱ�ӳ���
// Encodes a tree to a single string.
string Sword::serialize(TreeNode* root) {
	ostringstream out;
	queue<TreeNode*> q;
	q.push(root);
	while (!q.empty()) {
		TreeNode* tmp = q.front();
		q.pop();
		if (tmp) {
			out << tmp->val << " ";
			q.push(tmp->left);
			q.push(tmp->right);
		}
		else {
			out << "null ";
		}
	}
	return out.str();
}

// Decodes your encoded data to tree.
TreeNode* Sword::deserialize(string data)
{
	istringstream input(data);
	string val;
	vector<TreeNode*> vec;
	while (input >> val)
	{
		if (val == "null")
			vec.push_back(nullptr);
		else
		{
			TreeNode* temp = new TreeNode(stoi(val));
			vec.push_back(temp);
		}
	}
	int j = 1;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] == nullptr)
			continue;
		if (j < vec.size())
			vec[i]->left = vec[j++];
		if (j < vec.size())
			vec[i]->right = vec[j++];
	}
	return vec[0];
}

//38.�ַ���������

//��ʱ��
//vector<string> Sword::permutation(string s)
//{
//	int len = s.size();
//	if (len == 0) return { "" };
//	vector<string> ans;
//	queue<string> que;
//	string s1;
//	s1.push_back(s[0]);
//	que.push(s1);
//	int pos = 0;
//	while (!que.empty())
//	{
//		string pre = que.front();
//		pos = pre.size() + 1;
//		if (pos > len)
//		{
//			break;
//		}
//		que.pop();
//		for (int j = 0; j < pos; j++)
//		{
//			string temp = pre;
//			temp.insert(j, 1, s[pos - 1]);
//			que.push(temp);
//		}
//	}
//	while (!que.empty())
//	{
//		string t = que.front();
//		que.pop();
//		int sign = 0;
//		for (int i = 0; i < ans.size(); i++)
//		{
//			if (t == ans[i])
//			{
//				sign = 1;
//				break;
//			}
//		}
//		if (sign == 1) continue;
//		ans.push_back(t);
//	}
//	return ans;
//}

//dfs
vector<string> ans_38;
vector<char> c;
vector<string> Sword::permutation(string s)
{
	for (int i = 0; i < s.size(); i++)
	{
		c.push_back(s[i]);
	}
	dfs(0);
	return ans_38;
}

void Sword::dfs(int x)
{
	if (x == c.size() - 1)
	{
		string res(c.begin(), c.end());
		ans_38.push_back(res);
		return;
	}
	set<char> c_set;
	for (int i = x; i < c.size(); i++)
	{
		if (c_set.count(c[i])) continue;
		c_set.insert(c[i]);
		swap(c[i], c[x]);
		dfs(x + 1);
		swap(c[i], c[x]);
	}
}

//39. �����г��ִ�������һ�������
//Ħ��ͶƱ���������������������
int Sword::majorityElement(vector<int>& nums)
{
	int votes = 1;
	int temp = nums[0];
	for (int i = 1; i < nums.size(); i++)
	{
		if (votes == 0)
		{
			temp = nums[i];
		}
		if (nums[i] == temp)
		{
			votes++;
		}
		else
		{
			votes--;
		}
	}

	int count = 0;
	for (int num : nums)
	{
		if (num == temp) count++;
	}
	return count > nums.size() / 2 ? temp : 0;
}

//40. ��С��k����
//����ѡ��
vector<int> Sword::getLeastNumbers(vector<int>& arr, int k)
{
	if (k == 0) return{};
	else if (arr.size() <= k)
		return arr;

	quickSelect(arr, 0, arr.size() - 1, k);
	vector<int> ans;
	for (int i = 0; i < k; i++)
	{
		ans.push_back(arr[i]);
	}
	return ans;
}

void Sword::quickSelect(vector<int>& arr, int left, int right, int k)
{
	int j = partition(arr, left, right);
	if (j == k)
	{
		return ;
	}
	if (j > k)
	{
		return quickSelect(arr, left, j - 1, k);
	}
	else
	{
		return quickSelect(arr, j + 1, right, k);
	}
}

int Sword::partition(vector<int>& arr, int left, int right)
{
	int i = left, j = right;
	int key = arr[left];
	while (true)
	{
		while (i < j && arr[j] >= key)
		{
			j--;
		}
		while (i < j && arr[i] <= key)
		{
			i++;
		}
		if (i < j)
		{
			int t = arr[i];
			arr[i] = arr[j];
			arr[j] = t;
		}
		else
		{
			break;
		}
	}
	arr[left] = arr[j];
	arr[j] = key;
	return j;
}

//�����
vector<int> Sword::getLeastNumbers(vector<int>& arr, int k, bool useheap)
{
	vector<int>vec(k, 0);
	if (k == 0) return vec; // �ų� 0 �����
	priority_queue<int>Q;
	for (int i = 0; i < k; ++i) Q.push(arr[i]);
	for (int i = k; i < (int)arr.size(); ++i) {
		if (Q.top() > arr[i]) {
			Q.pop();
			Q.push(arr[i]);
		}
	}
	for (int i = 0; i < k; ++i) {
		vec[i] = Q.top();
		Q.pop();
	}
	return vec;
}

//42. ���������������
int Sword::maxSubArray(vector<int>& nums)
{
	int len = nums.size();
	vector<int> max(len);//��i��ʼ��j���������ֵ
	max[0] = nums[0];
	for (int i = 1; i < len; i++)
	{
		int temp = max[i - 1] + nums[i];
		max[i] = temp > nums[i] ? temp : nums[i];
	}
	int ans = max[0];
	for (int i = 1; i < len; i++)
	{
		if (ans < max[i])
		{
			ans = max[i];
		}
	}
	return ans;
}

//43. 1��n������1���ֵĴ���
int Sword::countDigitOne(int n)
{
	int cur = n % 10;
	int res = 0;
	long digit = 1;
	int high = n / 10;
	int low = 0;
	while (high != 0 || cur != 0)
	{
		if (cur == 0)
		{
			res += high*digit;
		}
		else if (cur == 1)
		{
			res += high*digit + low + 1;
		}
		else
		{
			res += high*digit + digit;
		}
		low += digit*cur;
		cur = high % 10;
		high = high / 10;
		digit *= 10;
	}
	return res;
}

//44. ����������ĳһλ������
int Sword::findNthDigit(int n)
{
	// ����������ɼ�λ������ɣ���1λ��digits = 1��2λ��digits = 2...
	long base = 9, digits = 1;
	while (n - base * digits > 0) {
		n -= base * digits;
		base *= 10;
		digits++;
	}

	// ������ʵ����������Ƕ���
	int idx = n % digits;  // ע����������ļ��㣬n���ڱ�ʾdigitsλ���ĵ�n������
	if (idx == 0)idx = digits;
	long number = 1;
	for (int i = 1; i < digits; i++)
		number *= 10;
	number += (idx == digits) ? n / digits - 1 : n / digits;

	// ����ʵ���������ҵ�������Ҫ���Ǹ�����
	for (int i = idx; i<digits; i++) number /= 10;
	return number % 10;
}

//45. �������ų���С����
string Sword::minNumber(vector<int>& nums)
{
	vector<string> strs;
	for (int i = 0; i < nums.size(); i++)
	{
		strs.push_back(to_string(nums[i]));
	}
	fastSort(strs, 0, strs.size() - 1);
	string ans;
	for (string num : strs)
	{
		ans += num;
	}
	return ans;
}

void Sword::fastSort(vector<string>& strs, int left, int right)
{
	if (left >= right) return;
	int i = left, j = right;
	string key = strs[left];
	while (i < j)
	{
		while (i < j && key + strs[j] <= strs[j] + key)
			j--;
		while (i < j && key + strs[i] >= strs[i] + key)
			i++;
		if (i < j)
		{
			string temp = strs[i];
			strs[i] = strs[j];
			strs[j] = temp;
		}
	}
	strs[left] = strs[j];
	strs[j] = key;
	fastSort(strs, left, i - 1);
	fastSort(strs, i + 1, right);
	return;
}

//50. ��һ��ֻ����һ�ε��ַ�
char Sword::firstUniqChar(string s)
{
	unordered_map<char, bool> dic;
	for (char c : s)
	{
		dic[c] = dic.find(c) == dic.end();
	}
	for (char c : s)
	{
		if (dic[c]) return c;
	}
	return ' ';
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
