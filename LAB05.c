#include <stdio.h>
#include <stdlib.h>
int* queue;
int front = -1;
int rear = -1;
void qi(int x, int N) {
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        printf("OVERFLOW\n");
        return;
    }
   if (front == -1) {
        front = 0;
        rear = 0;
    } else {
        rear++;	
    }
   queue[rear] = x;
    printf("Inserted %d into the queue\n", x);
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}
int main() {
    int N;
    printf("Enter the size of the queue: ");
    scanf("%d", &N);
    queue = (int*)malloc(N * sizeof(int));
  int t;
    printf("Enter the number of operations: ");
    scanf("%d", &t);
  while (t--) {
        int x;
        printf("Enter the element: ");
        scanf("%d", &x);
        qi(x, N);
        display();
    }
   free(queue);
    return 0;
}
