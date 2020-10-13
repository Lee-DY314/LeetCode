#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> dic;
vector<int> filenum(100);
int cur = -1;

int open(string str)
{
	cur++;
	dic.push_back(str);
	filenum[cur] = cur;
	return cur;
}

void close(int para)
{
	filenum.erase(filenum.begin()+para);
}

int dup(int para)
{
	cur++;
	filenum[cur] = para;
	return cur;
}

void dup2(int para1, int para2)
{
	int temp = filenum[para1];
	filenum[para2] = temp;
}

void query(int para)
{
	int temp = filenum[para];
	cout << dic[temp] << endl; 
}

//int main()
//{
//	int t;
//	cin >> t;
//	for (int i = 0; i < t; i++)
//	{
//		int n;
//		cin >> n;
//		for (int j = 0; j < n; j++)
//		{
//			string name, para1, para2;
//			string str;
//			getline(cin,str);
//			istringstream is(str);
//			is >> name >> para1 >> para2;
//			if (name == "open")
//			{
//				open(para1);
//			}
//			else if (name == "close")
//			{
//				int temp = stoi(para1);
//				close(temp);
//			}
//			else if (name == "query")
//			{
//				int temp = stoi(para1);
//				query(temp);
//			}
//			else if (name == "dup2")
//			{
//				int temp1 = stoi(para1);
//				int temp2 = stoi(para2);
//				dup2(temp1, temp2);
//			}
//			else
//			{
//				int temp = stoi(para1);
//				dup(temp);
//			}
//		}
//	}
//}


//int main()
//{
//	int c, n, m;
//	cin >> c;
//	for (int i = 0; i < c; i++)
//	{
// 		cin >> n >> m;
//		vector<vector<int>> map(n, vector<int>(n,0));
//		int size = n*n;
//		int circle = (n + 1) / 2;
//		
//		int x = 0, y = 0;
//		int count = 0;
//		int top, bottom, left, right;
//		int num = 0;
//		for (int i = 0; i < circle; i++)
//		{
//			top = i;
//			bottom = n - i - 1;
//			left = i;
//			right = n - i - 1;
//			map[i][i] = ++count;
//			x = i;
//			y = i;
//		    num = num + (n - 1 - i * 2) * 4;
//			if (num > size) num = size;
//			if (i % 2 == 0)
//			{
//				while (count < num)
//				{
//					while (y < right)
//					{
//						map[x][++y] = ++count;
//					}
//					top++;
//
//					while (x < bottom)
//					{
//						map[++x][y] = ++count;
//					}
//					right--;
//
//					while (y > left)
//					{
//						map[x][--y] = ++count;
//					}
//					bottom--;
//
//					while (x > top)
//					{
//						map[--x][y] = ++count;
//					}
//					left++;
//				}
//			}
//			else
//			{
//				while (count < num)
//				{
//					while (x < bottom)
//					{
//						map[++x][y] = ++count;
//					}
//					left++;
//
//					while (y < right)
//					{
//						map[x][++y] = ++count;
//					}
//					bottom--;
//
//					while (x > top)
//					{
//						map[--x][y] = ++count;
//					}
//					right--;
//
//					while (y > left)
//					{
//						map[x][--y] = ++count;
//					}
//					top++;
//					
//				}
//			}
//		}
//
//		for (int i = 0; i < m; i++)
//		{
//			int cx, cy;
//			cin >> cx >> cy;
//			cout << map[cx][cy] << endl;
//		}
//		
//	}
//
//	return 0;
//}