#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000000

int main(void)
{
	int T, n, n_sqr, idx, cnt;
	int prime_list[MAX + 1] = { 0 };
	scanf("%d", &T);

	for (int j = 0; j < T; j++)
	{
		scanf("%d", &n);
		//에라토스테네스의 체
		for (int i = 0; i <= n; i++) prime_list[i] = 0; //소수이면 0, 아니면 1
		cnt = 0;
		prime_list[0] = prime_list[1] = 1;

		n_sqr = sqrt(n);
		for (int p_num = 2; p_num <= n_sqr; p_num++)
		{
			while (prime_list[p_num] > 0 && p_num <= n) p_num++;
			for (int i = p_num * p_num; i <= n; i += p_num) prime_list[i] = 1;
		}
		idx = 0;
		for (int i = 2; i < n; i++)
		{
			if (prime_list[i] == 0) prime_list[idx++] = i; //소수이면 값을 소수로 저장
		}
		for (int i = 0; i < idx; i++)
		{
			if (prime_list[i] > (n / 2)) break; //중복피하기 위해서 반만
			if (prime_list[n - prime_list[i]] != 1) cnt++; //골드바흐 파티션 수 count
		}
		printf("%d\n", cnt);
	}
}
