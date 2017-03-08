#include <iostream>
#include <time.h>

int main()
{
    const char *time_details = "16:35:12";
    struct tm tm;

    strptime(time_details, "%H:%M:%S", &tm);

    time_t t = mktime(&tm);  // t is now your desired time_t

    std::cout << t << std::endl;
}
