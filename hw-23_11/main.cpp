//Визначити структуру Date, в якій три поля: день (1..31),
// місяць типу Months і рік – ціле число. В основній програмі
// створити масив з 5 елементів типу Date і ввести дати, вивести дату, яка найближча до сьогоднішньої

#include <iostream>
#include <string>
#include <time.h>

using  namespace std;
struct Date
{
    int day;
    string months;
    int year;
};

Date getClosest(struct Date dates[5]){
    time_t theTime = time(NULL);
    Date closesDate = dates[1];
    struct tm *aTime = localtime(&theTime);
    int current_day = aTime->tm_mday;
    int curent_month = aTime->tm_mon + 1;
    int current_year = aTime->tm_year + 1900;

    for(int i = 1; i<= 4;i++)
    {
        if(dates[i].year > closesDate.year ){
            closesDate.year = dates[i].year;
            if(dates[i].day > closesDate.day ){
                closesDate.day = dates[i].day ;
            }
        }

    }

    return closesDate;

}
void getDate(struct Date date) {
    cout << "-------\n";
    cout << "date\t" << date.day << endl;
    cout << "date\t" << date.months << endl;
    cout << "date\t" << date.year << endl;
}
int main() {
    struct Date dates[5] =
            {
                    {3,"Dec",2020},
                    {10,"Feb",2022},
                    {21,"Jun",2019},
                    {15,"Nov",2022},
            };
    getDate(getClosest(dates));
    return 0;
}
