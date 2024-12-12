#include<iostream>
#include<vector>
#include<queue>
using namespace std;
typedef pair<int, int>PII;
int x[4] = { 0,0,1,-1 };
int y[4] = { -1,1,0,0 };
int m, n;
int main()
{
	cin >> m >> n;
	vector<vector<char>>v(m, vector<char>(n));
	vector<vector<bool>>b(m, vector<bool>(n));
	queue<PII>q;
	queue<PII>q1;
	int mx = 0;
	PII ret1;
	int ret2=0;
	int flag = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		if (v[i][0] == 'O')
		{
			q.emplace(PII(i,0));
			if (i > 0 && v[i - 1][0] == 'O')
			{
				flag = 1;
			}
		}
		if (v[i][n - 1] == 'O')
		{
			q.emplace(PII(i,n-1));
			if (i >0 && v[i - 1][n-1] == 'O')
			{
				flag = 1;
			}
		}
	}
	for (int j = 0; j < n; j++)
	{
		if (v[0][j] == 'O')
		{
			q.emplace(PII(0,j));
			if (j >0 && v[0][j-1] == 'O')
			{
				flag = 1;
			}
		}
		if (v[m-1][j] == 'O')
		{
			q.emplace(PII(m-1,j));
			if (j > 0 && v[m-1][j - 1] == 'O')
			{
				flag = 1;
			}
		}
	}
	while (!q.empty())
	{
		PII qt = q.front();
		q1.emplace(qt);
		int cnt = 0;
		q.pop();
		b[qt.first][qt.second] = true;
		while (!q1.empty())
		{
			cnt++;
			PII t = q1.front();
			q1.pop();
			for (int i = 0; i < 4; i++)
			{
				int x1 = t.first + x[i];
				int y1 = t.second + y[i];
				if (x1>=0&&x1<m&&y1>=0&&y1<n&&b[x1 ][y1] == false && v[x1][y1] == 'O')
				{
					q1.emplace(PII(x1, y1));
					b[x1][y1] = true;
				}
			}
		}
		if (cnt > ret2)
		{
			ret1 = qt;
			ret2 = cnt;
		}
	}
	if (flag == 0)
	{
		cout << ret1.first << " " << ret1.second << " ";
	}
		cout << ret2;
}
/*4 5
XXXXX
XOOOO
XOOOX
XOXXX
*/
