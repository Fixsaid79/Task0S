// Hello and its task0S
// maybe its not professional beacose im just junior
// but i like this project
// taskOS alpha version

#include <iostream>
#include <random>
using namespace std;

string Name = "admin"; // default: admin
string password = "adminadmin"; // default: adminadmin
int Age = 18; // default 18

class OS {
    private :
        string userAnsw;
        bool unlock = false; // default: false
    public :
    OS() {}
    //Number game
    void game() {
        random_device rd; 
        mt19937 gen(rd()); 
        uniform_int_distribution<> distr(1, 100);
        int a;
        int total;
        string answ;
        int difficulty = 1;
        bool playing = true;
        bool restart = false;
        float number;
        cout << "====================================================" << endl;
        cout << "   🎯 WELCOME TO NUMBER FINDING GAME! 🎯" << endl;
        cout << "     (There is 3 levels of difficulty)" << endl;
        cout << "====================================================" << endl;
        cout << "Choose difficulty: a = 1-500, b = 1-200, c = 1-100" << endl;
        cout << "difficulty: "; cin >> answ;        
        if(answ == "a" or answ == "A")
        {
            uniform_int_distribution<> distr(1, 500);
            a = distr(gen);
        }
        else if(answ == "b" or answ == "B")
        {
            uniform_int_distribution<> distr(1, 200);
            a = distr(gen);
        }
        else 
        {
            uniform_int_distribution<> distr(1, 100);
            a = distr(gen);
        }

        cout << "\n💡 Game is starting. Enter any number" << endl;
        cout << "👉 number: "; cin >> number;
        while(playing)
        {
            if(number != a)
            {
                total = total + 1;
                if(restart == true)
                {
                cout << "\n New number was choosed" << endl;
                restart = false;
                }
                else if(restart == false and number > a)
                {
                    cout << "❌ Choosed number is SMALLER ↓" << endl;
                }
                else if(restart == false and number < a)
                {
                    cout << "❌ Choosed number is BIGGER ↑" << endl;
                }
                cout << "👉 Rewrite: "; cin >> number;
            }
            else 
            {
                cout << "\n✨ Yo bro, You find it! ✨" << endl;
                cout << "\n🎯 Number was " << a <<endl;
                cout << "\n📊 You trys " << total <<endl;
            
                cout << "\n🔄 Do you want replay[Y/N]: "; cin >> answ;
                if(answ == "Y" or answ == "y")
                {
                    cout << "Choose difficulty: a = 1-500, b = 1-200, c = 1-100" << endl;
                    cout << "difficulty: "; cin >> answ;
                    if(answ == "a" or answ == "A")
                    {
                        uniform_int_distribution<> distr(1, 500);
                        a = distr(gen);
                    }
                    else if(answ == "b" or answ == "B")
                    {                  
                        uniform_int_distribution<> distr(1, 200);
                        a = distr(gen);
                    }
                    else 
                    {
                        uniform_int_distribution<> distr(1, 100);
                        a = distr(gen);
                    }
                    answ = "null";
                    restart = true; 
                    number = 0;
                }
                else
                {
                    playing = false;
                    cout << "\n****************************************" << endl;
                    cout << "🎮 Game Over" << endl;
                    cout << "🏆 All your: " << total << endl;
                    cout << "👋 Have a good time!" << endl;
                    cout << "****************************************" << endl;
                    desktop();
                }
            }
        }
    }

    void cp() {
        cout << "Enter your password: ";cin >> userAnsw;
        ident(userAnsw);
        cout << "Enter new password: ";cin >> password;
        cout << "Password was changed sucsessfully" << endl;
        desktop();
    }

    void starting() {
        cout << "Hello " << Name << endl;
        cout << "Welcome to task0S" << endl;
        cout << "Please enter your password: "; cin >> userAnsw;
        unlock = ident(userAnsw);
        if(unlock == true)
        {
            desktop();
        }
    }

    void np() {
        cout << "Enter your password: ";cin >> userAnsw;
        ident(userAnsw);
        cout << "Enter new name: ";cin >> Name;
        cout << "Name was changed sucsessfully" << endl;
        desktop();
    }

    void off() {
        cout << "Off (a), restart (b) =>";cin >> userAnsw;
        if(userAnsw == "a" or userAnsw == "A")
        {
            bool start = false;
            while (start == false)
            {
                cout << "Enter A to start =>";cin >> userAnsw;
                if(userAnsw == "a" or userAnsw == "A")
                {
                    start = true;
                }
            }
            starting();
        }
        else if(userAnsw == "b" or userAnsw == "B")
        {
            starting();
        }
    }

    void preferences() {
        cout << "Preferences" << endl;
        cout << "Password (a), name (b), off (c) =>";cin >> userAnsw;
        if(userAnsw == "a" or userAnsw == "A")
        {
            cout << "Change password (a)" <<endl;
            cout << "=>";cin >> userAnsw;
            if(userAnsw == "a" or userAnsw == "A")
            {
                cp();
            }
        }
        else if(userAnsw == "b" or userAnsw == "B")
        {
            cout << "Change name (a)" <<endl;
            cout << "=>";cin >> userAnsw;
            if(userAnsw == "a" or userAnsw == "A")
            {
                np();
            }
        }
        else 
        {
            off();
        }
    }

    void desktop() {
        //Your desktop
        userAnsw = "null";
        cout << "\nYou are in the desktop" << endl;
        cout << "All apps: NumberGame (a), preferences (b)" << endl;
        cout << "choose one: "; cin >> userAnsw;
        if(userAnsw == "a" or userAnsw == "A") 
        {
            game();
        }
        else if(userAnsw == "b" or userAnsw == "B")
        {
            preferences();
        }
        else if(userAnsw == "c" or userAnsw == "C")
        {
            cout << "I think you are devoloper" << endl;
            cout << "Its from alpha version" << endl;
            cout << "Im just too lazy to delete it :) " << endl;
            cout << "And all your data was deleted" << endl;
            cout << "Good luck XD" << endl;
        }
    }

    int ident(string answ) {
        while(unlock == false)
        {
            if(answ == password)
            {
                unlock = true;
            }
            else
            {
                cout << "Wrong password. Please return: "; cin >> answ;
            }
        }
        return unlock;
    }

    void main() {
        cout << "Hello " << Name << endl;
        cout << "Welcome to task0S" << endl;
        cout << "Please enter your password: "; cin >> userAnsw;
        unlock = ident(userAnsw);
        if(unlock == true)
        {
            desktop();
        }
    }
};

int main() {

    //Starting system
    cout << "[INFO]: System was loaded sucsesfully" << endl;
    cout << "[INFO]: Libarys was downloaded sucsess" << endl;
    cout << "[INPUT]: Enter your name: "; cin >> Name;
    cout << "[INPUT]: Enter your password: "; cin >> password;
    cout << "[INPUT]: Enter your Age: "; cin >> Age;
    // Age check
    if(Age <= 18)
    {
        cout << "[ERROR 101]: YOU CAN'T USE TASK0S IF YOU ARE SMALLER THAN 18!" <<endl;
        cout << "[SYSTEM]: ALL DATA WAS DESTROYED" << endl;
    }
    else 
    {
        //OS start
        OS o;
        o.main();
    }
    //End operation
    return 0;
}