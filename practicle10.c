#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, n, head, total = 0;
    int request[100];

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk requests sequence:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(i = 0; i < n; i++) {
        total += abs(request[i] - head);
        head = request[i];
    }

    printf("Total head movement = %d\n", total);

    return 0;
}
