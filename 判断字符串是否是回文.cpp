#include <stdio.h>
#include <string.h>
void ispalindrome(const char *fuck);

int main(void) {
	char s[100];
	scanf("%s", s);
	ispalindrome(s);
	return 0;
}

void ispalindrome(const char *fuck) {
	int n = strlen(fuck);

	int flag = 1;  // 假设是回文
for (int i = 0; i < n / 2; i++) {
    if (fuck[i] != fuck[n - i - 1]) {
        flag = 0;
        break;
    }
}
if (flag)
    puts("yes");
else
    puts("no");
}