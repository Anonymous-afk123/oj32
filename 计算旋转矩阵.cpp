#include <stdio.h>

int main() {
	double q1, q2, q3, q4;
	scanf("%lf,%lf,%lf,%lf", &q1, &q2, &q3, &q4);
	double R[3][3];
	R[0][0] = q1 * q1 + q2 * q2 - q3 * q3 - q4 * q4;
	R[0][1] = 2 * (q2 * q3 - q1 * q4);
	R[0][2] = 2 * (q2 * q4 + q1 * q3);
	R[1][0] = 2 * (q2 * q3 + q1 * q4);
	R[1][1] = q1 * q1 - q2 * q2 + q3 * q3 - q4 * q4;
	R[1][2] = 2 * (q2 * q4 - q1 * q2);
	R[2][0] = 2 * (q2 * q4 - q1 * q3);
	R[2][1] = 2 * (q4 * q3 + q1 * q2);
	R[2][2] = q1 * q1 - q2 * q2 - q3 * q3 + q4 * q4;

	for (int i = 0; i <= 2; i++) {

		for (int j = 0; j <= 2; j++) {

			printf("%lf", R[i][j]);

			if (j != 2)
				printf(" ");
		}

		printf("\n");
	}

	return 0;
}