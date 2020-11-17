#include <stdio.h>

int
main(int argc, char **argv){
    unsigned int randval;
    FILE *f;

    f = fopen("/dev/urandom", "r");
    fread(&randval, sizeof(randval), 1, f);
    fclose(f);

    printf("%u\n", randval);

    return 0;
}