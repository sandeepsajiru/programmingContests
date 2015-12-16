#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <algorithm>

using namespace std;
long long fact[21];

int cmpChars(const void * a, const void * b)
{
    return *(char*)a - *(char*)b;
}

void uva941()
{
    int i, pI;
    fact[0]=1;
    char line[22];
    for(i=1;i<=20;i++)
        fact[i] = i * fact[i-1];

    int t;
    scanf("%d\n", &t);
    while(t--!=0){
        gets(line);
        scanf("%s %d\n", &pI);
        //printf("UNSORTED: %s", line);
        qsort(line, strlen(line), sizeof(char), cmpChars);
        //printf("SORTED: %s\n", line);


    }
}


