#include <stdio.h>

#define MAX 1000000
int prime_list[MAX + 1] = { 0 };

int main(void)
{
	int n, cnt = 0;
	prime_list[0] = prime_list[1] = 1;

	for (int p_num = 2; p_num <= MAX; p_num++)
	{
		if (prime_list[p_num] == 0){
		for (int i = p_num * p_num; i <= MAX; i += p_num) prime_list[i] = 1;
        }
	}

	while (1)
	{
		scanf("%d", &n);
		if (n == 0) return 0;

		for (int i = 3; i < n/2; i++) {
			if (prime_list[i] == 0 && prime_list[n - i] == 0) {
				printf("%d = %d + %d\n",n, i, n - i);
				break;
                cnt = 1;
			}
		}
        if (!cnt) printf("Goldbach's conjecture is wrong.\n");
	}
}
