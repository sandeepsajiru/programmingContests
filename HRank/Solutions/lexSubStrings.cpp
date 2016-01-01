#include<stdio.h>
#include<string.h>
#include <algorithm>

using namespace std;

char ori[17];
char res[17];

void printLex(int idx, int ci)
{
    if(ori[idx]=='\0')
        return;
	res[idx] = ori[ci];
	res[idx+1] = '\0';

	printf("%s\n", res);
    int i;
	for(i=ci+1;ori[i]!='\0';i++)
	{
		printLex(idx+1, i);
	}
	res[idx] = '\0';
}
void printAllLex()
{
	int i;
	for(i=0;ori[i]!='\0';i++)
		printLex(0, i);
}

//https://www.hackerrank.com/challenges/building-a-list
void buildlingAList()
{
    int t, len;
    scanf("%d", &t);
    while(t--)
    {
        scanf("%d\n", &len);
        scanf("%s", ori);

        sort(ori, ori+strlen(ori));
        //printf("%s", ori);
        printAllLex();
    }
}
