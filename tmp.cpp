#include <iostream>
#include <string>
#include <minwindef.h>
#include <sysinfoapi.h>
#include <profileapi.h>
#include <synchapi.h>

using namespace std;

int main()
{
    DWORD startTimeStamp = GetTickCount();
    int j = 0;
    for (int i = 0; i < 999999; i++)
    {
        j += i;
    }

    LARGE_INTEGER freq_;
    QueryPerformanceFrequency(&freq_);

    LARGE_INTEGER begin_time;
    LARGE_INTEGER end_time;
    QueryPerformanceCounter(&begin_time);
    Sleep(100);
    QueryPerformanceCounter(&end_time);

    double ns_time = (end_time.QuadPart - begin_time.QuadPart) * 1000000.0 / freq_.QuadPart;

    DWORD endTimeStamp = GetTickCount();
    cout << endTimeStamp << "\t" << startTimeStamp << endl;
    cout << endTimeStamp - startTimeStamp;
}