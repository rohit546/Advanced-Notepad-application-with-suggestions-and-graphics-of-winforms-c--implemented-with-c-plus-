#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
#include<vector>
using namespace std;


int main() {

    string str="";
    int stri = 0;

    while (1) {
        if (_kbhit())
        {
            system("cls");
            cout << str;
            if (_getch() >= 'a' && _getch() <= 'z') {

                str += _getch();
              

            }
            if (_getch() == 13)
                break;


        }
    }



	return 0;
}