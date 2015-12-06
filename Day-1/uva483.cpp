#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

void reverseString(char c[], int stIdx, int endIdx)
{
    int i, j;
    char t;
    for(i=stIdx, j=endIdx;i<j;i++, j--)
    {
        t = c[i];
        c[i] = c[j];
        c[j] = t;
    }
}
void uva483()
{
    char line[1000];

    int ws, we, IN=0;
    int j;
    while(gets(line)!=NULL)
    {
        for(j=0;line[j]!='\0';j++)
        {
            if(isspace(line[j]))
            {
                if(IN){
                    IN = 0;
                    we = j-1;
                    reverseString(line, ws, we);
                }
            }
            else
            {
                if(!IN){
                    IN = 1;
                    ws = j;
                }

            }
        }

        if(IN==1){
            reverseString(line, ws, j-1);
            IN=0;
        }

        printf(line);
        printf("\n");
    }
}

