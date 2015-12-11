#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>

using namespace std;

/* APPROACH - 2 */

char encodingChar[]= {'-', '1', '2','3', '-', '1', '2', '-', '-', '2','2', '4', '5', '5', '-', '1', '2', '6', '2', '3', '-', '1', '-', '2', '-', '2'};

void printSoundexCode(char name[])
{
    char code[5];
    strcpy(code, "0000");
    char curEC, prevEC;

    code[0] = name[0];
    prevEC = encodingChar[name[0]-'A'];


    int i, j=1;
    for(i=1; name[i]!='\0'; i++)
    {
        curEC = encodingChar[name[i]-'A'];
        if(curEC!='-' && curEC!=prevEC)
        {
            code[j++] = curEC;
            if(j==4)
                break;
        }
        prevEC = curEC;
    }

    printf("%9s%-25s%s\n", "", name, code);
}

void uva739_2()
{
    char name[1000];
    printf("%9s%s%21s%s\n", "", "NAME","", "SOUNDEX CODE");
    while(gets(name)!=NULL)
    {
        printSoundexCode(name);
    }
    printf("%19s%s\n", "", "END OF OUTPUT");
}


/* APPROACH - 1 */

bool isEncoded(char c)
{
    if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='Y' || c=='W' || c=='H')
        return false;
    return true;
}

int getEncodeDigit(char c)
{
    switch(c)
    {
    case 'B':
    case 'P':
    case 'F':
    case 'V':
        return 1;
    case 'C':
    case 'S':
    case 'K':
    case 'G':
    case 'J':
    case 'Q':
    case 'X':
    case 'Z':
        return 2;
    case 'D':
    case 'T':
        return 3;
    case 'L':
        return 4;
    case 'M':
    case 'N':
        return 5;
    case 'R':
        return 6;
    default:
        return -1;
    }
}
void generateAndPrintSoundexCode(char name[])
{
    char code[5];
    int i, j=1;
    code[0] = name[0];
    char prev=code[0], cur;
    for(i=1; name[i]!='\0'; i++)
    {
        cur = name[i];
        if(isEncoded(cur) && getEncodeDigit(cur)!=getEncodeDigit(prev))
        {
            code[j] = getEncodeDigit(cur)+'0';
            j++;
            if(j==4)
            {
                break;
            }
        }
        prev = name[i];
    }

    for(; j<4; j++)
        code[j] = '0';
    code[j]='\0';
    printf("%9s%-25s%s\n", "", name, code);
}

void uva739_1()
{
    char name[1000];
    printf("%9s%s%21s%s\n", "", "NAME","", "SOUNDEX CODE");
    while(gets(name)!=NULL)
    {
        generateAndPrintSoundexCode(name);
    }
    printf("%19s%s\n", "", "END OF OUTPUT");
}


