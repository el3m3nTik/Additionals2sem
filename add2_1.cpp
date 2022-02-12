#include <iostream>

void Sumofnums(int N, int& sum)
{
	if (N == 0)
		return;
	sum += N % 10;
	N /= 10;
	Sumofnums(N, sum);
}

int main()
{
	int sum = 0, N;
	std::cin >> N;
	Sumofnums(N, sum);
	std::cout << sum << std::endl;
}