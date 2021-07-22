#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <netinet/in.h>

int main(int argc, char *argv[]){

    FILE *file1;
    FILE *file2;
    uint32_t dat1, dat2, dat3;

    file1 = fopen(argv[1], "r");
    file2 = fopen(argv[1], "r");
    fread(&dat1, sizeof(uint32_t), 1, file1);
    fread(&dat2, sizeof(uint32_t), 1, file2);
    fclose(file1);
    fclose(file2);

    dat1 = ntohl(dat1);
    dat2 = ntohl(dat2);
    dat3 = dat1 + dat2;

    printf ("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", dat1, dat1, dat2, dat2, dat3, dat3);

    return 0;
}
