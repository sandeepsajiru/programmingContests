#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

#define MAX 40

using namespace std;

char mapping[] = {'2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', '6', '6', '7', '7', '7', '7', '8', '8', '8', '9', '9', '9', '9'};
char line[MAX];

void uva10921()
{
    int i;
    char c;
    while(gets(line))
    {
        for(i=0; (c=line[i])!='\0'; i++)
        {
            if(isalpha(c))
                putchar(mapping[c-'A']);
            else
                putchar(c);
        }
        printf("\n");
    }
}


