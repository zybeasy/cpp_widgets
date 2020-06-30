#include <iostream>

#include <time.h>

using namespace std;

void time_usage() {
    struct timespec a;

    clock_gettime(CLOCK_REALTIME, &a);  // 挂钟时间
    cout << ctime(&a.tv_sec) << " " << a.tv_sec << " " << a.tv_nsec << endl;

    // 已系统启动时间作为基准时间，所以它是不可变的，修改系统时间不会影响到获取的值
    clock_gettime(CLOCK_MONOTONIC, &a);
    cout << ctime(&a.tv_sec) << " " << a.tv_sec << " " << a.tv_nsec << endl;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &a);
    cout << ctime(&a.tv_sec) << " " << a.tv_sec << " " << a.tv_nsec << endl;

    clock_gettime(CLOCK_THREAD_CPUTIME_ID, &a);
    cout << ctime(&a.tv_sec) << " " << a.tv_sec << " " << a.tv_nsec << endl;

    clock_getres(CLOCK_REALTIME, &a);
    cout << ctime(&a.tv_sec) << " " << a.tv_sec << " " << a.tv_nsec << endl;

    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);
    cout << now << " " << mktime(tm_now) << endl;
    cout << ctime(&now) << asctime(tm_now) << endl;
}
