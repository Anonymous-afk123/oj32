#include <stdio.h>
#include <ctype.h>

int main() {
	char isbn[14];
	scanf("%13s", isbn);

	int digits[9];
	int idx = 0;

	// 提取前9个数字
	for (int i = 0; i < 12; i++) {

		if (isdigit(isbn[i])) {
			digits[idx++] = isbn[i] - '0';
		}
	}

	// 计算加权和
	int sum = 0;

	for (int i = 0; i < 9; i++) {

		sum += digits[i] * (i + 1);
	}

	// 计算正确的识别码
	int remainder = sum % 11;
	char correct_check;

	if (remainder == 10) {
		correct_check = 'X';
	} else {
		correct_check = remainder + '0';
	}

	// 比较并输出结果
	if (isbn[12] == correct_check) {
		printf("Right\n");
	} else {
		isbn[12] = correct_check;
		printf("%s\n", isbn);
	}

	return 0;
}
