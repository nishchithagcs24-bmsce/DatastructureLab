#include <stdio.h>
#define SIZE 10

int pq[SIZE];
int count = 0;

void insert(int value) {
    if (count == SIZE) {
        printf("Priority Queue is full\n");
        return;
    }

    int i = count - 1;
    while (i >= 0 && pq[i] > value) {
        pq[i + 1] = pq[i];
        i--;
    }
    pq[i + 1] = value;
    count++;
}

void deleteHighestPriority() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", pq[0]);

    for (int i = 1; i < count; i++) {
        pq[i - 1] = pq[i];
    }
    count--;
}

void display() {
    if (count == 0) {
        printf("Priority Queue is empty\n");
        return;
    }

    printf("Priority Queue: ");
    for (int i = 0; i < count; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    insert(30);
    insert(10);
    insert(20);
    display();

    deleteHighestPriority();
    display();

    return 0;
}



//OUTPUT
/*Priority Queue: 10 20 30 
Deleted: 10
Priority Queue: 20 30 
*/
