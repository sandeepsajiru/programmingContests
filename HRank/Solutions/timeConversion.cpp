#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

//https://www.hackerrank.com/challenges/time-conversion
void timeConversion(){
    char* time = (char *)malloc(10240 * sizeof(char));
    scanf("%s",time);
    int len = strlen(time);
    bool isAM = true;

    // if 12:00 AM
    if(time[len-2]=='P')
        isAM = false;

    time[len-2] = '\0';

    int twoDigits;
    sscanf(time, "%d:", &twoDigits);
    //printf("%d", twoDigits);

    if(isAM && twoDigits==12)
    {
            time[0] = '0';
            time[1] = '0';
    }
    else if(!isAM && time[0]=='0')
    {
        twoDigits+= 12;
        time[1] = twoDigits%10+'0';
        time[0] = twoDigits/10+'0';
    }
    printf("%s\n", time);
}
