
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctime>

int main(void)
{
    struct tm* newtime;
    char am_pm[] = "AM";
    __time64_t long_time;

    _time64(&long_time);             // Get time as 64-bit integer.
    // Convert to local time.
    newtime = localtime(&long_time); // C4996
    // Note: _localtime64 deprecated; consider _localetime64_s

    if (newtime->tm_hour > 12)        // Set up extension.
        strcpy_s(am_pm, sizeof(am_pm), "PM");
    if (newtime->tm_hour > 12)        // Convert from 24-hour
        newtime->tm_hour -= 12;        //   to 12-hour clock.
    if (newtime->tm_hour == 0)        // Set hour to 12 if midnight.
        newtime->tm_hour = 12;

    char buff[30];
    asctime_s(buff, sizeof(buff), newtime);
    printf("%.19s %s\n", buff, am_pm);
}