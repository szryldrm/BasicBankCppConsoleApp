#include <iostream>
#include <cstddef>
#include <sstream>
#include <string>
#include "stack.h"
#include "queue.h"

using namespace std;


double TempBalance[5] = {0, 0, 0, 0, 0};
double TempDept[5]{0, 0, 0, 0, 0};


struct CstBilgi {
    string cstNameSurname, cstID;
    double cstBalance;
    double cstDept;
} cstBilgi[5];

stack stack[5];
queue<CstBilgi> cstQueue;
CstBilgi GeciciQueue;
int choice;

string convertDoubleToString(double dbl) {
    std::ostringstream strs;
    strs << dbl;
    std::string str = strs.str();
    return str;
}

std::string strikethrough(const std::string &text) {
    std::string result;
    for (auto ch : text) {
        result.append(u8"\u0336");
        result.push_back(ch);
    }
    return result;
}

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d / %H:%M", &tstruct);
    return buf;
}

void bilgiDoldur() {
    cstBilgi[0].cstID = "16070006144";
    cstBilgi[0].cstNameSurname = "Sezer YILDIRIM";
    cstBilgi[0].cstBalance = TempBalance[0];
    cstBilgi[0].cstDept = TempDept[0];

    cstBilgi[1].cstID = "16070006155";
    cstBilgi[1].cstNameSurname = "Onur HIZLAN";
    cstBilgi[1].cstBalance = TempBalance[1];
    cstBilgi[1].cstDept = TempDept[1];

    cstBilgi[2].cstID = "16070006152";
    cstBilgi[2].cstNameSurname = "Volkan GÜRBÜZ";
    cstBilgi[2].cstBalance = TempBalance[2];
    cstBilgi[2].cstDept = TempDept[2];

    cstBilgi[3].cstID = "16070006171";
    cstBilgi[3].cstNameSurname = "Görkem YILDIRIM";
    cstBilgi[3].cstBalance = TempBalance[3];
    cstBilgi[3].cstDept = TempDept[3];

    cstBilgi[4].cstID = "161170006185";
    cstBilgi[4].cstNameSurname = "Ramazan DURSUN";
    cstBilgi[4].cstBalance = TempBalance[4];
    cstBilgi[4].cstDept = TempDept[4];

    for (int i = 0; i < 5; ++i) {
        cstQueue.enqueue(cstBilgi[i]);
    }

}

void cstClean() {
    while (!cstQueue.empty()) {
        cstQueue.dequeue();
    }
}

void cstShow() {
    cstClean();
    bilgiDoldur();
    for (int i = 0; i < 5; ++i) {
        cout << i << " - " + cstQueue.getFront().cstNameSurname << endl;
        cstQueue.dequeue();
    }
    bilgiDoldur();

}

CstBilgi getCST(int index) {
    if (index == 0) {
        return cstQueue.getFront();
    } else {
        for (int i = 0; i < index; ++i) {
            cstQueue.dequeue();
        }
    }
    return cstQueue.getFront();
}

void deposit(int index, double money) {
    cstClean();
    bilgiDoldur();
    CstBilgi temp = getCST(index);
    double geciciBalance = temp.cstBalance + money;
    TempBalance[index] = geciciBalance;
    cstClean();
    bilgiDoldur();
    stack[index].push(currentDateTime() + " - " + temp.cstNameSurname + " deposits " + convertDoubleToString(money) + " dollars into account");
}

void withdraw(int index, double money) {
    cstClean();
    bilgiDoldur();
    CstBilgi temp = getCST(index);
    if (temp.cstBalance >= money) {
        double geciciBalance = temp.cstBalance - money;
        TempBalance[index] = geciciBalance;
        stack[index].push(currentDateTime() + " - " + temp.cstNameSurname + " withdraws " + convertDoubleToString(money) + " dollars into account");
    } else {
        if (temp.cstBalance == 0)
            cout << "\033[1;31m\nSorry! Your Balance Is '0' So You Cannot Withdraw.\n\033[0m\n" << endl;
        else
            cout << "\033[1;31m\nSorry! Your Balance Is Not Enough.(You Can Withdraw Max : "<<"\033[1;37m" + convertDoubleToString(temp.cstBalance) + " $)\n\033[0m" << endl;
    }
    cstClean();
    bilgiDoldur();
}

void lendMoney(int index, double money) {
    cstClean();
    bilgiDoldur();
    CstBilgi temp = getCST(index);
    double geciciBalance = temp.cstBalance + money;
    TempBalance[index] = geciciBalance;
    TempDept[index] = money + (money * 0.10);
    cstClean();
    bilgiDoldur();
    stack[index].push(currentDateTime() + " - " + temp.cstNameSurname + " lends money " + convertDoubleToString(money) + " dollars with %20 interest");
}

void payDebt(int index, double money) {
    cstClean();
    bilgiDoldur();
    CstBilgi temp = getCST(index);
    if(temp.cstBalance >= money)
    {
        if(money <= temp.cstDept){
            double geciciBalance = temp.cstBalance - money;
            double geciciDept = temp.cstDept - money;
            TempBalance[index] = geciciBalance;
            TempDept[index] = geciciDept;
            stack[index].push(currentDateTime() + " - " + temp.cstNameSurname + " pay debts " + convertDoubleToString(money) + " dollars");
        } else
            cout << "\033[1;32m\nYou Cannot Pay More Than Your Dept!\n\033[0m\n" << endl;
    }
    else{
        cout << "\033[1;33m\nYou Haven't Got Enough Money!\n\033[0m\n" << endl;
    }
    cstClean();
    bilgiDoldur();
}

void showAccountInfo(int index){
    cstClean();
    bilgiDoldur();
    CstBilgi temp = getCST(index);
    cout<<"Customer Name: "<< "\033[1;32m" + temp.cstNameSurname + "\033[0m\n"<<endl;
    cout<<"Customer ID: "<<"\033[1;32m" + temp.cstID + "\033[0m\n"<<endl;
    cout<<"Customer Balance: "<<"\033[1;32m" + convertDoubleToString(temp.cstBalance) + "\033[0m\n"<<endl;
    cout<<"Customer Dept: "<<"\033[1;32m" + convertDoubleToString(temp.cstDept) + "\033[0m\n"<<endl;
    cout<<"Account Movements/Statements:\n"<<endl;
    while(!stack[index].IsEmpty(0)){
        cout<<"\033[1;35m" + stack[index].pop() + "\033[0m\n"<<endl;
    }

}

int main() {
    cstShow();
    cout << "\nChoice A Customer Number" << endl;
    cin >> choice;
    while (choice > 4) {
        cstShow();
        cout << "\033[1;31m\nChoice Again A Valid Customer Number\033[0m\n" << endl;
        cin >> choice;
    }
    GeciciQueue = getCST(choice);
    int switchChoice;
    double money;
    while (switchChoice != 7) {
        cout << "What Do You Want To Do " << "\033[1;33m" + GeciciQueue.cstNameSurname + "\033[0m"
             << " (Your Balance Is : " << "\033[1;36m" + convertDoubleToString(GeciciQueue.cstBalance) + " $" + "\033[0m"
             << " And Your Dept Is : " << "\033[1;36m" + convertDoubleToString(GeciciQueue.cstDept) + " $" + "\033[0m"
             << ")" << "\n" << endl;
        cout << "1. Deposit" << endl;
        cout << "2. Withdraw" << endl;
        if (GeciciQueue.cstDept == 0)
            cout << "3. Lend Money with %20 Interest (Max : 1000$)" << endl;
        else
            cout << "\033[1;31m" + strikethrough("3. Lend Money with %10 Interest (Max : 1000$)") + "\033[0m" << endl;
        cout << "4. Pay your debt" << endl;
        cout << "5. Show Account Information" << endl;
        cout << "6. Logout" << endl;
        cout << "7. Exit" << endl;
        cin >> switchChoice;
        switch (switchChoice) {
            case 1 :
                cout << "\nEnter Money To Deposit" << endl;
                cin >> money;
                while (money < 0) {
                    cout << "\033[1;31m\nPlease Enter Valid Money!\n\033[0m\n" << endl;
                    cout << "Enter Money" << endl;
                    cin >> money;
                }
                deposit(choice, money);
                cstClean();
                bilgiDoldur();
                GeciciQueue = getCST(choice);
                break;
            case 2 :
                cout << "\nEnter Money To WithDraw" << endl;
                cin >> money;
                while (money < 0) {
                    cout << "\033[1;31m\nPlease Enter Valid Money!\n\033[0m\n" << endl;
                    cout << "Enter Money" << endl;
                    cin >> money;
                }
                withdraw(choice, money);
                GeciciQueue = getCST(choice);
                break;
            case 3 :
                if (GeciciQueue.cstDept == 0) {
                    cout << "\nEnter Money To Lend" << endl;
                    cin >> money;
                    while (money < 0) {
                        cout << "\033[1;31m\nPlease Enter Valid Money!\n\033[0m\n" << endl;
                        cout << "Enter Money" << endl;
                        cin >> money;
                    }
                    while(money > 1000){
                        cout << "\033[1;36m\nYou Can Lend MAX 1000 $\n\033[0m\n" << endl;
                        cout << "Enter Money" << endl;
                        cin >> money;
                    }
                    lendMoney(choice, money);
                    GeciciQueue = getCST(choice);
                } else
                    cout << "\033[1;31m\nFirstly, You Have To Pay Your Dept!\n\033[0m\n" << endl;
                break;
            case 4 :
                if(GeciciQueue.cstDept > 0){
                    cout << "\nEnter Money To Pay Your Debt" << endl;
                    cin >> money;
                    while (money < 0) {
                        cout << "\033[1;31m\nPlease Enter Valid Money!\n\033[0m\n" << endl;
                        cout << "Enter Money" << endl;
                        cin >> money;
                    }
                    payDebt(choice, money);
                    GeciciQueue = getCST(choice);
                }
                else{
                    cout << "\033[1;33m\nYou Haven't Got Any Dept!\n\033[0m\n" << endl;
                }
                break;
            case 5 :
                showAccountInfo(choice);
                cout<<"\n\n"<<endl;
                break;
            case 6 :
                cstShow();
                cout << "\nChoice A Customer Number" << endl;
                cin >> choice;
                while (choice > 4) {
                    cstShow();
                    cout << "\033[1;31m\nChoice Again A Valid Customer Number\033[0m\n" << endl;
                    cin >> choice;
                }
                GeciciQueue = getCST(choice);
                break;
            case 7 :
                break;
            default :
                cout << "\033[1;31m\nPlease Enter Valid Number!\033[0m\n" << endl;
        }
    }
    return 0;
}