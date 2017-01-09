#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_LINE_LEN 256

int moveFilter(char *org, char *flt, char *dst) {
    FILE *filter = fopen(flt, "rb");
    char orgName[MAX_NAME_LEN];
    char dstName[MAX_NAME_LEN];
    char line[MAX_LINE_LEN];

    if (!filter) {
        goto Error;
    }

    while (fgets(line, MAX_LINE_LEN, filter)) {
        int n = strlen(line);
        line[n-1] = 0;        
        sprintf(orgName, "%s/%s%s", org, line, ".afp");
        sprintf(dstName, "%s/%s%s", dst, line, ".afp");
        printf ("org = %s | dst = %s\n", orgName, dstName);
        rename(orgName, dstName);
    }
    fclose(filter);
    return 0;
Error:
    return -1;
}

int main(int argc, char **argv) {
    char *org_name;
    char *dst_name;
    char *flt_name;
    int ch;
    while (-1 != (ch=getopt(argc, argv, "o:f:d:"))) {
        switch(ch) {
            case 'o': {
                org_name = optarg;
                break;
            }
            case 'f': {
                flt_name = optarg;
                break;
            }
            case 'd': {
                dst_name = optarg;
                break;
            }
            default: {
                break;
            }
        }
    }

    if (!org_name || !flt_name || !dst_name) {
        printf ("param error\n");
        goto Error;
    }

    if (-1 == moveFilter(org_name, flt_name, dst_name)) {
        printf ("call Error");
        goto Error;
    }

    return 0;
Error:
    return -1;
}
