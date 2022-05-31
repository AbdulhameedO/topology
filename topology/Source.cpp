#include <iostream>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::vector;


void rateb(vector<vector<int>>& nas,int index, vector<int>& metrateb, int& minimum)
{
	if (!nas[index].size())
	{
		metrateb.push_back(index);
		nas[index].push_back(-1);
		return;
	}
	if (index > minimum)
		minimum = index;
	if (nas[index][0] == -1)
		return;

	for (int i = 0; i < nas[index].size(); i++)
		rateb(nas, nas[index][i], metrateb,minimum);

	metrateb.push_back(index);
	nas[index][0] = -1;
}

int main()
{
	int count;
	cin >> count;
	int par1, par2;
	vector<vector<int>> nas(count);

	for (int i = 0; i < count; i++)
	{
		cin >> par1;
		cin >> par2;

		if (par1 != -1)
		{
			nas[par1].push_back(i);
			std::sort(nas[par1].begin(), nas[par1].end());
		}
		if (par2 != -1)
		{
			nas[par2].push_back(i);
			std::sort(nas[par2].begin(), nas[par2].end());
		}
	}

	//OR

	//for (int i = 0; i < count; i++)
		//std::sort(nas[i].begin(), nas[i].end());



	//for (int i = 0; i < count; i++)
	//{
	//	cin >> par1;
	//	cin >> par2;
	//	 
	//	if (par1 == -1 && par2 == -1)
	//		continue;
	//	else if (par1 == -1)
	//		nas[i].p2 = par2;
	//	else if (par2 == -1)
	//		nas[i].p2 = par1;
	//	else if (par1 < par2)
	//	{
	//		nas[i].p1 = par1;
	//		nas[i].p2 = par2;
	//	}
	//	else
	//	{
	//		nas[i].p2 = par1;
	//		nas[i].p1 = par2;
	//	}
	//}
	vector<int> moratab;
	int min = 0;
	int dummy = 0;
	int x = 0;
	while (moratab.size() < count)
	{
		rateb(nas, dummy, moratab,min);
		dummy = min + 1;
		for (int i = 0; i < nas.size(); i++)
		{
			if (nas[i].size())
				if (nas[i][0] == -1)
					continue;
			dummy = i;
			break;
		}
	}
	for (int i = moratab.size() - 1; i > -1; i--)
		cout << moratab[i] << " ";

	return 0;
}