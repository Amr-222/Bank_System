#pragma once
#include <fstream>
#include "clsString.h"
#include "clsDate.h"
#include "clsUser.h"
#include "clsScreen.h"
#include <iomanip>


using namespace std;

class clsLoginRegisterScreen:protected clsScreen {

private:


    struct stLoginInfo {
        string DateTime, UserName, Pass;
        short permissions;
    };




    static string _ConvertLoginObjectToLine(clsUser User, string Seperator = "#//#")
    {

        string stRecord = "";
        stRecord += clsDate::GetDateTimeStringNow() + Seperator;
        stRecord += User.UserName + Seperator;
        stRecord += clsUtil::EncryptText(User.Password, 10) + Seperator;
        stRecord += to_string(User.Permissions);

        return stRecord;

    }


    static stLoginInfo _ConvertLinetoLoginObject(string line,string separator="#//#") {
        
        vector <string> v = clsString::Split(line, separator);

        
        stLoginInfo s;
       s.DateTime = v[0];
        s.UserName = v[1];
        s.Pass = clsUtil::DecryptText(v[2], 10);
        s.permissions = stoi(v[3]);

        return s;

    }



public:

    static void Register(clsUser User) {


        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::app);

        string DataLine;

        if (MyFile.is_open())
        {
            DataLine = _ConvertLoginObjectToLine(User);
            MyFile << DataLine << endl;
      
            MyFile.close();

        }

    }

  
    static void PrintObjectLoginInfo(stLoginInfo &s) {

        cout << setw(8) << left << "" << "| " << setw(35) << left << s.DateTime;
        cout << "| " << setw(25) << left << s.UserName;
        cout << "| " << setw(12) << left << s.Pass;
        cout << "| " << setw(20) << left << s.permissions;
    }



    static vector <stLoginInfo> GetLoginDataFromFile() {


        fstream MyFile;
        MyFile.open("LoginRegister.txt", ios::in);//read Mode

        vector <stLoginInfo> vLoginInfo;

        if (MyFile.is_open())
        {
            string Line;

            while (getline(MyFile, Line))
            {

                vLoginInfo.push_back(_ConvertLinetoLoginObject(Line));

            }

            MyFile.close();

        }

        return vLoginInfo;
    }

    static  void ShowLoginRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pLoginRegisters))
        {
            return;// this will exit the function and it will not continue
        }

        vector <stLoginInfo> vLogin = GetLoginDataFromFile();

        string Title = "\t  Login Register Screen";
        string SubTitle = "\t    (" + to_string(vLogin.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(35) << "Date/Time";
        cout << "| " << left << setw(25) << "User Name";
        cout << "| " << left << setw(12) << "Password";
        cout << "| " << left << setw(20) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        if (vLogin.size() == 0)
            cout << "\t\t\t\tNo Users Available In the System!";
        else {

            for (stLoginInfo& s : vLogin)
            {

                PrintObjectLoginInfo(s);
                cout << endl;
            }
        
        }
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;






    }


};