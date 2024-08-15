#include <stdio.h>

int main() {
    unsigned int num = 1;
    char *byte = (char*)&num;

    if (*byte) {
        printf("Little-endian\n");
    } else {
        printf("Big-endian\n");
    }

    return 0;
}

