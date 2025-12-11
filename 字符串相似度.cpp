#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char s1[110], s2[110];
	fgets(s1, sizeof(s1), stdin);
	fgets(s2, sizeof(s2), stdin);

	if (s1[strlen(s1) - 1] == '\n')
		s1[strlen(s1) - 1] = '\0';

	if (s2[strlen(s2) - 1] == '\n')
		s2[strlen(s2) - 1] = '\0';

	int len1 = strlen(s1);
	int len2 = strlen(s2);

	int dp[110][110] = {0};
	int LCS = 0;

	for (int i = 1; i <= len1; i++) {

		for (int j = 1; j <= len2; j++) {

			if (tolower(s1[i - 1]) == tolower(s2[j - 1])) {
				dp[i][j] = dp[i - 1][j - 1] + 1;

				if (dp[i][j] > LCS)
					LCS = dp[i][j];
			} else {
				dp[i][j] = 0;
			}
		}
	}

	double sim = 2.0 * LCS / (len1 + len2);

	printf("%.3f", sim);

	return 0;
}