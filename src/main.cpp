#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

//Type 1 is substract 1 day by using 86400 second
time_t get1daySubtacted_Type1(time_t timePoint)
{
    return timePoint - 86400;
}

//Type 2 is substract 1 day by using struct tm
time_t get1daySubtacted_Type2(const time_t timePoint)
{
    struct tm tm;
    time_t tp = timePoint;
    localtime_r(&tp, &tm);

    tm.tm_mday-=1;
    tm.tm_isdst=-1;

    return mktime(&tm);
}

void printDayTimeStmap(const time_t timePoint)
{
    cout << "timestamp: " << timePoint << endl;
}

void printDayTimeString(const time_t timePoint)
{
    struct tm tm;
    time_t tp = timePoint;
    localtime_r(&tp, &tm);


    cout << "timeString: " << asctime(&tm) << endl;
}

int main()
{
    
    cout << "----------- Testing DST timestamp -----------" << endl;
    {
    time_t current_ts = time(NULL);
    struct tm current_tm;
    localtime_r(&current_ts, &current_tm);
    char buf[16];
    strftime(buf, sizeof(buf), "%z", &current_tm);
    
    std::cout << "Current timezone (POSIX): " << current_tm.tm_zone << " (" << buf << ")" << std::endl;
    cout << "\nCurrent time: " << endl;
    printDayTimeStmap(current_ts);
    printDayTimeString(current_ts);

    cout << "\nSubtract 1 day (Type1): " << endl;
    time_t current_ts_Sub1day = get1daySubtacted_Type1(current_ts);
    printDayTimeStmap(current_ts_Sub1day);
    cout << "diff: " << current_ts-current_ts_Sub1day<< endl;
    printDayTimeString(current_ts_Sub1day);

    cout << "Subtract 1 day (Type2): " << endl;
    time_t current_ts_Sub1day_t2 = get1daySubtacted_Type2(current_ts);
    printDayTimeStmap(current_ts_Sub1day_t2);
    cout << "diff: " << current_ts-current_ts_Sub1day_t2<< endl;
    printDayTimeString(current_ts_Sub1day_t2);


    }

    cout << "----------- Testing Entering DST (EST -> EDT) -----------" << endl;
    //We are in EDT time, -1 day should be in EST time
    {
        time_t ts = 1710054001; //Sunday, March 10, 2024 3:00:01 AM GMT-04:00 DST
        cout << "\nCurrent time (Sunday, March 10, 2024 3:00:01 AM GMT-04:00 DST): " << endl;
        printDayTimeStmap(ts);
        printDayTimeString(ts);

        cout << "\nSubtract 1 day (Type1): " << endl;
        time_t current_ts_Sub1day = get1daySubtacted_Type1(ts);
        printDayTimeStmap(current_ts_Sub1day);
        cout << "diff: " << ts-current_ts_Sub1day<< endl;
        printDayTimeString(current_ts_Sub1day);

        cout << "Subtract 1 day (Type2): " << endl;
        time_t current_ts_Sub1day_t2 = get1daySubtacted_Type2(ts);
        printDayTimeStmap(current_ts_Sub1day_t2);
        cout << "diff: " << ts-current_ts_Sub1day_t2<< endl;
        printDayTimeString(current_ts_Sub1day_t2);
    
    }
    cout << "----------- Testing Exiting DST (EDT -> EST)  -----------" << endl;
    //We are in EST time, -1 day should be in EST time
    {
        time_t ts = 1699164001; //Sunday, November 5, 2023 1:00:01 AM GMT-05:00

        cout << "\nCurrent time (Sunday, November 5, 2023 1:00:01 AM GMT-05:00): " << endl;
        printDayTimeStmap(ts);
        printDayTimeString(ts);

        cout << "\nSubtract 1 day (Type1): " << endl;
        time_t current_ts_Sub1day = get1daySubtacted_Type1(ts);
        printDayTimeStmap(current_ts_Sub1day);
        cout << "diff: " << ts-current_ts_Sub1day<< endl;
        printDayTimeString(current_ts_Sub1day);

        cout << "Subtract 1 day (Type2): " << endl;
        time_t current_ts_Sub1day_t2 = get1daySubtacted_Type2(ts);
        printDayTimeStmap(current_ts_Sub1day_t2);
        cout << "diff: " << ts-current_ts_Sub1day_t2<< endl;
        printDayTimeString(current_ts_Sub1day_t2);
    }

    return 0;
}

