#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

// Global Variables
string FirstName, LastName, PhoneNum;
string Username, Password;
bool LoggedIn = false;

void SignUp();
void Login();
void AddContact();
void DeleteContact();
void ListContacts();
void SearchContact();
void EditContact();
bool check_digits(string);
bool check_numbers(string);
void Theme();

void Theme()
{
    system("cls");
    int theme;
    cout << "\n\n\t\t 1 -> Light Mode";
    cout << "\n\n\t\t 2 -> Dark Mode\n\n\n\t\t-->";
    cin >> theme;
    switch (theme)
    {
    case 1:
        system("color 70");
        break;
    case 2:
        system("color 0B");
        break;
    default:
        cout << "\n\tInvalid Input! Defaulting to Dark Mode.";
        system("color 0B");
    }
    system("cls");
}

void SignUp()
{
    system("cls");
    cout << "\n\n\n\t\t\t  SignUp" << endl;
    cout << "\nEnter a New Username\n--> ";
    cin >> Username;
    cout << "\nEnter a Password\n--> ";
    cin >> Password;

    ofstream UserFile("users.txt", ios::app);
    if (UserFile.is_open())
    {
        UserFile << Username << " " << Password << endl;
        cout << "\n---Account Created Successfully---" << endl;
        UserFile.close();
    }
    else
    {
        cout << "\n!!! Account Creation Failed !!!" << endl;
    }
    system("pause");
    system("cls");
}

void Login()
{
    system("cls");
    cout << "\n\n\n\t\t\t  LOGIN" << endl;
    cout << "\nEnter Username: ";
    cin >> Username;
    cout << "Enter Password: ";
    cin >> Password;

    ifstream UserFile("users.txt");
    bool loginSuccess = false;

    if (UserFile.is_open())
    {
        string storedUsername, storedPassword;
        while (UserFile >> storedUsername >> storedPassword)
        {
            if (storedUsername == Username && storedPassword == Password)
            {
                LoggedIn = true;
                loginSuccess = true;
                cout << "\n---Logged In Successfully---" << endl;
                break;
            }
        }
        UserFile.close();

        if (!loginSuccess)
        {
            cout << "\n!!! Invalid Username or Password !!!" << endl;
        }
    }
    else
    {
        cout << "\n!!! Unable to open users file !!!" << endl;
    }
    system("pause");
    system("cls");
}

void SearchContact()
{
    system("cls");
    bool found = false;
    ifstream ContactFile("information.txt");
    string keyword;
    cout << "\n\tEnter Name to search : ";
    cin >> keyword;
    while (ContactFile >> FirstName >> LastName >> PhoneNum)
    {
        if (keyword == FirstName || keyword == LastName)
        {
            cout << "\n\n\n\t\tCONTACT DETAILS";
            cout << "\n\nFirst Name : " << FirstName;
            cout << "\nLast Name : " << LastName;
            cout << "\nPhone Number : " << PhoneNum;
            found = true;
        }
    }
    if (!found)
    {
        cout << "\nNo such contact is found!";
    }

    cout << endl
         << endl;
    system("pause");
    system("cls");
}

void ListContacts()
{
    system("cls");
    ifstream ContactFile("information.txt");
    if (ContactFile.is_open())
    {
        cout << "\n\n\t\t\tCONTACT LIST\n\n";
        cout << "-------------------------------------------\n";
        cout << "    First Name  Last Name : Phone Number   \n";
        cout << "-------------------------------------------\n";

        while (ContactFile >> FirstName >> LastName >> PhoneNum)
        {
            cout << "    " << FirstName << "  " << LastName << " : " << PhoneNum << endl;
        }
        ContactFile.close();
    }
    else
    {
        cout << "\n\tError opening file!";
    }
    cout << endl
         << endl;
    system("pause");
    system("cls");
}

void AddContact()
{
    system("cls");
    ofstream phone("information.txt", ios::app);
    cout << "\n\n\tEnter First Name : ";
    cin >> FirstName;
    cout << "\n\tEnter Last Name : ";
    cin >> LastName;
    cout << "\n\tEnter Phone Number : ";
    cin >> PhoneNum;

    if (check_digits(PhoneNum))
    {
        if (check_numbers(PhoneNum))
        {
            if (phone.is_open())
            {
                phone << FirstName << " " << LastName << " "
                      << PhoneNum << endl;
                cout << "\n\tContact saved successfully !";
            }
            else
            {
                cout << "\n\tError in opening record!";
            }
        }
        else
        {
            cout << "\n\tOnly numbers are allowed!";
        }
    }
    else
    {
        cout << "\n\tPhone Number Should Consist of Digits Only";
    }
    cout << endl
         << endl;
    system("pause");
    system("cls");
    phone.close();
}

bool check_digits(string x)
{
    return x.length() > 0;
}

bool check_numbers(string x)
{
    bool check = true;

    for (int i = 0; i < x.length(); i++)
    {
        if (!(int(x[i]) >= 48 && int(x[i]) <= 57))
        {
            check = false;
            break;
        }
    }

    return check;
}

void DeleteContact()
{
    system("cls");
    ifstream ContactFile("information.txt");
    ofstream temp("temp.txt");
    bool found = false;
    string keywordFirst, keywordLast;

    cout << "\n\tEnter the First Name of the Contact: ";
    cin >> keywordFirst;
    cout << "\tEnter the Last Name of the Contact: ";
    cin >> keywordLast;

    while (ContactFile >> FirstName >> LastName >> PhoneNum)
    {
        if (!(keywordFirst == FirstName && keywordLast == LastName))
        {
            temp << FirstName << " " << LastName << " " << PhoneNum << endl;
        }
        else
        {
            found = true;
        }
    }

    ContactFile.close();
    temp.close();

    if (found)
    {
        remove("information.txt");
        rename("temp.txt", "information.txt");
        cout << "\n\tContact deleted successfully!" << endl;
    }
    else
    {
        remove("temp.txt");
        cout << "\n\tNo such contact found!" << endl;
    }
    system("pause");
}

void EditContact()
{
    system("cls");
    bool found = false;
    string SearchFirstName, SearchLastName;

    cout << "\n\tEnter the First Name of the contact to edit: ";
    cin >> SearchFirstName;
    cout << "\tEnter the Last Name of the contact to edit: ";
    cin >> SearchLastName;

    ifstream ContactFile("information.txt");
    ofstream temp("temp.txt");

    if (ContactFile.is_open() && temp.is_open())
    {
        while (ContactFile >> FirstName >> LastName >> PhoneNum)
        {
            if (FirstName == SearchFirstName && LastName == SearchLastName)
            {
                found = true;
                cout << "\n\tEnter new First Name: ";
                cin >> FirstName;
                cout << "\tEnter new Last Name: ";
                cin >> LastName;
                cout << "\tEnter new Phone Number: ";
                cin >> PhoneNum;
                if (!check_digits(PhoneNum) || !check_numbers(PhoneNum))
                {
                    cout << "\n\tInvalid phone number format. Edit aborted.";
                    temp << SearchFirstName << " " << SearchLastName << " " << PhoneNum << endl;
                }
                else
                {
                    temp << FirstName << " " << LastName << " " << PhoneNum << endl;
                    cout << "\n\tContact edited successfully!";
                }
            }
            else
            {
                temp << FirstName << " " << LastName << " " << PhoneNum << endl;
            }
        }

        ContactFile.close();
        temp.close();

        if (!found)
        {
            cout << "\n\tNo such contact found!";
            remove("temp.txt");
        }
        else
        {
            remove("information.txt");
            rename("temp.txt", "information.txt");
        }
    }
    else
    {
        cout << "\n\tError opening file!";
    }
    system("pause");
    system("cls");
}

int main()
{
start:
    system("cls");
    int log;
    cout << "\n\n\n\t\t\t   LOGIN / SIGNUP";
    cout << "\n\n\n\t 1)  Login";
    cout << "\t\t\t\t 2)  SignUp";
    cout << "\n\n\t 3)  Change Theme";
    cout << "\n\n\t 0)  Exit\n\n\t--> ";
    cin >> log;

    switch (log)
    {
    case 1:
        Login();
        break;
    case 2:
        SignUp();
        Login();
        break;
    case 0:
        exit(0);
        break;
    case 3:
        Theme();
        goto start;
    default:
        cout << "\n\n\tInvalid Input!" << endl
             << endl;
        system("pause");
        system("cls");
    }

    if (LoggedIn)
    {
        int choice;
        system("cls");
        while (1)
        {
            cout << "\n\n\n\t\t\t\t\t\tCONTACT SAVER";
            cout << "\n\n\t\t 1. Search Contact \t\t\t\t\t 2. Add Contact";
            cout << "\n\n\t\t 3. Remove Contact \t\t\t\t\t 4. Edit Contact";
            cout << "\n\n\t\t 5. Contact List";
            cout << "\n\n\t\t 6. Change Theme";
            cout << "\n\n\t\t 0. Exit \n\n\n\t\t--> ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                SearchContact();
                break;
            case 2:
                AddContact();
                break;
            case 3:
                DeleteContact();
                break;
            case 4:
                EditContact();
                break;
            case 5:
                ListContacts();
                break;
            case 6:
                Theme();
                break;
            case 0:
                exit(0);
                break;
            default:
                cout << "\n\tInvalid Input!\n"
                     << endl;
                system("pause");
                system("cls");
            }
        }
    }
    else
    {
        goto start;
    }
}
