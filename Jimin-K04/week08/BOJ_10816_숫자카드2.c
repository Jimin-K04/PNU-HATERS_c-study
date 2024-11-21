//63프로에서 시간 초과 떠버림
#include <stdio.h>
#include <stdlib.h>
#define MAX 500000
int sorted[MAX];
void merge(int list[], int list1, int list2, int end);
void merge_sort(int list[], int start, int end);

int main(void)
{
	int N, M, search, cnt = 0;
	int min = 0, max, mid;

	scanf("%d", &N);
	int* card_nums = malloc(sizeof(int) * N);
	for (int i = 0; i < N; i++) scanf("%d", &card_nums[i]);
	//분할정복으로 정렬
	merge_sort(card_nums, 0, N - 1);

	scanf("%d", &M);

	for (int i = 0; i < M; i++) {
		scanf("%d", &search);
		cnt = 0;
		min = 0; 
		max = N - 1;
		int check = 0;
		while (min <= max) {
			mid = (max + min) / 2;
			if (search == card_nums[mid]) {
				check = 1;
				break;
			}
			else if (search > card_nums[mid]) min = mid + 1;
			else max = mid - 1;
		}
		// 숫자가 발견된 경우 앞뒤로 같은 숫자가 몇개인지 count
		if (check) {
			cnt++;
			for (int down = mid - 1; card_nums[down] == card_nums[mid]; down--) cnt++;
			for (int up = mid + 1; card_nums[up] == card_nums[mid]; up ++) cnt++;
		}
		printf("%d ", cnt);
	}
}

void merge(int list[], int list1, int list2, int end)
{
	int i = list1, j = list2, k = list1;
	
	while (i < list2 && j <= end) {
		if (list[i] <= list[j]) sorted[k++] = list[i++];
		else sorted[k++] = list[j++];
	}
	if (i >= list2) {
		for (int l = j; l <= end; l++) sorted[k++] = list[l];
	}
	else {
		for (int l = i; l < list2; l++) sorted[k++] = list[l];
	}

	for (int i = list1; i <= end; i++) list[i] = sorted[i];
}

void merge_sort(int list[], int start, int end)
{
	if (start == end) return;

	int mid = (start + end) / 2;
	merge_sort(list, start, mid);
	merge_sort(list, mid + 1, end);
	merge(list, start, mid + 1, end);
}
