#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#define ll long long
#define un unsigned
using namespace std;

un ll toNum(string str)
{
	un ll num;
	istringstream iss(str);
	iss >> num;
	return num;
}

int main(int argc, char **argv)
{
	if (argc != 2)
		return (EXIT_FAILURE);
	ifstream file(argv[1]);
	if (!file)
		return (EXIT_FAILURE);

	string line;
	while (getline(file, line))
	{
		un ll num = toNum(line);

		for (un ll i = 2; i * i <= num; i++)
		{
			if (num % i == 0)
			{
				printf("%llu=%llu*%llu\n", num, num / i, i);
				break;
			}
		}
	}
	file.close();
}
