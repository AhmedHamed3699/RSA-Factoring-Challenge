#include <cstdlib>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>
#define ll long long
#define un unsigned
using namespace std;

/*
void generatePrime(un ll n, vector<un ll> &v)
{
	vector<bool> primes(n + 1, 1);

	primes[0] = primes[1] = 0;
	for (un ll i = 2; i <= n; i++)
	{
		if (primes[i])
		{
			v.push_back(i);
			for (un ll j = i + i; j <= n; j += i)
				primes[j] = 0;
		}
	}
}

bool isPrime(un ll n)
{
	if (n == 2)
		return true;
	if (n < 2 || n % 2 == 0)
		return false;

	for (un ll i = 3; i * i <= n; i += 2)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
*/

void PrimeDivisors(un ll n, vector<un ll> &divisors)
{
	for (un ll i = 2; i * i <= n; i++)
	{
		while (n % i == 0)
		{
			divisors.push_back(i);
			n /= i;
		}
	}
	if (n != 1)
		divisors.push_back(n);
}

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
	getline(file, line);
	un ll num = toNum(line);

	vector<un ll> div;
	PrimeDivisors(num, div);

	printf("%llu=%llu*%llu\n", num, div[1], div[0]);

	file.close();
}
