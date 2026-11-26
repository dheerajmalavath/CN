#include <stdio.h>

void printIp(const char *label, unsigned int ip) {
    printf("%s: %u.%u.%u.%u\n", label, (ip >> 24) & 255, (ip >> 16) & 255, (ip >> 8) & 255, ip & 255);
}

int main() {
    unsigned int a, b, c, d;
    int p;

    printf("Enter IP address (e.g., 192.168.1.0): ");
    scanf("%u.%u.%u.%u", &a, &b, &c, &d);
    printf("Enter current prefix length (e.g., 24): ");
    scanf("%d", &p);

    unsigned int ip = (a << 24) | (b << 16) | (c << 8) | d;
    unsigned int mask = p == 0 ? 0 : ~((1U << (32 - p)) - 1);
    unsigned int newMask = ~((1U << (31 - p)) - 1);

    printf("\nNumber of subnets: 2\n");
    printf("Number of hosts per subnet: %u\n", (1U << (31 - p)) - 2);

    for (int i = 0; i < 2; i++) {
        unsigned int net = (ip & mask) | ((unsigned int)i << (31 - p));
        unsigned int bcast = net | ~newMask;

        printf("\nSubnet %d:\n", i + 1);
        printIp("Network Address", net);
        printIp("Broadcast Address", bcast);
        printIp("Subnet Mask", newMask);
        printIp("First Host", net + 1);
        printIp("Last Host", bcast - 1);
    }

    return 0;
}