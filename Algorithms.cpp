#include <iostream>
#include <vector>
using namespace std;
//-------------------------------------------------------------------------------------------------
void merge(int arr[], int l, int m, int r) {
	int n1 = m - l + 1;
	int n2 = r - m;

	int L[100], R[100];

	for (int i = 0;i < n1;i++) {
		L[i] = arr[l + i];
	}
	for (int j = 0;j < n2;j++) {
		R[j] = arr[r + j + 1];
	}

	int i = 0, j = 0, k = l;

	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while (j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}

}
void mergeSort(int arr[], int l, int r) {
	if (l >= r)return;
	int m = (l + r) / 2;
	mergeSort(arr, l, m);
	mergeSort(arr, m + 1, r);

	merge(arr, l, m, r);
}
//-------------------------------------------------------------------------------------------------


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

void bubbleSort(int arr[], int n) {
	for (int i = 0;i < n - 1;i++) {
		bool swapped = false;
		for (int j = 0;j < n - i - 1;j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j + 1], arr[j]);
				swapped = true;
			}
		}
		cout << i + 1 << ".Step: ";
		for (int k = 0;k < n;k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
		if (!swapped) break;
	}
}

void selectionSort(int arr[], int n) {
	for (int i = 0;i < n - 1;i++) {
		int min = i;
		for (int j = i + 1;j < n;j++) {
			if (arr[min] > arr[j]) {
				min = j;
			}
		}
		if (min != i) {
			swap(arr[i], arr[min]);
		}
		cout << i + 1 << ".Step: ";
		for (int k = 0;k < n;k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}

void insertionSort(int arr[], int n) {
	for (int i = 1;i < n;i++) {
		int key = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		cout << i << ".Step: ";
		for (int k = 0;k < n;k++) {
			cout << arr[k] << " ";
		}
		cout << endl;
	}
}

int gcdit(int a, int b) {
	while (a != b) {
		if (a > b)a -= b;
		else b -= a;
	}
	return b;
}
int gcdrec(int a, int b) {
	if (b == 0)return a;
	return gcdrec(b, a % b);
}

int fibo(int n) {
	if (n == 0)return 0;
	if (n == 1)return 1;
	return fibo(n - 1) + fibo(n - 2);
}
int fibonacii(int n, vector <int>& dp) {
	if (n <= 1)return n;
	if (dp[n] != -1)return dp[n];
	return dp[n] = fibonacii(n - 1, dp) + fibonacii(n - 2, dp);
}

int factiter(int n) {
	int sum = 1;
	for (int i = 2;i <= n;i++) {
		sum *= i;
	}
	return sum;
}
int factrec(int n) {
	if (n == 0)return 1;
	return n * factrec(n - 1);
}

void sieve(int n) {
	vector<bool>isPrime(n + 1, true);

	isPrime[0] = isPrime[1] = false;

	for (int i = 2;i * i <= n;i++) {
		if (isPrime[i]) {
			for (int j = i * i;j <= n;j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int k = 2;k <= n;k++) {
		if (isPrime[k]) {
			cout << k << " | ";
		}
	}
}


int main() {
	cout << "Prime test 7: " << PrimeNumber(7) << endl;
	cout << "Prime test 10: " << PrimeNumber(10) << endl;

	cout << "Reverse (end with '.'): ";
	Reverse();
	cout << endl;

	cout << "\nHanoi (3 disks):\n";
	hanoi(3, 'A', 'C', 'B');

	int arr1[] = { 5, 1, 4, 2, 8 };
	int n1 = 5;
	cout << "\nBubble Sort:\n";
	bubbleSort(arr1, n1);

	int arr2[] = { 64, 25, 12, 22, 11 };
	int n2 = 5;
	cout << "\nSelection Sort:\n";
	selectionSort(arr2, n2);

	int arr3[] = { 9, 5, 1, 4, 3 };
	int n3 = 5;
	cout << "\nInsertion Sort:\n";
	insertionSort(arr3, n3);

	cout << "\nGCD iterative (48,18): " << gcdit(48, 18) << endl;
	cout << "GCD recursive (48,18): " << gcdrec(48, 18) << endl;

	cout << "\nFibo(6): " << fibo(6) << endl;

	vector<int> dp(20, -1);
	cout << "Fibo DP (10): " << fibonacii(10, dp) << endl;

	cout << "\nFactorial iter (5): " << factiter(5) << endl;
	cout << "Factorial rec (5): " << factrec(5) << endl;

	cout << "\nSieve (20): ";
	sieve(20);
	cout << endl;

	return 0;
}