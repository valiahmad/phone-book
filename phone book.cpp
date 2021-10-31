// phone book.cpp
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <conio.h>
#include <vector>
using namespace std;
#define _name 1
#define _lastname 2
#define _address 3
#define _email 4
#define _phone_num 1
#define _mobile_num 2
#define size 100
int i_t;
/////////////////////////////class of member
class member {
	vector<char> name, lastname, address, email;
	vector<int>phone_num, mobile_num;
public:
	vector<char> re_name(int key) {

		switch (key) {
		case 1:return name; break;
		case 2:return lastname; break;
		case 3:return address; break;
		case 4:return email; break;
		default:
			break;
		}
	}
	vector<int> re_num(int key) {
		switch (key) {
		case 1:return phone_num; break;
		case 2:return mobile_num; break;
		default:
			break;
		}
	}
	void put_name(vector<char>new_name, int key) {
		switch (key)
		{
		case 1:name = new_name; break;
		case 2:lastname = new_name; break;
		case 3:address = new_name; break;
		case 4:email = new_name; break;
		default:
			break;
		}
	}
	void put_num(vector<int>new_num, int key) {
		switch (key)
		{
		case 1:phone_num = new_num; break;
		case 2:mobile_num = new_num; break;
		default:
			break;
		}
	}
	void clear(int key) {
		if (key >= 1 && key <= 6) {
			switch (key)
			{
			case 1:name.clear(); break;
			case 2:lastname.clear(); break;
			case 3:address.clear(); break;
			case 4:email.clear(); break;
			case 5:phone_num.clear(); break;
			case 6:mobile_num.clear(); break;
			default:
				break;
			}
		}
		else if (key == 7) {
			name.clear();
			lastname.clear();
			address.clear();
			email.clear();
			phone_num.clear();
			mobile_num.clear();
		}
	}
	bool empty() {
		if (name.empty() || lastname.empty() || address.empty() || email.empty() ||
			phone_num.empty() || mobile_num.empty())
			return false;
		else return true;
	}
};
class phonebook {
	member person[size];
	vector<char> name, lastname, address, email;
	vector<int>phone_num, mobile_num;
public:
	void add_member(int key, int i, int option) {
		int id;
		static int last = 0;
		if (key == 0)id = last;
		else if (key != 0)id = i;
		if (option == _name || key == 0 || option == 7) {
			//getting name
			cout << "\n\tEnter The Name : ";
			while (true) {
				name.push_back(_getche());
				if (name.back() == '\r')break;
			}
			person[id].put_name(name, _name);
		}
		if (option == _lastname || key == 0 || option == 7) {
			//getting lastname
			cout << "\n\tEnter The Lastname : ";
			while (true) {
				lastname.push_back(_getche());
				if (lastname.back() == '\r')break;
			}
			person[id].put_name(lastname, _lastname);
		}
		if (option == _address || key == 0 || option == 7) {
			//getting address
			cout << "\n\tEnter The Address : ";
			while (true) {
				address.push_back(_getche());
				if (address.back() == '\r')break;
			}
			person[id].put_name(address, _address);
		}
		if (option == _email || key == 0 || option == 7) {
			//getting email
			cout << "\n\tEnter The Email : ";
			while (true) {
				email.push_back(_getche());
				if (email.back() == '\r')break;
			}
			person[id].put_name(email, _email);
		}
		if (option == 5 || key == 0 || option == 7) {
			//getting phone number
			cout << "\n\tEnter The Phone Number : ";
			while (true) {
				phone_num.push_back(_getche());
				if (phone_num.back() == '\r')break;
			}
			person[id].put_num(phone_num, _phone_num);
		}
		if (option == 6 || key == 0 || option == 7) {
			//getting moblie number
			cout << "\n\tEnter The Mobile Number : ";
			while (true) {
				mobile_num.push_back(_getche());
				if (mobile_num.back() == '\r')break;
			}
			person[id].put_num(mobile_num, _mobile_num);
		}
		if (key == 0) {
			last++;
			i_t = last;
		}
		name.clear();
		lastname.clear();
		address.clear();
		email.clear();
		phone_num.clear();
		mobile_num.clear();
	}
	int main_search() {
		int option, key, id;
		cout << "\nSearch According To \n#1 Name Or Lastname Or Address Or Email\n#2 Phone Number Or Mobile Number\n";
		cin >> option;
		if (option == 1) {
			vector<char>temp;
			cout << "\nSearch By : #1 Name  #2 Lastname  #3 Address #4 Email\n";
			cin >> key;
			cout << "\nEnter The Statement : ";
			while (true) {
				temp.push_back(_getche());
				if (temp.back() == '\r')break;
			}
			id = search_name(temp, key);
			temp.clear();
		}
		else if (option == 2) {
			vector<int>temp;
			cout << "\nSearch By : #1 Phone Number  #2 Mobile Number\n";
			cin >> key;
			cout << "\nEnter The Number : ";
			while (true) {
				temp.push_back(_getche());
				if (temp.back() == '\r')break;
			}
			id = search_num(temp, key);
			temp.clear();
		}
		return id;
	}
	int search_name(vector<char>Name, int key) {
		int i;
		switch (key) {
		case 1:
			for (i = 0; i < i_t; i++) {
				if (Name == person[i].re_name(_name))return i;
			}
			break;
		case 2:
			for (i = 0; i < i_t; i++) {
				if (Name == person[i].re_name(_lastname))return i;
			}
			break;
		case 3:
			for (i = 0; i < i_t; i++) {
				if (Name == person[i].re_name(_address))return i;
			}
			break;
		case 4:
			for (i = 0; i < i_t; i++) {
				if (Name == person[i].re_name(_email))return i;
			}
			break;
		}
		cout << "\n***NOT FOUND***";
		return -1;
	}
	int search_num(vector<int>Num, int key) {
		int i;
		switch (key) {
		case 1:
			for (i = 0; i < i_t; i++) {
				if (Num == person[i].re_num(_phone_num))return i;
			}
			break;
		case 2:
			for (i = 0; i < i_t; i++) {
				if (Num == person[i].re_num(_mobile_num))return i;
			}
			break;
		}
		cout << "\n***NOT FOUND***";
		return -1;
	}
	void edit_member() {
		int i, option;
		i = main_search();
		cout << "\nWhich Part Do You Want To Edit\n#1 Name\n#2 Lastname\n#3 Address\n#4 Email";
		cout << "\n#5 Phone Number\n#6 Mobile Number\n#7 All\n";
		cin >> option;
		person[i].clear(option);
		add_member(1, i, option);
	}
	void show_member(int key, int pos) {
		int i, j;
		for (i = 0; i < i_t; i++) {
			if (!key)i = pos;
			if (!person[i].empty())continue;
			name = person[i].re_name(_name);
			cout << "\n\tName : ";
			for (j = 0; name[j] != '\r'; j++) {
				cout << (char)name[j];
			}
			lastname = person[i].re_name(_lastname);
			cout << "\n\tLastname : ";
			for (j = 0; lastname[j] != '\r'; j++) {
				cout << (char)lastname[j];
			}
			address = person[i].re_name(_address);
			cout << "\n\tAddress : ";
			for (j = 0; address[j] != '\r'; j++) {
				cout << (char)address[j];
			}
			email = person[i].re_name(_email);
			cout << "\n\tEmail : ";
			for (j = 0; email[j] != '\r'; j++) {
				cout << (char)email[j];
			}
			phone_num = person[i].re_num(_phone_num);
			cout << "\n\tPhone Number : ";
			for (j = 0; phone_num[j] != '\r'; j++) {
				cout << (char)phone_num[j];
			}
			mobile_num = person[i].re_num(_mobile_num);
			cout << "\n\tMobile Number : ";
			for (j = 0; mobile_num[j] != '\r'; j++) {
				cout << (char)mobile_num[j];
			}
			name.clear();
			lastname.clear();
			address.clear();
			email.clear();
			phone_num.clear();
			mobile_num.clear();
			if (!key)break;
		}
	}
	void save_member() {
		int i, j;
		ofstream outputfile("D:\\file.txt", ios::out);
		if (!outputfile) {
			cout << "\nFile Not Found!";
			return;
		}
		for (i = 0; i < i_t; i++) {
			name = person[i].re_name(_name);
			for (j = 0; name[j] != '\r'; j++) {
				outputfile << name[j];
			}
			outputfile << " ";
			lastname = person[i].re_name(_lastname);
			for (j = 0; lastname[j] != '\r'; j++) {
				outputfile << lastname[j];
			}
			outputfile << " ";
			address = person[i].re_name(_address);
			for (j = 0; address[j] != '\r'; j++) {
				outputfile << address[j];
			}
			outputfile << " ";
			email = person[i].re_name(_email);
			for (j = 0; email[j] != '\r'; j++) {
				outputfile << email[j];
			}
			outputfile << " ";
			phone_num = person[i].re_num(_phone_num);
			for (j = 0; phone_num[j] != '\r'; j++) {
				outputfile << (char)phone_num[j];
			}
			outputfile << " ";
			mobile_num = person[i].re_num(_mobile_num);
			for (j = 0; mobile_num[j] != '\r'; j++) {
				outputfile << (char)mobile_num[j];
			}
			outputfile << endl;
			name.clear();
			lastname.clear();
			address.clear();
			email.clear();
			phone_num.clear();
			mobile_num.clear();
		}
		cout << "\n***Saved***";
	}
	void delete_member(int id) {
		person[id].clear(7);
		cout << "\n***Deleted***";
	}
	int menu() {
		int option;
		cout << "#1 Add Member";
		cout << "\n#2 Search Member";
		cout << "\n#3 Edit Member";
		cout << "\n#4 Print Member";
		cout << "\n#5 Save";
		cout << "\n#6 Delete Member";
		cout << "\n#7 Exit\n";
		cin >> option;
		return option;
	}
	void main_menu() {
		int i;
	loop:
		system("cls");
		switch (menu())
		{
		case 1:add_member(0, -1, -1); break;
		case 2: i = main_search(); if (i == -1)break; show_member(0, i); break;
		case 3:edit_member(); break;
		case 4:show_member(1, -1); break;
		case 5:save_member(); break;
		case 6:i = main_search(); delete_member(i);
		case 7:exit(0); break;
		default:
			break;
		}
		cout << "\nPress Any Key To Continue";
		_getch();
		goto loop;
	}
};
/////////////////////////////////////////////////////////////////////
int main()
{
	phonebook book;
	book.main_menu();
	return 0;
}