#include <stdio.h>
#include <stdlib.h>

#define N 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

void test(int i);
void take_fork(int i);
void put_fork(int i);
void philosopher(int i);
void display();

void test(int i) {
    if (state[i] == HUNGRY && state[(i+4)%N] != EATING && state[(i+1)%N] != EATING) {
        state[i] = EATING;
        printf("Philosopher %d takes forks %d and %d\n", i+1, (i+4)%N+1, i+1);
        printf("Philosopher %d is Eating\n", i+1);
    }
}

void take_fork(int i) {
    state[i] = HUNGRY;
    printf("Philosopher %d is Hungry\n", i+1);
    test(i);
}

void put_fork(int i) {
    state[i] = THINKING;
    printf("Philosopher %d putting forks %d and %d down\n", i+1, (i+4)%N+1, i+1);
    printf("Philosopher %d is Thinking\n", i+1);
    test((i+4)%N);
    test((i+1)%N);
}

void display() {
    for (int i = 0; i < N; i++) {
        if (state[i] == EATING)
            printf("P%d: EATING\n", i+1);
        else if (state[i] == HUNGRY)
            printf("P%d: HUNGRY\n", i+1);
        else
            printf("P%d: THINKING\n", i+1);
    }
}

int main() {
    int choice, i;
    while (1) {
        printf("\n1. Take fork\n2. Put fork\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter philosopher number (1-5): ");
                scanf("%d", &i);
                take_fork(i - 1);
                break;
            case 2:
                printf("Enter philosopher number (1-5): ");
                scanf("%d", &i);
                put_fork(i - 1);
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}
