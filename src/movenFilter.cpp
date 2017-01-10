#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <set>
#include <string>
using namespace std;

#define MAX_NAME_LEN 256
#define MAX_LINE_LEN 256

int movenFilter(char *org, char *flt, char *dst) {
    FILE *filter = fopen(flt, "rb");
    char orgName[MAX_NAME_LEN];
    char dstName[MAX_NAME_LEN];
    char filterName[MAX_NAME_LEN];
    char line[MAX_LINE_LEN];
    DIR * dp = opendir(org);
    struct dirent *dirp;
    set<string> filterSet;
    if (!filter || !dp) {
        goto Error;
    }

    while (fgets(line, MAX_LINE_LEN, filter)) {
        int n = strlen(line);
        line[n-1] = 0;        
        sprintf(filterName, "%s%s",line, ".afp");
        string fltName(filterName);
        filterSet.insert(fltName);
    }
    fclose(filter);

    while (dirp = readdir(dp)) {
        if (!strcmp(".", dirp->d_name) ||
            !strcmp("..", dirp->d_name)) {
            continue;
        }
        string tmp(dirp->d_name);
        if (filterSet.find(tmp) != filterSet.end()) {
            continue;
        }
        sprintf(orgName, "%s/%s", org, tmp.c_str());
        sprintf(dstName, "%s/%s", dst, tmp.c_str());
        rename(orgName, dstName);
    }

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

    if (-1 == movenFilter(org_name, flt_name, dst_name)) {
        printf ("call Error");
        goto Error;
    }

    return 0;
Error:
    return -1;
}
