#include <stdio.h>

int main() {
    int size, rate, input, stored = 0, time, sent;

    printf("Enter bucket size: ");
    scanf("%d", &size);

    printf("Enter output rate (leak rate): ");
    scanf("%d", &rate);

    printf("Enter number of cycles (time units): ");
    scanf("%d", &time);

    while (time--) {
        printf("\nEnter number of packets arriving: ");
        scanf("%d", &input);

        stored += input;

        if (stored > size) {
            printf("Bucket overflow! %d packets dropped.\n",
                   stored - size);
            stored = size;
        }

        printf("Packets currently in bucket: %d\n", stored);

        sent = (stored >= rate) ? rate : stored;

        stored -= sent;

        printf("Packets sent: %d\n", sent);
        printf("Packets left in bucket after sending: %d\n", stored);
    }

    return 0;
}   