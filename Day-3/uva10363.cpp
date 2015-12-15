#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

bool isWinner(char line[], char c)
{
    int i;

    // ROW WINNER
    for(i=0; i<9; i=i+3)
        if(line[0+i]==c && line[1+i]==c && line[2+i]==c)
            return true;

    // COL WINNER
    for(i=0; i<3; i++)
        if(line[0+i]==c && line[3+i]==c && line[6+i]==c)
            return true;

    // TOP-LEFT->BOTTOM-RIGHT
    if(line[0]==c && line[4]==c && line[8]==c)
        return true;

    if(line[2]==c && line[4]==c && line[6]==c)
        return true;

    return false;
}

void uva10363()
{
    char line[10];
    line[9]='\0';
    int t;
    scanf("%d", &t);
    //printf("TC: %d\n",t);
    while(t-->0)
    {
        int i=0;
        while(i!=9)
        {
            char c = getchar();
            if(!isspace(c))
                line[i++]=c;
        }
        int x=0, o=0;
        for(i=0; line[i]!='\0'; i++)
        {
            if(line[i]=='X')
                x++;
            else if(line[i]=='O')
                o++;
        }

        if(isWinner(line, 'X') && isWinner(line, 'O'))
            printf("no\n");
        else if(isWinner(line, 'X'))
        {
            if(x-o==1)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(isWinner(line, 'O'))
        {
            if(x==o)
                printf("yes\n");
            else
                printf("no\n");
        }
        else if(x==o || x-o==1)
            printf("yes\n");
        else
            printf("no\n");

    }

}

int main()
{
    uva10363();
    return 0;
}
