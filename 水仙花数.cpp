#include <stdio.h>
#include <math.h>
int  function(int a, int b);

int function(int a, int b);
int main() {
	int a, b, count;
	scanf("%d%d", &a, &b);
	count = function(a, b);
	printf("%d\n", count);
	return 0;
}

#include <math.h>

int function(int a, int b) {
    int count = 0;
    
    // 确定区间的起点和终点
    int start = (a < b) ? a : b;
    int end = (a > b) ? a : b;
    
    // 如果终点小于100，直接返回0（水仙花数至少是3位数）
    if (end < 100) {
        return 0;
    }
    
    // 确保起点至少是100
    if (start < 100) {
        start = 100;
    }
    
    for (int i = start; i <= end; i++) {
        int temp = i;
        int sum = 0;
        int n = 0;
        
        // 计算数字的位数
        int temp2 = i;
        while (temp2 > 0) {
            n++;
            temp2 /= 10;
        }
        
        // 计算每位数字的n次幂之和
        temp = i;
        while (temp > 0) {
            int digit = temp % 10;
            int power = 1;
            
            // 手动计算digit的n次幂，避免浮点数精度问题
            for (int j = 0; j < n; j++) {
                power *= digit;
            }
            
            sum += power;
            temp /= 10;
        }
        
        if (sum == i) {
            count++;
        }
    }
    
    return count;
}