#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

void AddLargeNumbers(char a[MAX],char b[MAX],char result[MAX + 1]);

int main() {
    char a[MAX] = "122", b[MAX] = "142", result[MAX + 1];
    AddLargeNumbers(a, b, result);
    printf("result = %s\n", result);
    return 0;
}

void AddLargeNumbers(char a[MAX],char b[MAX],char result[MAX + 1]) {
    int aLength = strlen(a); // 计算数组长度，但是在顶上的<string.h>的包里
    int bLength = strlen(b); // 同上

    int carry = 0; // 进位

    // 循环时候计数器
    int i = aLength - 1;
    int j = aLength - 1;
    int k = 0;

    // 逐位相加
    while (i >= 0 || j >= 0 || carry) {
        int digitA = (i >= 0) ? a[i] - '0' : 0;  // 获取 a 的当前位
                                                 // 这里的 a[i] - '0' 是通过ASCII码来进行char->int的转变
        int digitB = (j >= 0) ? b[j] - '0' : 0;  // 获取 b 的当前位

        int sum = digitA + digitB + carry;  // 当前位的和
        result[k++] = (sum % 10) + '0';  // 当前位的结果
        carry = sum / 10;  // 更新进位

        i--;  // 向前移位
        j--;
    }

    result[k] = '\0';  // 添加字符串结束符

    // 反转结果数组，因为我们是从个位开始相加的，但是保存在result的最高位
    for (int left = 0, right = k - 1; left < right; left++, right--) {
        char temp = result[left];
        result[left] = result[right];
        result[right] = temp;
    }
}


/*
    ab分别作为char数组保存

*/
