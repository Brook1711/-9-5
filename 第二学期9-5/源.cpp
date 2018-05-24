#include<iostream>
#include<vector>
using namespace std;

int BestSituaion(int i,int n, int limit, vector<int> v)
{
	if (i == n - 1)
	{
		if (limit >= v[i])
			return 1;
		else
			return 0;
	}
	else
	{
		int max = 0;
		int this_one;
		if (i == -1)
			this_one = 0;
		else
			this_one = limit >= v[i] ? 1 : 0;
		for (int j = i + 1; j < n; j++)
		{
			int next_limit = limit > v[j] ? v[j] : limit;
			int Next = BestSituaion(j, n, next_limit, v);
			if (Next > max)
				max = Next;
		}
		return this_one + max;
	}

}

int main()
{
	vector<int>Hight;
	int temp;
	while (cin >> temp)
		Hight.push_back(temp);
	int n = Hight.size();
	int Best = BestSituaion(-1, n, 100000, Hight);
	return 0;
}