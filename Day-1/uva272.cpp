#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;


void uva272()
{
    char line[1000];
    bool start = false;
    int i;
    while(gets(line)!=NULL)
    {
        for(i=0;line[i]!='\0';i++)
        {
            if(line[i]=='"'){
                if(start==false){
                    printf("``");

                }
                else{
                    printf("''");
                }
                start = !start;
            }
            else
                putchar(line[i]);
        }
        printf("\n");

    }
}
