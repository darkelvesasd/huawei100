#include<iostream>
#include<vector>
#include<string.h>
#include<algorithm>
#include<queue>
using namespace std;
struct cmp
{
	bool operator()(vector<int>a,vector<int>b)
	{
			if (a[0] < b[0])
			{
				return true;
			}
			else if (a[0] > b[0])
			{
				return false;
			}
			if (a[1] < b[1])
			{
				return false;
			}
			else
			{
				return true;
			}
	}
};
int main()
{
	vector<priority_queue<vector<int>, vector<vector<int>>, struct cmp>>pq(100);
	int n;
	cin >> n;
	int i = 1;
	string s;
	while (n--)
	{
		cin >> s;
		if (s == "IN")
		{
			int t;
			vector<int>v(2);
			cin >> t;
			int t1;
			cin >> t1;
			v[0] = t1;
			v[1] = i++;
			pq[t].emplace(v);
		}
		else
		{
			if (s == "OUT")
			{
				int t;
				cin >> t;
				if (pq[t].empty())
				{
					cout << "NULL" << endl;
				}
				else
				{
					cout << pq[t].top()[1];
					pq[t].pop();
				}
			}
		}
	}
	return 0;
}
/*
 6
 IN 1 1
 IN 1 3
 IN 1 1
 IN 1 3
 OUT 1
 OUT 2
*/
