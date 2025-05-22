#include <stdio.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

int wait(int s) { return (--s); }
int signal(int s) { return (++s); }

void producer() {
    mutex = wait(mutex);
    empty = wait(empty);
    full = signal(full);
    x++;
    printf("\nProducer produces item %d", x);
    mutex = signal(mutex);
}

void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item %d", x);
    x--;
    mutex = signal(mutex);
}

int main() {
    int n, i;
    for(i = 1; i > 0; i++) {
        printf("\n1. Producer\n2. Consumer\n3. Exit\nEnter your choice: ");
        scanf("%d", &n);
        switch(n) {
            case 1:
                if((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("\nBuffer is full!");
                break;
            case 2:
                if((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("\nBuffer is empty!");
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}
