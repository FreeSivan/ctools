#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE_LEN 256

int findLine(char *org, char *dst, char *flt) {
    printf ("3\n");
    FILE *forg = fopen(org, "rb");
    FILE *fdst = fopen(dst, "wb");
    char line[MAX_LINE_LEN];
    if (!forg || !fdst) {
        return -1;
    }
    printf ("4\n");
    while (fgets(line, MAX_LINE_LEN, forg)) {
        if (!strstr(line, flt)) {
            continue;
        }
        fputs(line, fdst);
    }
    fclose(forg);
    fclose(fdst);
}

int main(int argc, char **argv) {
    char *org = 0;
    char *dst = 0;
    char *flt = 0;
    int ch = -1;

    while (-1 != (ch=getopt(argc, argv, "o:d:m:"))) {
        switch(ch) {
        case 'o': {
            org = optarg;
            break;
        }
        case 'd': {
            dst = optarg;
            break;
        }
        case 'm': {
            flt = optarg;
            break;
        }
        default: {
            break;
        }
        }
    }
    printf ("1\n");
    if (!org || !dst || !flt) {
        printf ("param error!\n");
        goto Error;
    }

    printf ("2\n");
    if (-1 == findLine(org, dst, flt)) {
        printf ("deal line Error!\n");
        goto Error;
    }
    printf ("6\n");

    return 0;
Error:
    return -1;
}


