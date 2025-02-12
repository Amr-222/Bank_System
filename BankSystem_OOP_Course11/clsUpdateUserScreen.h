#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsAddNewUserScreen .h"

class clsUpdateUserScreen :protected clsScreen

{
private:


    static void _ReadUserInfo(clsUser& User)
    {

        char Answer;

        cout << "\nDo you want to update FirstName? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nEnter FirstName: ";
            User.FirstName = clsInputValidate::ReadString();

        }

        cout << "\nDo you want to update LastName? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nEnter LastName: ";
            User.LastName = clsInputValidate::ReadString();

        }

        cout << "\nDo you want to update Email? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nEnter Email: ";
            User.Email = clsInputValidate::ReadString();

        }
      
        cout << "\nDo you want to update Phone? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nEnter Phone: ";
            User.Phone = clsInputValidate::ReadString();

        }

        cout << "\nDo you want to update Password? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {
            cout << "\nEnter Password: ";
            User.Password = clsInputValidate::ReadString();
        
        }


        cout << "\nDo you want to update Permission? y/n? ";
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\nEnter Permission: ";
            User.Permissions = clsAddNewUserScreen::ReadPermissionsToSet();
        
        }

     

    }

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUser Name   : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }


public:

    static void ShowUpdateUserScreen()
    {

        _DrawScreenHeader("\tUpdate User Screen");

        string UserName = "";

        cout << "\nPlease Enter User UserName: ";
        UserName = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount number is not found, choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser User1 = clsUser::Find(UserName);

        _PrintUser(User1);

        cout << "\nAre you sure you want to update this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {

            cout << "\n\nUpdate User Info:";
            cout << "\n____________________\n";


            _ReadUserInfo(User1);

            clsUser::enSaveResults SaveResult;

            SaveResult = User1.Save();

            switch (SaveResult)
            {
            case  clsUser::enSaveResults::svSucceeded:
            {
                cout << "\nUser Updated Successfully :-)\n";

                _PrintUser(User1);
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject:
            {
                cout << "\nError User was not saved because it's Empty";
                break;

            }

            }

        }

    }
};

