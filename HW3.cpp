#include <iostream>
using namespace std;

int main() {
	int n, i, j;
	cout << "Enter an odd positive integer less than 30: ";
	cin >> n;
	for ( ;n < 1 || n >= 30 || n % 2 == 0; ) {
		cout << "Try again: ";
		cin >> n;
	}
	for (int h = 1; h <= n; h++) {
		for (int w = 1; w <= n; w++) {
			if (h == (n + 1) / 2 || w == (n + 1) / 2 || h == w || h + w == (n + 1)) cout << "*";
			else cout << " ";
		}
		cout << endl;
	}
	cout << endl << endl << endl;
	if (n % 3 == 0) i = 1, j = 0; // If n/3 divides cleanly.
	else if (n % 3 == 1) i = 1, j = 1; // If n/3 gives remainder of 1.
	else if (n % 3 == 2) i = 2, j = 0; // If n/3 gives remainder of 2.
	for (int h = 1; h <= n; h++) {
		for (int w = 1; w <= n; w++) {
			if (w == (n / 3) + i && (h <= (n / 3) + i || h >= ((2 * n) / 3) + j)) cout << "*"; // w reaches middle section, h isn't inside middle.
			else if (w == ((2 * n) / 3) + j && (h <= (n / 3) + i || h >= ((2 * n) / 3) + j)) cout << "*"; // w reaches end of middle, h isn't inside middle.
			else if (h == (n / 3) + i && (w <= (n / 3) + i || w >= ((2 * n) / 3) + j)) cout << "*"; // h reaches middle, w isn't inside middle.
			else if (h == ((2 * n) / 3) + j && (w <= (n / 3) + i || w >= ((2 * n) / 3) + j)) cout << "*"; // h reaches end of middle, w isn't inside middle.
			else if (w > (n / 3) + i && w <= ((2 * n) / 3) + j && (h == 1 || h == n)) cout << "*"; // w is in middle, h is one of the end values.
			else if (h > (n / 3) + i && h <= ((2 * n) / 3) + j && (w == 1 || w == n)) cout << "*"; // h is in middle, w is an end value.
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}
