#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct CARD {
  int data;
  int pos;
  struct CARD *next;
} CARD;

typedef struct {
  CARD *front;
  CARD *rear;
} QUEUE;

void createEmptyQueue(QUEUE *q) {
  q->rear = NULL;
  q->front = NULL;
}

int fillingQueue(QUEUE *q) {
  int size = 0;
  int input = 0;
  int position = 1;
  while (input != -1) {
    scanf("%d", &input);
    if (input == -1) break;
    CARD *ptr = (CARD *)malloc(sizeof(CARD));
    ptr->pos = position;
    ptr->data = input;
    if (q->front == NULL) {
      q->front = ptr;
      q->rear = ptr;
      q->front->next = q->rear->next = NULL;
    } else {
      q->rear->next = ptr;
      q->rear = ptr;
      q->rear->next = NULL;
    }
    position++;
    size++;
  }
  return size;
}

void dequeueFront(QUEUE *q) {
  if (q->front != NULL) {
    CARD *temp = q->front;
    q->front = q->front->next;
    free(temp);
  }
}

void dequeueRear(QUEUE *q) {
  if (q->rear != NULL) {
    CARD *current = q->front;
    while (current->next != q->rear) {
      current = current->next;
    }
    free(q->rear);
    q->rear = current;
    q->rear->next = NULL;
  }
}

int main() {
  int steps = 0;
  QUEUE q;
  createEmptyQueue(&q);
  int size = fillingQueue(&q);
  scanf("%d", &steps);

  int values[size * 2];
  int i = 0;

  int max_sum = 0;
  while (steps != 0) {
    if (q.rear->data > q.front->data) {
      max_sum += q.rear->data;
      values[i] = q.rear->data;
      i++;
      values[i] = q.rear->pos;
      i++;
      dequeueRear(&q);
      dequeueFront(&q);
    } else {
      max_sum += q.front->data;
      values[i] = q.front->data;
      i++;
      values[i] = q.front->pos;
      i++;
      dequeueFront(&q);
      dequeueRear(&q);
    }
    steps--;
  }

  printf("%d\n", max_sum);

  int a = 0;
  while (a < i) {
    printf("%d %d\n", values[a], values[a + 1]);
    a += 2;
  }

  return 0;
}

