#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	int sum_val;
} Number;

int get_sum(int n) {
	int s = 0;

	while (n > 0) {
		s += n % 10;
		n /= 10;
	}

	return s;
}

void swap(Number *a, Number *b) {
	Number temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int n;

	if (scanf("%d", &n) != 1)
		return 0;

	Number nums[n];

	for (int i = 0; i < n; i++) {

		scanf("%d", &nums[i].value);

		nums[i].sum_val = get_sum(nums[i].value);
	}

	for (int i = 0; i < n - 1; i++) {

		for (int j = 0; j < n - 1 - i; j++) {

			if (nums[j].sum_val < nums[j + 1].sum_val ||
			        (nums[j].sum_val == nums[j + 1].sum_val && nums[j].value > nums[j + 1].value)) {
				swap(&nums[j], &nums[j + 1]);
			}
		}
	}

	for (int i = 0; i < n; i++) {

		printf("%d %d\n", nums[i].value, nums[i].sum_val);
	}

	return 0;
}