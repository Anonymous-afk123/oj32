#include <stdio.h>

int main() {
	int n, tar;
	scanf("%d %d", &n, &tar);
	int arr[n];

	for (int i = 0; i < n; i++) {

		scanf("%d", &arr[i]);
	}

	int found = 0;

	for (int i = 0; i < n; i++) {

		if (tar == arr[i]) {
			printf("%d\ ", i);
			found = 1;
		}
	}

	if (found == 0) {
		printf("-1\n");
	}

	return 0;
}
