#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include <iomanip>
#include "clsMainScreen.h"
#include "Global.h"
#include "clsLoginRegisterScreen.h"

class clsLoginScreen :protected clsScreen
{

private:

    static  bool _Login()
    {
        bool LoginFaild = false;
        short Trials = 2;
        string Username, Password;
        do
        {

            if (LoginFaild)
            {
                cout << "\nInvlaid Username/Password!";
                cout << "\nYou have "<<Trials<<" Trials to login.\n\n";
                Trials--;
            }

            cout << "Enter Username? ";
            cin >> Username;

            cout << "Enter Password? ";
            cin >> Password;

            CurrentUser = clsUser::Find(Username, Password);

            LoginFaild = CurrentUser.IsEmpty();

        } while (LoginFaild && Trials != 0);

        if (Trials == 0&&LoginFaild)
        {
            cout << "\n\nYou are locked after 3 faild trials :-(\n\n";
            return false;
        }
        else {
            clsLoginRegisterScreen::Register(CurrentUser);
            clsMainScreen::ShowMainMenue();
            return true;
        }
    }

public:


    static bool ShowLoginScreen()
    {
        system("cls");
        _DrawScreenHeader("\t  Login Screen");
       return _Login();

    }

};

