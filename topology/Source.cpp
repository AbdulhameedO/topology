#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::vector;

struct men
{
public:
	int p1 = -1;
	int p2 = -1;
};

int main()
{
	int count;
	cin >> count;
	int par1, par2;
	vector<men> nas(count);

	for (int i = 0; i < count; i++)
	{
		cin >> par1;
		cin >> par2;
		 
		if (par1 == -1 && par2 == -1)
			continue;
		else if (par1 == -1)
			nas[i].p2 = par2;
		else if (par2 == -1)
			nas[i].p2 = par1;
		else if (par1 < par2)
		{
			nas[i].p1 = par1;
			nas[i].p2 = par2;
		}
		else
		{
			nas[i].p2 = par1;
			nas[i].p1 = par2;
		}
	}
	return 0;
}