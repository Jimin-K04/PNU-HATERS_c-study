#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SIZE 10000
//������ ���� ����
// ���� �������� �ǰ��� ���ε�

//FIFO - QUEUE
// 1. ������ �߿䵵�� Ȯ��
// 2. �߿䵵�� ���� ������ �ϳ��� �ִٸ�, �� ������ QUEUE ���� �ڿ� ��ġ

typedef struct {
	int priority[SIZE];
	int front, rear, tindex;
}queue;

void init(queue* q, int target) {
	q->front = q->rear = -1;
	q->tindex = target;
}

void enqueue(queue* q, int e) {
	q->rear++;
	q->priority[q->rear] = e;
}

int dequeue(queue* q) {
	q->front++;
	return q->priority[q->front];
}

int main() {
	int loop = 0;
	scanf("%d", &loop);

	while (loop > 0) {
		loop--;
		int num, target, cnt = 0;
		queue q;
		scanf("%d", &num); //������ ����
		scanf("%d", &target); // Ÿ�� ���� �ε���
		init(&q, target);
		for (int i = 0; i < num; i++) {
			// �߿䵵 ��ġ
			int tmp;
			scanf("%d", &tmp);
			enqueue(&q, tmp);
		}
		//�ݺ����� ���ؼ� �ڿ� �ִ� �ε����� ��� �߿䵵�� ��� ���Ͽ� print
		for (int i = (q.front) + 1; i < q.rear + 1; i++) {
			int check = 1;
			for (int j = (q.front) + 2; j < q.rear + 1; j++) {
				if (q.priority[i] < q.priority[j]) {
					check = 0;
					if (i == q.tindex) {
						q.tindex = (q.rear + 1);
					}
					enqueue(&q, dequeue(&q));
					break;
				}
			}
			if (check) {
				dequeue(&q);
				cnt++;
				if (i == q.tindex) {
					printf("%d\n", cnt);
					break;
				}
			}
		}
	}
}
