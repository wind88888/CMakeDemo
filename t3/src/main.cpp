//
// Created by ruiy on 20-11-26.
//

// 此头文件在/tmp324/t3/usr/local/include/hello目录下，不在系统标准的头文件路径中(/usr/local/include(不一定是这个路径))
#include "hello.h"
#include <iostream>
#include <assert.h>
#include <ctime>
#include <string> // std::to_string
#include <sstream> // std::stringstream

std::string DatetimeToString(time_t time)
{
    tm *tm_ = localtime(&time);                // 将time_t格式转换为tm结构体
    int year, month, day, hour, minute, second;// 定义时间的各个int临时变量。
    year = tm_->tm_year + 1900;                // 临时变量，年，由于tm结构体存储的是从1900年开始的时间，所以临时变量int为tm_year加上1900。
    month = tm_->tm_mon + 1;                   // 临时变量，月，由于tm结构体的月份存储范围为0-11，所以临时变量int为tm_mon加上1。
    day = tm_->tm_mday;                        // 临时变量，日。
    hour = tm_->tm_hour;                       // 临时变量，时。
    minute = tm_->tm_min;                      // 临时变量，分。
    second = tm_->tm_sec;                      // 临时变量，秒。
    char yearStr[5], monthStr[3], dayStr[3], hourStr[3], minuteStr[3], secondStr[3];// 定义时间的各个char*变量。
    sprintf(yearStr, "%d", year);              // 年。
    sprintf(monthStr, "%d", month);            // 月。
    sprintf(dayStr, "%d", day);                // 日。
    sprintf(hourStr, "%d", hour);              // 时。
    sprintf(minuteStr, "%d", minute);          // 分。
    if (minuteStr[1] == '\0')                  // 如果分为一位，如5，则需要转换字符串为两位，如05。
    {
        minuteStr[2] = '\0';
        minuteStr[1] = minuteStr[0];
        minuteStr[0] = '0';
    }
    sprintf(secondStr, "%d", second);          // 秒。
    if (secondStr[1] == '\0')                  // 如果秒为一位，如5，则需要转换字符串为两位，如05。
    {
        secondStr[2] = '\0';
        secondStr[1] = secondStr[0];
        secondStr[0] = '0';
    }
    char s[20];                                // 定义总日期时间char*变量。
    sprintf(s, "%s-%s-%s %s:%s:%s", yearStr, monthStr, dayStr, hourStr, minuteStr, secondStr);// 将年月日时分秒合并。
    std::string str(s);                             // 定义string变量，并将总日期时间char*变量作为构造函数的参数传入。
    return str;                                // 返回转换日期时间后的string变量。
}

int main(){
    HelloFunc();
    time_t t = time(0);
//    char ch[64];
//    strftime(ch, sizeof(ch), "%Y-%m-%d %H-%M-%S", localtime(&t)); //年-月-日 时-分-秒
//    std::cout << ch << std::endl;

    std::cout << DatetimeToString(t) << std::endl;
    return 0;
}