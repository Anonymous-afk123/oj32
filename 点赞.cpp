#include <stdio.h>
#include <string.h>

int main() {
	int n;
	scanf("%d", &n);

	int count[101] = {0};

	for (int i = 0; i < n; i++) {

		int k;
		scanf("%d", &k);


		int appeared[101] = {0};

		for (int j = 0; j < k; j++) {

			int tag;
			scanf("%d", &tag);

			count[tag]++;

		}
	}

	int max_count = 0;
	int max_tag = 0;

	for (int tag = 1; tag <= 100; tag++) {

		if (count[tag] >= max_count) {
			max_count = count[tag];
			max_tag = tag;
		}
	}

	printf("%d %d", max_tag, max_count);

	return 0;
}