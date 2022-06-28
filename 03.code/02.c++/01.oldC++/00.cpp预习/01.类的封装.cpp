#include <iostream>
using namespace std;

struct Date {
    int year;
    int month;
    int day;
};

void initDate(struct Date &data) {//初始化变量
    cout << "year, mouth, day" <<  endl;
    cin >> data.year;
    cin >> data.month;
    cin >> data.day;

}

void printDate(struct Date &data) {//打印
    cout << data.year << "年" <<  data.month << "月" << data.day << "日" << endl;
}

bool isLeapYear(struct Date &data) {//判断闰年
    if ((data.year % 4 == 0 && data.year % 100 != 0) || data.year % 400 == 0) return true;
    return false;
}
class MyDate {
public :
    int getYear() {
        return year;
    }
    void setYear(int newYear) {
        year = newYear;
    }
    void initDate() {//初始化变量
    cout << "year, mouth, day" <<  endl;
    cin >> year;
    cin >> month;
    cin >> day;
    }

    void printDate() {//打印
        cout << year << "年" <<  month << "月" << day << "日" << endl;
    }

    bool isLeapYear() {//判断闰年
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
        return false;
    }
private :
    int year;
    int month;
    int day;

};

int main () {
    #if 0
    Date d1;
    initDate(d1);
    printDate(d1);
    if (isLeapYear(d1)) cout << "是闰年" << endl;
    else cout << "不是闰年" << endl;
    #endif

    MyDate myDate;
    myDate.initDate();
    myDate.printDate();
    if (myDate.isLeapYear()) cout << "是闰年" << endl;
    else cout << "不是闰年" << endl;
    myDate.setYear(2000);
    cout << myDate.getYear() << endl;


    return 0;
}