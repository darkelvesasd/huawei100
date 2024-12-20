#include<iostream>
#include<vector>
using namespace std;
int main()
{
	int a, b, n, t;
	cin >> a >> b >> n;
	while (n--)
	{
		int flag = 0;
		cin >> t;
		int n1, n2, n3, n4;
		int row = t / a;
		n1 = t - a;
		n2 = t - 1;
		n3 = t + a;
		n4 = t + 1;
		if (n1 < 0)
		{
			if (a * b + n1 != t)
			{
				cout << a * b + n1 << " ";
				flag++;
			}
		}
			else
			{
				cout << n1 << " ";
				flag++;
			}
		if (n2 >= 0)
		{
			cout << n2 << " ";
			flag++;
		}
		if (n3 >= a * b )
		{
			if (n3 % (a * b) != t)
			{
				cout << n3 % (a * b) << " ";
				flag++;
			}
		}
			else 
			{
				cout << n3 << " ";
				flag++;
			}
		if (n4 < a * b)
		{
			cout << n4 << " ";
			flag++;
		}
		cout << t << endl;
	}
	return 0;
}/*12 4 1
17*/
