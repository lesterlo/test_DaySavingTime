#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

int main()
{
    
    cout << "Testing DST timestamp" << endl;
    {
    time_t current_ts = time(NULL);
    struct tm current_tm;
    localtime_r(&current_ts, &current_tm);

    cout << "Current timestamp: " << current_ts << endl;
    cout << "Current timestamp: " << asctime(&current_tm) << endl;

    time_t current_ts_Sub1day = current_ts-86400;
    struct tm current_tm_Sub1day;
    localtime_r(&current_ts_Sub1day, &current_tm_Sub1day);
    cout << "Current timestamp -1day: " << asctime(&current_tm_Sub1day) << endl;

    }
    cout << "Testing Entering DST (EST -> EDT)" << endl;

    cout << "Testing Exiting DST (EDT -> EST)" << endl;

    return 0;
}