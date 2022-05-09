#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//12345 -> 5 --> 1234 -> 4 --> 123 ->...
//%, /
// Cho n nguyen duong bat ky, tinh tong cac chu so cua n.
int main() {
    int n;
    scanf("%d", &n);
    //Complete the code to calculate the sum of the five digits on n.
    int S = 0;
    while (n != 0)
    {
    	S += n % 10;
    	n /= 10;
	}
	printf("%d\n", S);
    return 0;
}
