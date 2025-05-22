#include <stdio.h>

int main() {
    int i, j, n, frames, k = 0, page_faults = 0;
    int pages[50], frame[10], flag;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    printf("\nPage\tFrames\n");
    for(i = 0; i < n; i++) {
        flag = 0;
        for(j = 0; j < frames; j++) {
            if(frame[j] == pages[i]) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            frame[k] = pages[i];
            k = (k + 1) % frames;
            page_faults++;

            printf("%d\t", pages[i]);
            for(j = 0; j < frames; j++)
                if(frame[j] != -1)
                    printf("%d ", frame[j]);
            printf("\n");
        }
    }

    printf("\nTotal Page Faults = %d\n", page_faults);

    return 0;
}
