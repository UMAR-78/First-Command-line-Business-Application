system("CLS");
    bool flag = false;
    header();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    gotoxy(9, 3);
    cout << "Enter your option here(1/2/3/4)" << endl;
    gotoxy(9, 4);
    cout << "1-Admin" << endl;
    gotoxy(9, 5);
    cout << "2-Employ" << endl;
    gotoxy(9, 6);
    cout << "3-Costumer" << endl;
    gotoxy(9, 7);
    cout << "4-Exit";
    do
    {
        gotoxy(9, 9);
        cin >> option;
        if (option < 1 || option > 4)
        {
            gotoxy(9, 8);
            cout << "---------Enter valid option-----------" << endl;
        }
    } while (option > 4 || option < 1);
    return option;