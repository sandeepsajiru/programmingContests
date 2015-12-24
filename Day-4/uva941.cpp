#include <cstdlib>
#include <cstdio>
#include <cstring>

unsigned long long fact[21];

void calcFactorial()
{
    int i;
    fact[0]=1;
    for(i=1;i<21;i++)
        fact[i] = i * fact[i-1];
}

int cmp(const void *a, const void *b)
{
    return (*(char *)a- *(char *)b);
}


void uva941()
{
    calcFactorial();
    unsigned long long n;
    int t;
    scanf("%d\n", &t);
    char str[30];
    while(t--)
    {
        scanf("%s", str);
        qsort(str, strlen(str), sizeof(char), cmp);

        scanf("%llu", &n);

        int len = strlen(str);
        char remaining[len+1];
        strcpy(remaining, str);
        char sol[len+1];

        int i;
        for (i = 0; i < len; i++) {
            int idx = n / fact[len - i - 1];
            sol[i] = remaining[idx];
            int j;
            for (j = idx; j + 1 < strlen(remaining); j++)
                remaining[j] = remaining[j + 1];
            remaining[j] = '\0';
            n -= idx * fact[len - i - 1];
        }
        sol[i]='\0';
        printf("%s\n", sol);
    }
}

int main()
{
    uva941();
    return 0;
}
