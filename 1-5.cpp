#include <iostream>
#include <memory.h>
#include <string.h>

using namespace std;

char s1[1001], s2[1001], s3[1001];
int temp = 0;

int main() {
	memset(s1, '0', sizeof(s1));
	memset(s2, '0', sizeof(s2));
	memset(s3, '0', sizeof(s3));
	s1[0] = '0';
	s2[0] = '1';
	s1[1000] = s2[1000] = s3[1000] = 0;
	int n;
	cout << "请输入项数：" << endl;
	cin >> n;
	if (n == 1 || n == 0) {
		if (n == 1) {
			cout << '1' << endl;
		}
		if (n == 0) {
			cout << '0' << endl;
		}
	}
	else {
		for (int i = 2; i <= n; i++) {
			for (int j = 0; j <= 999; j++) {
				temp = s1[j] - '0' + s2[j] - '0' + temp;
				s3[j] = temp % 10 + '0';
				temp = temp / 10;
			}
			strcpy(s1, s2);
			strcpy(s2, s3);
		}
		int k = 999;
		while (s3[k] == '0') {
			k--;
		}
		for (int i = k; i >= 0; i--) {
			cout << (s3[i] - '0');
		}
		cout << endl;
	}
	return 0;
}