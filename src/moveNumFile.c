#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define MAX_NAME_LEN 256
#define MAX_LINE_LEN 256

int moveFilter(char *org, char *dst, int start, int end) {
    char orgName[MAX_NAME_LEN];
    char dstName[MAX_NAME_LEN];
    int i;
    int count = 0;
    for (i = start; i <= end; ++i) {
        sprintf(orgName, "%s/%d%s", org, i, ".afp");
        sprintf(dstName, "%s/%d%s", dst, i, ".afp");
        count ++;
        if ((count % 10000) == 0) {
            printf ("count = %d\n", count);
        }
        rename(orgName, dstName);
    }

    return 0;
Error:
    return -1;
}

int main(int argc, char **argv) {
    char *org_name;
    char *dst_name;
    int start = 0;
    int end = 0;
    int ch;
    while (-1 != (ch=getopt(argc, argv, "o:s:e:d:"))) {
        switch(ch) {
            case 'o': {
                org_name = optarg;
                break;
            }
            case 's': {
                start = atoi(optarg);
                break;
            }
            case 'e': {
                end = atoi(optarg);
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

    if (!org_name || !dst_name) {
        printf ("param error\n");
        goto Error;
    }

    if (-1 == moveFilter(org_name, dst_name, start, end)) {
        printf ("call Error");
        goto Error;
    }

    return 0;
Error:
    return -1;
}
