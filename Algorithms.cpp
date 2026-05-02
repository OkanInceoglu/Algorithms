#include <iostream>
#include <vector>
using namespace std;

bool PrimeNumber(int n) {
	if (n <= 1)return false;
	if (n == 2)return true;
	if (n % 2 == 0)return false;
	for (int i = 3;i * i <= n;i += 2) {
		if (n % i == 0)return false;
	}
	return true;
}
void Reverse()
{
	char ch;
	cin >> ch;
	if (ch == '.') return;
	else Reverse();
	cout << ch;
}
void hanoi(int n, char from, char to, char aux) {
	if (n == 0) return;

	hanoi(n - 1, from, aux, to);
	cout << "Move disk " << n << " from " << from << " to " << to << endl;
	hanoi(n - 1, aux, to, from);
}
int evklid(int a, int b) {
	if (b == 0)return a;
	return evklid(b, a % b);
}
int factorial(int n, vector <int>& dp) {
	if (n == 0)return 1;
	if (dp[n] != -1)return dp[n];
	return dp[n] = n * factorial(n - 1, dp);

}
int fibonachii(int n, vector<int>& dp) {
	if (n <= 1) return n;

	if (dp[n] != -1) return dp[n];

	return dp[n] = fibonachii(n - 1, dp) + fibonachii(n - 2, dp);
}
int sum(int n, vector<int>& dp) {
	if (n == 0) return 0;

	if (dp[n] != -1) return dp[n];

	return dp[n] = n + sum(n - 1, dp);
}
int main() {
	vector <int> dpf(5 + 1, -1);
	cout << factorial(5, dpf) << endl;
	vector <int> d(5 + 1, -1);
	cout << sum(5, d) << endl;
	vector<int> dp(5 + 1, -1);
	cout << fibonachii(5, dp) << endl;
	cout << evklid(18, 48) << endl;
	hanoi(3, 'A', 'C', 'B');
	Reverse();
	cout << endl;
	cout << PrimeNumber(47);
	return 0;
}