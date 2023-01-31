#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void formatCheck(char *time);

int main(void)
{
    system("clear");
    long int h, m, s;
    char *timeInput = malloc(9 * sizeof(char));
    printf("Enter a time in the format hh:mm:ss.\n");
    scanf("%s", timeInput);
    system("clear");

    /* for debugging
    printf("\nYou entered %s.\n", timeInput);
    */

    formatCheck(timeInput);

    char *hour = malloc(2 * sizeof(char));
    for (int i = 0; i < 2; i++)
    {
        hour[i] = timeInput[i];
    }
    h = strtol(hour, NULL, 10);
    
    char *minute = malloc(2 * sizeof(char));
    for (int i = 3; i < 5; i++)
    {
        minute[i-3] = timeInput[i];
    }
    m = strtol(minute, NULL, 10);
    
    char *second = malloc(2 * sizeof(char));
    for (int i = 6; i < 9; i++)
    {
        second[i-6] = timeInput[i];
    }
    s = strtol(second, NULL, 10);

    if (h > 24 || m > 60 || s > 60 || h < 0 || m < 0 || s < 0)
    {
        printf("Please enter a proper time.\n");
        return 1;
    }

    while (1)
    {
        printf("%02li:%02li:%02li\n", h, m, s);
        s++;
        if (s > 59)
        {
            s = 0;
            m++;
        }
        if (m > 59)
        {
            m = 0;
            h++;
        }
        if (h > 23)
        {
            h = 0;
            s++;
        }
        sleep(1);
        system("clear");
    }
    
    free(timeInput);
    free(hour);
    free(minute);
    free(second);
}

void formatCheck(char *time)
{
    if (strlen(time) != 8)
    {
        printf("Your time string was not the correct length.\n");
        free(time);
        return;
    }

    int Colons = 0;
    for (int i = 0; i < strlen(time); i++)
    {
        if (time[i] == ':')
        {
            Colons++;
        }
    }
    if (Colons != 2)
    {
        printf("You did not include the correct amount of colons. Colons: %i\n", Colons);
        free(time);
        return;
    }
    /* no clue what's wrong with this
    if (time[2] != ':' || time[5] != ':')
    {
        printf("Your colons are not in the right place.");
        free(time);
        return;
    }
    */
}