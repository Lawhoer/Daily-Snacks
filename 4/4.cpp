#include <iostream>

using namespace std;

void Genel();
int FindMinP(int arr[], int size);

int main() {
	Genel();
	return 0;
}

void Genel() {
	int size;
	int* arr = nullptr;
	cout << "Dizinin boyutu kac?" << endl;
	cin >> size;
	cout << "Degerleri giriniz: ";
	arr = new int[size];
	for (int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int minP = FindMinP(arr, size);

	if (minP == 0) {
		cout << "1";
	}
	else {
		cout << "minP: " << minP << endl;
		int ctr = minP;
		int temp = ctr;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (arr[j] != ctr + 1) {
					continue;
				}
				else {
					ctr++;
					temp = ctr;
					break;
				}
			}
			if (temp == ctr) {
				cout << ctr + 1;
			}
		}
	}
}

int FindMinP(int arr[], int size) {
	int minP = arr[0];
	for (int i = 0; i < size; i++) {
		if (arr[i] < minP && arr[i]>0)
			minP = arr[i];
	}
	return minP;
}