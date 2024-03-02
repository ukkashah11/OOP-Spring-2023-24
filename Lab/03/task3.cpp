/*Syed Ukkashah Ahmed Shah
  23K-0055
*/
#include <iostream>
using namespace std;
class Calendar {
private:
    int year;
    string jan[30];
    string feb[30];
    string march[30];
    string april[30];
    string may[30];
    string jun[30];
    string jul[30];
    string aug[30];
    string sep[30];
    string nov[30];
    string oct[30];
    string dec[30];
    void show_one_month(string month[30]) {
        for (int i = 0; i < 30; i++) if (month[i].size() > 0) cout << month[i] << "  ";
        cout << endl;
    }
public:
    void addTask(int date, int month, string task) {
        switch(month) {
            case 1:
                jan[date-1] = task;
                break;
            case 2:
                feb[date-1] = task;
                break;
            case 3:
                march[date-1] = task;
                break;
            case 4:
                april[date-1] = task;
                break;
            case 5:
                may[date-1] = task;
                break;
            case 6:
                jun[date-1] = task;
                break;
            case 7:
                jul[date-1] = task;
                break;
            case 8:
                aug[date-1] = task;
                break;
            case 9:
                sep[date-1] = task;
                break;
            case 10:
                nov[date-1] = task;
                break;
            case 11:
                oct[date-1] = task;
                break;
            case 12:
                dec[date-1] = task;
        }
    }

    void remove_task(int date, int month) {
        switch(month) {
            case 1:
                jan[date-1] = "";
            case 2:
                feb[date-1] = "";
            case 3:
                march[date-1] = "";
            case 4:
                april[date-1] = "";
            case 5:
                may[date-1] = "";
            case 6:
                jun[date-1] = "";
            case 7:
                jul[date-1] = "";
            case 8:
                aug[date-1] = "";
            case 9:
                sep[date-1] = "";
            case 10:
                nov[date-1] = "";
            case 11:
                oct[date-1] = "";
            case 12:
                dec[date-1] = "";
        }
    }

    void show_all_tasks() {
        show_one_month(jan);
        show_one_month(feb);
        show_one_month(march);
        show_one_month(april);
        show_one_month(may);
        show_one_month(jun);
        show_one_month(jul);
        show_one_month(aug);
        show_one_month(sep);
        show_one_month(oct);
        show_one_month(nov);
        show_one_month(dec);
    }
};

int main(int argc, char const *argv[])
{
    Calendar calendar;
    calendar.addTask(6, 7, "Buy groceries");
    calendar.addTask(15, 2, "Do Laundry");
    calendar.addTask(10, 3, "Study");
    calendar.addTask(11, 3, "Eat food");
    calendar.remove_task(11, 3);
    calendar.addTask(11, 3, "go out with friends");
    calendar.show_all_tasks();
    return 0;
}