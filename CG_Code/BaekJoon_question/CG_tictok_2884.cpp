#include <iostream>

using namespace std;

int main()
{
    int hours = 0, minutes = 0;

    cin >> hours;
    cin >> minutes;

    minutes -= 45;

    if (minutes < 0) // 기본적인 시간연산
    {
        minutes += 60;
        hours--;
    }    
    if (hours < 0)
    {
        hours = 23;
    }
    cout << hours << " " << minutes;

    return 0;
}