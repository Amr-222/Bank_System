#pragma once
#include <iostream>
#include <string>
#include "clsDate.h"

using namespace std;

class clsInputValidate
{
private:

	
	static bool is_digit(string snum) {

		for (int i = 0; i < snum.length(); i++) {

			if (!isdigit(snum[i]) && snum[i] != '.') {
				return false;
			}

		}

		return true;
	}
	static bool IsPostiveNum(double num) {
		return num >= 0 ? true : false;
	}
	static string Num_As_String(string textnum, string error_message, bool postiveonly = false) {


		if (postiveonly) {
			while (!is_digit(textnum)) {


				cout << error_message;
				getline(cin >> ws, textnum);
			}
			while (!IsPostiveNum(stod(textnum))) {
				cout << error_message;
				getline(cin >> ws, textnum);
				Num_As_String(textnum, error_message, 1);
			}
		}
		else {
			while (!is_digit(textnum)) {
				cout << error_message;
				getline(cin >> ws, textnum);
			}
		}
		return textnum;
	}
	static string ReadString(string input_message) {
		string str;
		cout << input_message;
		getline(cin >> ws, str);
		return str;
	}

	

public :

	static bool IsNumberBetween(double num, double from, double to) {
		return (num >= from && num <= to);
	}
	static bool IsNumberBetween(int num, int from, int to) {
		return (num >= from && num <= to);
	}

	static int ReadIntNumber(string input_message = "", string error_message = "\nInvalid Num! , Enter again: ") {

		string str=ReadString(input_message);
		str = Num_As_String(str, error_message);
		return stoi(str);
	}



	static int ReadIntNumberBetween(double from, double to, string input_message = "", string error_message = "\nInvalid Num! , Enter again: ") {

		string str = ReadString(input_message);
		str = Num_As_String(str, error_message);
		
		while (!IsNumberBetween(stod(str), from, to)) {
			str = ReadString(error_message);
			str = Num_As_String(str, error_message);
		}

		return stoi(str);
	}





	static int ReadDblNumberBetween(double from, double to, string input_message = "", string error_message = "\nInvalid Num! , Enter again: ") {

		string str = ReadString(input_message);
		str = Num_As_String(str, error_message);

		while (!IsNumberBetween(stod(str), from, to)) {
			str = ReadString(error_message);
			str = Num_As_String(str, error_message);
		}

		return stod(str);
	}

	static double ReadDblNumber(string input_message = "", string error_message = "\nInvalid Num! , Enter again: ") {

		string str = ReadString(input_message);

		str = Num_As_String(str, error_message);

		return stod(str);
	}


	static double ReadPostiveNumber(string input_message = "", string error_message = "\nInvalid Num! , Enter again: ") {
		
		string str = ReadString(input_message);

		str = Num_As_String(str, error_message, 1);

		return stod(str);
	}






	static bool IsDateBetween(clsDate currentDate, clsDate Date1, clsDate Date2) {


		if ((clsDate::IsDate1BeforeDate2(currentDate, Date1) && !clsDate::IsDate1BeforeDate2(currentDate, Date2))
			|| (clsDate::IsDate1BeforeDate2(currentDate, Date2) && !clsDate::IsDate1BeforeDate2(currentDate, Date1))) {
			return true;
		}
		else
			return false;

	}

	static bool IsValidDate(clsDate date) {
		return	clsDate::IsValidDate(date);
	}

	static string ReadString()
	{
		string  S1 = "";
		// Usage of std::ws will extract allthe whitespace character
		getline(cin >> ws, S1);
		return S1;
	}

	


};

