#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

int main()
{
	char temp[1000];
	char* str, *keyword;
	cin.getline(temp, 1000);
	char* buf;

	str = strtok_s(temp, " ", &buf);
	keyword = strtok_s(nullptr, " ", &buf);
	//printf("%s", str);
	//cout << endl;
	//printf("%s", keyword);

	int slen = strlen(str);
	int klen = strlen(keyword);
	int klen_min = (int)(klen*0.8);
	int count = 0;
	int march = 0;
	int j = klen / 2;
	int i = 0;
	queue<int> index;

	while (i < slen)
	{
		if (str[i] == keyword[j])
		{
			index.push(i);
		}
		i++;
	}
	int id = 0;
	while (!index.empty())
	{
	    id = index.front();
		count = 1;
		march = 1;
		j = klen / 2;
		while (id > 0 && j>0)
		{
			if (str[id-1] == keyword[j - 1])
			{
				count++;
				march++;
				j--;
				id--;
			}
			else if (id>=2 && str[id - 2] == keyword[j - 1])
			{
				count++;
				march += 2;
				j--;
				id -= 2;
			}
			else
			{
				break;
			}
		}
		id = index.front();
		j = klen / 2;
		while (id < slen && j< klen)
		{
			if (str[id + 1] == keyword[j + 1])
			{
				count++;
				march++;
				j++;
				id++;
			}
			else if (id < slen-2 && str[id + 2] == keyword[j + 1])
			{
				count++;
				march += 2;
				j++;
				id += 2;
			}
			else
			{
				break;
			}
		}
		if (count >= klen_min)
		{
			break;
		}
		index.pop();
	}
	if (count >= klen_min)
	{
		for (int k = id-march+1; k <=id; k++)
	    {
	    	str[k] = '*';
	    }
	}

	

	printf("%s", str);
	getchar();
	return 0;

}



//int gogogo(vector<vector<int>>& map, int i,int j,int end,int count)
//{
//	int size = map.size();
//	int start = map[i][j];
//	if (map[i][j] == -1 || i<0 || i>=size || j<0 || j>=size)
//		return;
//	if (map[i][j] == 0)
//	{
//		map[i][j] = count;
//	}
//	map[i][j] == end;
//	gogogo(map, i - 1, j, end, count+1);
//	gogogo(map, i + 1, j, end, count+1);
//	gogogo(map, i, j - 1, end, count+1);
//	gogogo(map, i, j + 1, end, count+1);
//	return;
//}
//
//int count;
//
//int main()
//{
//	int N;
//	cin >> N;
//	int c;
//	cin >> c;
//	vector<vector<int>> map(N, vector<int>(N, 0));
//	int id, locx, locy, w, h, px, py;
//	for (int i = 0; i<c; i++)
//	{
//		cin >> id >> locx >> locy >> w >> h >> px >> py;
//		for (int i = 0; i<w; i++)
//		{
//			for (int j = 0; j<h; j++)
//			{
//				map[locx + i][locy + j] = -1;
//			}
//		}
//		map[locx + px][locy + py] = id;
//	}
//	int start, end;
//	cin >> start >> end;
//
//	int start_x, start_y, end_x, end_y;
//	for (int i = 0; i<N; i++)
//	{
//		for (int j = 0; j<N; j++)
//		{
//			if (start = map[i][j])
//			{
//				start_x = i;
//				start_y = j;
//			}
//			if (end = map[i][j])
//			{
//				end_x = i;
//				end_y = j;
//			}
//		}
//	}
//	int count = id + 1;
//	map[start_x][start_y] = -1;
//
//	gogogo(map, start_x, start_y, end, count);
//
//}