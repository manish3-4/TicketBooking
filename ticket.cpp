#include <bits/stdc++.h>
using namespace std;

class mainClass
{
private:
    char box[10][10]{0};

public:
    bool checkIfMarked(int a, int b) { return box[a][b] != '@'; }
    void printBox()
    {
        for (int i = 0; i < 10; ++i)
        {
            if (i == 0)
            {
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
                cout << "\t\t\t\t\tGOLD [250Rs/Person]" << endl;
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
            }
            else if (i == 5)
            {
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
                cout << "\t\t\t\t\tPlatinum [300Rs/Person]" << endl;
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
            }
            else if (i == 8)
            {
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
                cout << "\t\t\t\t\tSILVER [200Rs/Person]" << endl;
                cout << "------------------------------------------------------------"
                        "------------------------------------"
                     << endl;
            }
            cout << "ROW " << i << "\t\t";

            for (int j = 0; j < 10; ++j)
            {
                cout << box[i][j] << "    ";
            }
            cout << endl;
        }
    }
    void reset() { memset(box, '#', sizeof(box)); }
    void header()
    {
        system("clear");
        cout << "------------------------------------------------------------------"
                "-------------------------------"
             << endl;
        cout << "\t\t\t\t\tWELCOME TO LPU CALINERIA                               "
             << endl;
        cout << "\t\t\t One and only online ticket booking hub in LPU              "
                "      "
             << endl;
        cout << "------------------------------------------------------------------"
                "-------------------------------"
             << endl;
        cout << "Time : |" << currentTime(timeAndDate())
             << "|\t\t\t\t\t\t\t\tDate: |" << currentDate(timeAndDate()) << ' '
             << currentMonth(timeAndDate()) << ',' << currentYear(timeAndDate())
             << "|\t\t\t"
             << "  " << endl;
        cout << "------------------------------------------------------------------"
                "-------------------------------"
             << endl;
    }
    bool auth()
    {
        static int count = 0;
        string u, p;
        ifstream readp;
        readp.open("password.txt");
        ifstream readu;
        readu.open("user.txt");

        cout << "\t\t\t\t\tPlease enter the information: " << endl;

        cout << "\t\t\t\t\tUser: ";
        cin >> u;
        cout << "\t\t\t\t\tPassword: ";
        cin >> p;

        string temp;
        readp >> temp;

        if (count > 3)
        {

            cout << "\t\t\t\t\tPassword Hint: " << temp[0] << temp[temp.length() - 1]
                 << endl;
        }
        count++;
        if (p != temp)
            return false;
        readu >> temp;
        return !(u != temp);
    }

    int mainMenu()
    {
        cout << "\t\t\t\t\t\t1. Book a show" << endl;
        cout << "\t\t\t\t\t\t2. View Prices" << endl;
        int choice;
        cin >> choice;
        return choice;
    }
    void mark(const int a, const int b) { box[a][b] = '@'; }
    mainClass()
    {
        system("clear");
        memset(box, '#', sizeof(box));
    }

private:
    string timeAndDate()
    {
        auto end = std::chrono::system_clock::now();
        std::time_t end_time = std::chrono::system_clock::to_time_t(end);
        return std::ctime(&end_time); // Mon Oct  2 00:59:08 2017
    }

public:
    string currentWeek(const string &str)
    {
        stringstream ss(str);
        string temp;
        ss >> temp;
        ss.clear();
        return temp;
    }

    string currentMonth(const string &str)
    {
        stringstream ss(str);
        string temp;
        ss >> temp >> temp;
        ss.clear();
        return temp;
    }
    string currentDate(const string &str)
    {
        stringstream ss(str);
        string temp;
        ss >> temp >> temp >> temp;
        ss.clear();
        return temp;
    }
    string currentTime(const string &str)
    {
        stringstream ss(str);
        string temp;
        ss >> temp >> temp >> temp >> temp;
        return temp;
    }
    string currentYear(const string &str)
    {
        stringstream ss(str);
        string temp;
        ss >> temp >> temp >> temp >> temp >> temp;
        return temp;
    }
};

class paymentPage : public mainClass
{
    string name{""}, email{""}, password{""};
    string phoneNumber{""}, cardNumber{""};

public:
    void getName(string &x) { name = x; }
    void getEmail(string &x) { email = x; }
    void getPhone(string &x) { phoneNumber = x; }
    void getPass(string &x) { password = x; }
    int totalCharges(int g, int s, int p) { return g * 250 + p * 300 + s * 200; }
    //  void finalPage(int cost) {}
    bool checkAll()
    {
        bool c{false};
        for (char i : email)
        {
            if (i == '@')
                c = true;
        }
        if (!c)
        {
            cout << "\t\t\t Please enter valid email address!----> |NO '@' FOUND|"
                 << endl;
            std::cin.ignore(1024, '\n');
            std::cout << "\t\t\tPress enter to continue..." << endl;
            std::cin.get();
            return false;
        }
        if (email.substr(email.length() - 4, email.length() - 1) != ".com" &&
            email.substr(email.length() - 3, email.length() - 1) != ".in")
        {
            cout << "\t\t\t Please enter valid email address!----> |EXTENSION SHOULD "
                    "BE .COM OR .IN|"
                 << endl;
            std::cin.ignore(1024, '\n');
            std::cout << "\t\t\tPress enter to continue..." << endl;
            std::cin.get();
            return false;
        }

        if (password.length() <= 6)
        {
            cout << "\t\t\tPassword should be greater than 6 characters" << endl;
            std::cin.ignore(1024, '\n');
            std::cout << "\t\t\tPress enter to continue..." << endl;
            std::cin.get();
            return false;
        }
        bool capital{false}, small{false}, special{false}, number{false};
        for (char i : password)
        {
            if (i >= 97)
                small = true;
            else if (i >= 65 && i <= 91)
                capital = true;
            else if (i >= 48 && i <= 57)
                number = true;
            else
                special = true;
        }
        if (!small)
            cout << "\t\t\tPassword should contain atleast one small letter." << endl;
        if (!capital)
            cout << "\t\t\tPassword should contain atleast one capital letter."
                 << endl;
        if (!number)
            cout << "\t\t\tPassword should contain atleast one number." << endl;
        if (!special)
        {
            cout << "\t\t\tPassword should contain atleast one special symbol (eg. "
                    "@,#,$) ."
                 << endl;
        }
        if ((!small || !capital) || (!number || !special))
        {
            std::cin.ignore(1024, '\n');
            std::cout << "\t\t\tPress enter to continue..." << endl;
            std::cin.get();
            return false;
        }
        return true;
    }
};

int main()
{
    mainClass t1;

    t1.header();
    while (!t1.auth())
        t1.auth();
    t1.header();
    cout << "\t\t\t\t\tSucessfully logged in" << endl;
    std::cin.ignore(1024, '\n');
    std::cout << "Press enter to continue...";
    std::cin.get();
main:
    t1.header();
    auto choice = t1.mainMenu();
    if (choice == 1)
    {
    again:
        t1.header();
        int r, c;
        static int sCount, pCount, gCount;
        cout << "\t\t\t\t\t Movie Ticket Counter" << endl;
        t1.printBox();
        cout << "\t\t\tEnter the row :";
        cin >> r;
        cout << "\t\t\tEnter the column :";
        cin >> c;

        if (t1.checkIfMarked(r, c))
        {
            t1.mark(r, c);
            if (r <= 4)
                gCount++;
            else if (r <= 7)
                pCount++;
            else
                sCount++;
        }
        else
        {
            cout << "\n--------------------------------------------------------------"
                    "----"
                    "-------------------------------"
                 << endl;
            cout << "\n\t\t\tThe seat is already booked! " << endl;
            std::cin.ignore(1024, '\n');
            std::cout << "\t\t\tPress enter to choose again.";
            cout << "\n--------------------------------------------------------------"
                    "----"
                    "-------------------------------"
                 << endl;
            std::cin.get();

            goto again;
        }
    totalCharges:
        t1.header();
        t1.printBox();
        string temp;
        cout << "\t\t\tDo you want to order more? ";
        cin >> temp;
        if (temp == "yes")
            goto again;

        paymentPage payment;
        payment.header();
        if (gCount != 0)
            cout << "\t\t\tYou are trying to book " << gCount
                 << " gold seat/s : " << gCount << " X 250 = " << 250 * gCount
                 << endl;
        if (sCount != 0)
            cout << "\t\t\tYou are trying to book " << sCount
                 << " gold seat/s : " << sCount << " X 250 = " << 200 * sCount
                 << endl;
        if (pCount != 0)
            cout << "\t\t\tYou are trying to book " << pCount
                 << " gold seat/s : " << pCount << " X 250 = " << 350 * pCount
                 << endl;

        cout << "\t\t\tYour total charges are "
             << payment.totalCharges(gCount, sCount, pCount) << endl;
        cout << "------------------------------------------------------------------"
                "-------------------------------"
             << endl;
        temp = "-1";
        do
        {
            cout << "\t\t\tDo you want to proceed further (yes/no): ";
            cin >> temp;
        } while (temp != "yes" && temp != "no");
        if (temp == "no")
            goto totalCharges;
        do
        {
            payment.header();
            cout << "\t\t\tYour total cost is "
                 << payment.totalCharges(gCount, sCount, pCount) << " Rs." << endl;
            cout << "----------------------------------------------------------------"
                    "--"
                    "-------------------------------"
                 << endl;
            cout << "\t\t\tPlease enter below details to confirm your ticket."
                 << endl;
            cout << "----------------------------------------------------------------"
                    "--"
                    "-------------------------------"
                 << endl;

            cout << "\t\t\tEnter your name: ";
            cin >> temp;
            payment.getName(temp);
            cout << "\t\t\tEnter your Email: ";
            cin >> temp;
            payment.getEmail(temp);
            cout << "\t\t\tEnter your Phone Number: ";
            cin >> temp;
            payment.getPhone(temp);
            cout << "\t\t\tSet your Password: ";
            cin >> temp;
            payment.getPass(temp);
        } while (!payment.checkAll());

        payment.header();
        cout << "\t\t\tEnter your card number: ";
        cin >> temp;
        cout << "\t\t\tEnter your pin";
        cin >> temp;
        payment.header();
        cout << "\t\t\tTicket Confirmed: Your transaction id is 2939" << endl;
        cout << "\t\tThanks for booking ticket with us" << endl;
        cout << "----------------------------------------------------------------"
                "--"
                "-------------------------------"
             << endl;
    }
    else if (choice == 2)
    {
        t1.header();
        cout << "\t\t\t\tPrices" << endl;
        cout << "----------------------------------------------------------------"
                "--"
                "-------------------------------"
             << endl;
        cout << "\t\t1. Gold         =                250Rs per person    " << endl;
        cout << "\t\t2. Silver       =                200Rs per person  " << endl;
        cout << "\t\t3. Platinum     =                250Rs per person" << endl;
        cout << "----------------------------------------------------------------"
                "--"
                "-------------------------------"
             << endl;
        std::cin.ignore(1024, '\n');
        std::cout << "\t\t\tPress enter to go to main menu." << endl;
        cin.get();
        goto main;
    }
}