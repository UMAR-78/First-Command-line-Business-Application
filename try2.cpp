//---------------------------------Libraries---------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>
#include <cmath>
using namespace std;
//---------------------------------Function prototypes-------------------------------------------------------
void gotoxy(int x, int y);
void header();
void header2();
void header3();
void subheader(string mainmenu, string submenu, string submenu2);
int Main_Menu(int option);
//---------------------------------Admin function starts----------------------------------------------------
int Admin_Menu(int option2);
void Add_Prduct(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void add_products_in_array(string n, int p, int q, string comp, string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void view_products(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count);
void check_stock(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count);
bool DEL_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
bool DEL_product_employ(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void Update_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
string sorting(string op);
void Ascending_sorting(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void Descending_sorting(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void search_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS);
void Add_Employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count);
void Add_employ_in_array(string n, string d, int s, int log, string contact, string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count);
void view_record_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count);
bool Del_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS);
void update_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS);
//--------------------------------Employer functions starts-------------------------------------------
int Employ_menu(int option3);
bool Employ_Menu(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS);
void Take_Order(string nameA[], int priceA[], int quantityA[], string companyA[], int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int product_count, int costumer_count);
void add_costumer_record_in_arr(string c_n, string o, int p, int r, int a, int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Quantity[], int Price[], int Bill[], int costumer_count);
void show_costumer_records(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count);
// -------------------------------Costumer function----------------------------------------------------
int costumer_menu(int option4);
void Order(string nameA[], int priceA[], int quantityA[], string companyA[], int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int product_count, int costumer_count);
//------------------------------- Validations check part-----------------------------------------------
bool validate(string name2, string pass2); // main menu username and password checker
void validate_in_price(int new_price);
string count_contact(int limit, string contact); // contact number checker
bool validate_log_in(int login, int Employ_LoginA[], int Employ_count);
//-------------------------------File Handling---------------------------------------------------------
void store(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count);
string parseData(string record, int field);
int load(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count);
void store_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count);
int load_employ_records(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count);
void store_costumer(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count);
int load_costumer_records(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count);

//------------------------------End of function prototypes----------------------------------------------

//___________________________________________Main starts________________________________________________
main()
{
    int option;
    int option2, option3, option4;
    int MainOption;
    int Admin_Option;
    int Employ_option;
    int Costumer_option;
    const int TOTAL_RECORDS = 100;
    //-----------PRODUCTS ARRAYS
    string nameA[TOTAL_RECORDS];
    int priceA[TOTAL_RECORDS];
    string companyA[TOTAL_RECORDS];
    int quantityA[TOTAL_RECORDS];
    int product_count = load(nameA, priceA, quantityA, companyA, product_count);
    //-------------Employer arrays
    string Employ_nameA[TOTAL_RECORDS];
    string Employ_DesigA[TOTAL_RECORDS];
    int Employ_salaryA[TOTAL_RECORDS];
    int Employ_LoginA[TOTAL_RECORDS];
    string Employ_ContactA[TOTAL_RECORDS];
    int Employ_count = load_employ_records(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
    //--------------Costumer record arr
    string Costumer_name[TOTAL_RECORDS];
    string Product_name[TOTAL_RECORDS];
    int Price[TOTAL_RECORDS];
    int Quantity[TOTAL_RECORDS];
    int Bill[TOTAL_RECORDS];
    int costumer_count = 0;
    costumer_count = load_costumer_records(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 1);

    //----------------------------------------------------------------------------------------------------------------
    MainOption = Main_Menu(option);
    while (MainOption < 5)
    {

        if (MainOption == 1)

        {
            if (validate("admin", "123") == 1)
            { // admin k bad jo password enter krna wo check krny lye

                char key = 'a';
                while (true)
                {
                    if (key == 'A' || key == 'a')
                    {
                        Admin_Option = Admin_Menu(option2);
                    }

                    if (Admin_Option == 1)
                    {

                        Add_Prduct(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                        product_count++;
                        store(nameA, priceA, quantityA, companyA, product_count);
                    }
                    else if (Admin_Option == 2)
                    { // view products
                        system("cls");
                        header2();
                        subheader("Main Menu", "Admin Portal", "View Products");
                        view_products(nameA, priceA, quantityA, companyA, product_count);
                    }
                    else if (Admin_Option == 3)
                    {
                        // check stock
                        check_stock(nameA, priceA, quantityA, companyA, product_count);
                    }
                    else if (Admin_Option == 4)
                    {
                        // Del
                        if (DEL_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS) == 1)
                        {
                            product_count--;
                        }
                    }
                    else if (Admin_Option == 5)
                    {
                        // update
                        Update_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                        // store(nameA, priceA, quantityA, companyA, product_count);
                    }
                    else if (Admin_Option == 6)
                    {
                        string op;
                        string sort;
                        while (true)
                        {
                            sort = sorting("op");

                            if (sort == "1")
                            {
                                system("cls");
                                subheader("Main Menu", "Admin Portal", "Ascending sorting");
                                Ascending_sorting(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                                system("pause");
                            }
                            else if (sort == "2")
                            {
                                subheader("Main Menu", "Admin Portal", "Descending sorting");
                                Descending_sorting(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                                system("pause");
                            }

                            else if (sort == "3")
                            {
                                break;
                            }
                            else
                            {
                                cout << "--------------------Wrong input-------------------" << endl;
                                break;
                            }
                        }
                    }

                    else if (Admin_Option == 7)
                    {
                        // serch product
                        search_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                    }
                    else if (Admin_Option == 8)
                    {
                        // Add employ
                        Add_Employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
                        Employ_count++;
                        // to store in file
                    }
                    else if (Admin_Option == 9)
                    {
                        // view record of employ
                        view_record_employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
                    }
                    else if (Admin_Option == 10)
                    {
                        // del record of emply
                        if (Del_employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count, TOTAL_RECORDS) == 1)
                        {
                            Employ_count--;
                        }
                    }
                    else if (Admin_Option == 11)
                    {
                        //  update record of emply
                        update_employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count, TOTAL_RECORDS);
                    }
                    else if (Admin_Option == 12)
                    {
                        //  view prevois costumer records
                        show_costumer_records(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);
                    }
                    else if (Admin_Option == 13)
                    {

                        // if we delete any record then it will resave all the products again
                        store(nameA, priceA, quantityA, companyA, product_count); // to store in file
                        store_employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
                        break;
                    }
                    else
                    {
                        cout << "        INVALID INPUT ! Please try again........." << endl;
                        system("pause");
                    }
                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "         Press A or a to go back to admin menu..." << endl;
                    cin >> key;
                }

                // Admin while loops ends here
            }

            MainOption = Main_Menu(option);
        }
        // Employ menu starts from here
        else if (MainOption == 2)
        {

            if (Employ_Menu(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count, TOTAL_RECORDS) == 1)
            {
                char key2 = 'e';
                while (true)
                {
                    if (key2 == 'E' || key2 == 'e')
                    {
                        Employ_option = Employ_menu(option3);
                    }

                    if (Employ_option == 1)
                    {
                        Take_Order(nameA, priceA, quantityA, companyA, TOTAL_RECORDS, Costumer_name, Product_name, Price, Quantity, Bill, product_count, costumer_count);
                        costumer_count++;
                    }

                    else if (Employ_option == 2)
                    {
                        Add_Prduct(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                        product_count++;
                        store(nameA, priceA, quantityA, companyA, product_count); // to store in file
                    }
                    else if (Employ_option == 3)
                    {
                        if (DEL_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS) == 1)
                        {
                            product_count--;
                        }
                    }
                    else if (Employ_option == 4)
                    {
                        Update_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                    }

                    else if (Employ_option == 5)
                    {
                        search_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                    }
                    else if (Employ_option == 6)
                    {
                        store(nameA, priceA, quantityA, companyA, product_count); // to store in file
                        store_costumer(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);

                        break;
                    }
                    else
                    {
                        cout << "INVALID INPUT..........!!" << endl;
                    }

                    SetConsoleTextAttribute(hConsole, 15);
                    cout << "         Press E or e to go back to employer menu..." << endl;
                    cin >> key2;
                    if (key2 == 'E' || key2 == 'e')
                    {
                        Employ_option = Employ_menu(option3);
                    }
                }
            }

            // Employ menu ends here.....
            MainOption = Main_Menu(option);
        }
        // costumer menu starts from here
        else if (MainOption == 3)
        {
            while (true)
            {
                Costumer_option = costumer_menu(option4);
                if (Costumer_option == 1)
                {
                    system("cls");
                    header3();
                    subheader("Main Menu", "Costumer Portal", "View Products");
                    view_products(nameA, priceA, quantityA, companyA, product_count);
                }
                else if (Costumer_option == 2)
                { // order

                    Order(nameA, priceA, quantityA, companyA, TOTAL_RECORDS, Costumer_name, Product_name, Price, Quantity, Bill, product_count, costumer_count);
                    costumer_count++;
                    // store_costumer(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);
                }
                else if (Costumer_option == 3)
                {
                    // search product
                    search_product(nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
                }

                else if (Costumer_option == 4)
                {
                    store_costumer(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);

                    break;
                }

                else
                {
                    cout << "INVALID INPUT.........";
                }
                char key3;
                SetConsoleTextAttribute(hConsole, 15);
                cout << "         Press C or c to go back to employer menu..." << endl;
                cin >> key3;
                if (key3 == 'E' || key3 == 'e')
                {
                    Costumer_option = costumer_menu(option4);
                }
            }
            MainOption = Main_Menu(option);
        }
        // costumer menu ends here
        else if (MainOption == 4)
        {
            store(nameA, priceA, quantityA, companyA, product_count); // to store in file
            store_employ(Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
            store_costumer(Costumer_name, Product_name, Price, Quantity, Bill, costumer_count);
            cout << "Thank you for using the system..........";
            break;
        }
    }
}
//--------------------------------------End of Main-------------------------------------------------

void gotoxy(int x, int y) // Function Definition
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void header()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(31, 0);
    cout << "**********************************************************************************" << endl;
    gotoxy(65, 1);
    cout << "Stationary Managemnet system" << endl;
    gotoxy(31, 2);
    cout << "**********************************************************************************" << endl;
}
void header2()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(31, 0);
    cout << "**********************************************************************************" << endl;
    gotoxy(65, 1);
    cout << "Welcome Admin                                    " << endl;
    gotoxy(31, 2);
    cout << "**********************************************************************************" << endl;
}
void header3()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 15);
    gotoxy(31, 0);
    cout << "*********************************************************************************" << endl;
    gotoxy(65, 1);
    cout << " Welcome to Golden Staioners                      " << endl;
    gotoxy(31, 2);
    cout << "*********************************************************************************" << endl;
}
void subheader(string mainmenu, string submenu, string submenu2)
{
    gotoxy(16, 3);
    cout << " | " << mainmenu << " >> " << submenu << " >> " << submenu2 << " | " << endl;
}

// Admin functions start
// This functions to check password and username
bool validate(string name2, string pass2)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    string name, pass;
    bool a_name = true;
    bool a_pass = true;
    gotoxy(9, 10);
    cout << "Enter username please:";
    gotoxy(69, 10);
    cout << "Enter your password:";
    gotoxy(9, 11);
    cin >> name;
    gotoxy(69, 11);
    cin >> pass;
    if (name == "admin" && pass == "123")
    {
        return true;
    }

    else if (name != "admin")
    {
        a_name = false;
    }
    if (pass != "123" || pass < "0")
    {
        a_pass = false;
    }
    if (a_name == false && a_pass == false)
    {
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(9, 13);
        cout << "-----------------------Wrong Credentials-------------------" << endl;
    }
    else if (a_name == false)
    {
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(9, 13);
        cout << "Enter correct username-----------!!" << endl;
    }
    else if (a_pass == false)
    {
        SetConsoleTextAttribute(hConsole, 4);
        gotoxy(9, 13);
        cout << "Enter correct password----------!!" << endl;
    }
    system("pause");
    return 0;
}
int Main_Menu(int option) // Function to return main menu choice
{
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
}
int Admin_Menu(int option2) // Function to return admin choice
{
    system("CLS");
    header2();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 4);
    cout << endl;
    cout << "         Main Menu >> Admin portal" << endl;
    cout << endl;
    cout << "         Enter right option here" << endl;
    cout << "         1-Add products" << endl;
    cout << "         2-View all products available at this time" << endl;
    cout << "         3-View products is in stock or not" << endl;
    cout << "         4-Delete products" << endl;
    cout << "         5-Update products" << endl;
    cout << "         6-View all items price vise" << endl;
    cout << "         7-Search product" << endl;
    cout << "         8-Add employ" << endl;
    cout << "         9-View record of all the employ" << endl;
    cout << "         10-Delete records of employ" << endl;
    cout << "         11-Update records of employ" << endl;
    cout << "         12-View costumer records" << endl;
    cout << "         13-Exit" << endl;
    gotoxy(9, 20);
    cin >> option2;
    return option2;
}

void Add_Prduct(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{
    string name;
    int price;
    int quantity;
    string company;
    string ans;
    system("CLS");
    header3();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    cout << endl;
    // subheader for sub headings
    subheader("Main Menu", "Admin Portal", "Add product");
    cout << endl;
    gotoxy(9, 6);
    cout << "Enter product name : ";
    gotoxy(49, 6);
    cout << "Enter price  : ";
    gotoxy(89, 6);
    cout << "Enter quantity: ";
    gotoxy(9, 9);
    cout << "Enter company : ";
    gotoxy(9, 7);
    cin >> name;
    do
    { // To check price greater than zero
        gotoxy(49, 7);
        cin >> price;
        if (price <= 0)
        {
            gotoxy(49, 8);
            cout << "Enter price greater then zero!!" << endl;
        }

    } while (price <= 0);

    do // To check quantity greater than zero
    {
        gotoxy(89, 7);
        cin >> quantity;
        if (quantity < 0 || quantity == 0)
        {
            gotoxy(89, 8);
            cout << "Enter quantity > 0----!!" << endl;
        }
    } while (quantity < 0 || quantity == 0);

    gotoxy(9, 10);
    cin >> company;
    gotoxy(9, 15);
    cout << "Your prodcut has been added successfully..........." << endl;

    add_products_in_array(name, price, quantity, company, nameA, priceA, quantityA, companyA, product_count, TOTAL_RECORDS);
}

void add_products_in_array(string n, int p, int q, string comp, string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{

    nameA[product_count] = n;
    priceA[product_count] = p;
    quantityA[product_count] = q;
    companyA[product_count] = comp;
}

void view_products(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count)
{

    gotoxy(16, 5);
    cout << "---------------------------------------------------------" << endl;
    gotoxy(16, 6);
    cout << "Name           Price          Quantity         Company" << endl;
    gotoxy(16, 7);
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < product_count; i++)
    { // product count is lye kyu k agar total record rkhty to 0 0 show hota
        cout << "\t"
             << "\t" << nameA[i] << "\t"
             << "\t" << priceA[i] << "\t"
             << "\t" << quantityA[i] << "\t"
             << "\t" << companyA[i] << endl;
    }
}

void check_stock(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count)
{
    string stock_check;
    string stock_check_company;
    bool flag1 = false;
    bool flag2 = true;
    bool flag3 = true;
    bool flag4 = true;
    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal", "Check stock");
    gotoxy(16, 5);
    cout << "Enter name of the product:";
    gotoxy(66, 5);
    cout << "Enter name of the company:";
    gotoxy(16, 6);
    cin >> stock_check;
    gotoxy(66, 6);
    cin >> stock_check_company;

    for (int i = 0; i < product_count; i++)
    {
        if (nameA[i] == stock_check && companyA[i] == stock_check_company)
        {
            flag1 = true;
            if (flag1 == true)
            {
                if (quantityA[i] > 1000)
                {
                    gotoxy(16, 8);
                    cout << nameA[i] << " is in stock and its total quantity is = " << quantityA[i] << endl;
                }
                else if (quantityA[i] < 1000)
                {
                    gotoxy(16, 8);
                    cout << nameA[i] << " is not in stock and its total quantity is = " << quantityA[i] << endl;
                }
            }
        }
        else
        {
            flag1 = false;
        }
    }
    if (flag1 == false)
    {
        gotoxy(16, 8);
        cout << "Product not found.!!!" << endl;
    }
}

bool DEL_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{

    string del_product;
    bool flag;
    system("CLS");
    header2();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    subheader("Main Menu", "Admin Portal", "Delete product");
    gotoxy(16, 5);
    cout << "Enter name of the product you want to delete:";
    gotoxy(16, 6);
    cin >> del_product;
    for (int i = 0; i <= TOTAL_RECORDS; i++)
    {
        if (nameA[i] == del_product)
        {
            flag = true;
            nameA[i] = nameA[i + 1];
            priceA[i] = priceA[i + 1];
            quantityA[i] = quantityA[i + 1];
            companyA[i] = companyA[i + 1];
        }
    }
    if (flag == true)
    {
        gotoxy(16, 8);
        cout << "Your prodct has been deleted successfully.......!!" << endl;
    }
    else if (flag == false)
    {
        gotoxy(16, 8);
        cout << "Product not found.....!!" << endl;
    }
    return flag;
}

void Update_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{
    string update_product;
    bool flag2;
    int new_price;
    int new_quan;
    string new_comp;

    system("CLS");
    header2();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    subheader("Main Menu", "Admin Portal", "Update Product");
    gotoxy(16, 5);
    cout << "Enter name of the product you want to Update:";
    gotoxy(16, 6);
    cin >> update_product;
    for (int i = 0; i < TOTAL_RECORDS; i++)
    {
        if (nameA[i] == update_product)
        {
            flag2 = true;
            gotoxy(16, 7);
            cout << "Enter new prices." << endl;
            gotoxy(16, 8);
            cin >> new_price;
            //----------------------------function to check price greater than zero
            // validate_in_price(new_price);
            //----------------------------------------------------------------
            gotoxy(56, 7);
            cout << "Enter new quantity." << endl;
            gotoxy(56, 8);
            cin >> new_quan;
            gotoxy(96, 7);
            cout << "Enter new company." << endl;
            gotoxy(96, 8);
            cin >> new_comp;

            priceA[i] = new_price;
            quantityA[i] = new_quan;
            companyA[i] = new_comp;
        }
    }
    if (flag2 == true)
    {
        gotoxy(16, 10);
        cout << "Your product has been updated successfully..!! " << endl;
    }
    else if (flag2 == false)
    {
        gotoxy(16, 7);
        cout << "Product not found...!" << endl;
    }
}
void validate_in_price(int new_price) // used in update product
{
    while (true)
    {
        gotoxy(16, 8);
        cin >> new_price;

        if (new_price <= 0)
        {
            gotoxy(16, 9);
            cout << "Enter price greater then zero" << endl;
        }
        else
        {
            break;
        }
    }
}

string sorting(string op)
{

    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal", "Price vice sorting");
    gotoxy(16, 4);
    cout << "How you wan to see sorting.. ";
    gotoxy(16, 5);
    cout << "1-In accessding order."; // choatay sy bra
    gotoxy(76, 5);
    cout << "2-In decessending order." << endl; // baray sy chota
    gotoxy(16, 6);
    cout << "3-Exit" << endl;
    gotoxy(16, 7);
    cin >> op;

    return op;
}
void Ascending_sorting(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{
    for (int i = 0; i < product_count - 1; i++)
    {
        for (int j = i + 1; j < product_count; j++)
        {
            if (priceA[j] < priceA[i])
            {
                float temp = priceA[j];
                priceA[j] = priceA[i];
                priceA[i] = temp;

                string temp_company = companyA[j];
                companyA[j] = companyA[i];
                companyA[i] = temp_company;

                string temp_product = nameA[j];
                nameA[j] = nameA[i];
                nameA[i] = temp_product;

                float temp_quan = quantityA[j];
                quantityA[j] = quantityA[i];
                quantityA[i] = temp_quan;
            }
        }
    }
    gotoxy(16, 9);
    cout << "---------------------------------------------------------" << endl;
    gotoxy(16, 10);
    cout << "Name           Price          Quantity         Company" << endl;
    gotoxy(16, 11);
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < product_count; i++)
    { // product count is lye kyu k agar total record rkhty to 0 0 show hota
        cout << "\t"
             << "\t" << nameA[i] << "\t"
             << "\t" << priceA[i] << "\t"
             << "\t" << quantityA[i] << "\t"
             << "\t" << companyA[i] << endl;
    }
}

void Descending_sorting(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{

    for (int i = 0; i < product_count - 1; i++)
    {
        for (int j = i + 1; j < product_count; j++)
        {
            if (priceA[j] > priceA[i])
            {
                float temp = priceA[j];
                priceA[j] = priceA[i];
                priceA[i] = temp;

                string temp_company = companyA[j];
                companyA[j] = companyA[i];
                companyA[i] = temp_company;

                string temp_product = nameA[j];
                nameA[j] = nameA[i];
                nameA[i] = temp_product;

                float temp_quan = quantityA[j];
                quantityA[j] = quantityA[i];
                quantityA[i] = temp_quan;
            }
        }
    }
    gotoxy(16, 9);
    cout << "---------------------------------------------------------" << endl;
    gotoxy(16, 10);
    cout << "Name           Price          Quantity         Company" << endl;
    gotoxy(16, 11);
    cout << "---------------------------------------------------------" << endl;

    for (int i = 0; i < product_count; i++)
    { // product count is lye kyu k agar total record rkhty to 0 0 show hota
        cout << "\t"
             << "\t" << nameA[i] << "\t"
             << "\t" << priceA[i] << "\t"
             << "\t" << quantityA[i] << "\t"
             << "\t" << companyA[i] << endl;
    }
}

void search_product(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count, int TOTAL_RECORDS)
{
    string search;
    bool flag = false;
    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal ", "Search Product");
    gotoxy(16, 5);
    cout << "Enter name of the product you want to search:";
    gotoxy(16, 6);
    cin >> search;
    for (int i = 0; i < TOTAL_RECORDS; i++)
    {
        if (nameA[i] == search)
        {
            flag = true;
            gotoxy(16, 7);
            cout << "Name of the product is : " << nameA[i];
            gotoxy(56, 7);
            cout << "Quantity of the product available = " << quantityA[i];
            gotoxy(16, 8);
            cout << "Price of the product is = " << priceA[i];
            gotoxy(56, 8);
            cout << "Company of the product is : " << companyA[i] << endl;
        }
    }
    if (flag == false)
    {
        gotoxy(16, 7);
        cout << "Product not found...!!" << endl;
    }
}

void Add_Employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count)
{
    string employname;
    int employsalary;
    string employdesignation;
    int employlogin;
    string employcontact;

    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal ", "Add Emlpoy");
    gotoxy(16, 4);
    cout << "Enter name of the employ:";
    gotoxy(56, 4);
    cout << "Enter designation of the employ:";
    gotoxy(16, 6);
    cout << "Enter salary of the employ:";
    gotoxy(56, 6);
    cout << "Enter log in id of employ:";
    gotoxy(16, 8);
    cout << "Enter contact no. of employ:";
    gotoxy(16, 5);
    cin >> employname;
    gotoxy(56, 5);
    cin >> employdesignation;
    gotoxy(16, 7);
    cin >> employsalary;
    gotoxy(56, 7);
    cin >> employlogin;

    while (validate_log_in(employlogin, Employ_LoginA, Employ_count) == false)
    {
        // this while loop to check same login id;
        gotoxy(56, 8);
        cout << "This log-in id  has already been taken!";
        cout << "Enter again.....";
        cin >> employlogin;
    }
    gotoxy(16, 9);
    string contact;
    employcontact = count_contact(11, contact); // validation checker for contact count
    Add_employ_in_array(employname, employdesignation, employsalary, employlogin, employcontact, Employ_nameA, Employ_DesigA, Employ_salaryA, Employ_LoginA, Employ_ContactA, Employ_count);
}

// validate functions to count contact number
string count_contact(int limit, string contact)
{

    int count = 0;
    bool flag = true;
    do
    {
        cin >> contact;
        for (int i = 0; contact[i] != '\0'; i++)
        {
            count++;
        }
        if (count != 11)
        {
            cout << "          Enter valid number ";
            count = 0;
        }

    } while (count != 11);
    return contact;
}
bool validate_log_in(int login, int Employ_LoginA[], int Employ_count)
{
    // to check for same login
    for (int i = 0; i < Employ_count; i++)
    {
        if (Employ_LoginA[i] == login)
        {
            return false;
        }
    }
    return true;
}

void Add_employ_in_array(string n, string d, int s, int log, string contact, string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count)
{
    Employ_nameA[Employ_count] = n;
    Employ_DesigA[Employ_count] = d;
    Employ_salaryA[Employ_count] = s;
    Employ_LoginA[Employ_count] = log;
    Employ_ContactA[Employ_count] = contact;
}

void view_record_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count)
{
    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal ", "Employ Record");
    gotoxy(16, 4);
    cout << "-------------------------------------------------------------------------------" << endl;
    gotoxy(16, 5);
    cout << "Name           Designation          Salary         LOGin ID         Contact no" << endl;
    gotoxy(16, 6);
    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < Employ_count; i++)
    { // product count is lye kyu k agar total record rkhty to 0 0 show hota
        cout << "\t"
             << "\t" << Employ_nameA[i] << "\t"
             << "\t" << Employ_DesigA[i] << "\t"
             << "\t" << Employ_salaryA[i] << "\t"
             << "\t" << Employ_LoginA[i] << "\t"
             << "\t" << Employ_ContactA[i] << endl;
    }
}

bool Del_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS)
{
    int del_employ;
    bool flag;
    system("CLS");
    header2();
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    subheader("Main Menu", "Admin Portal ", "Delete Employ");
    gotoxy(16, 5);
    cout << "Enter login id  of the employer you want to delete:";
    gotoxy(16, 6);
    cin >> del_employ;
    for (int i = 0; i <= TOTAL_RECORDS; i++)
    {
        if (Employ_LoginA[i] == del_employ)
        {
            flag = true;
            Employ_nameA[i] = Employ_nameA[i + 1];
            Employ_DesigA[i] = Employ_DesigA[i + 1];
            Employ_salaryA[i] = Employ_salaryA[i + 1];
            Employ_LoginA[i] = Employ_LoginA[i + 1];
            Employ_ContactA[i] = Employ_ContactA[i + 1];
        }
    }
    if (flag == true)
    {
        gotoxy(16, 9);
        cout << "Your record has been deleted successfully.......!!" << endl;
    }
    else if (flag == false)
    {
        gotoxy(16, 9);
        cout << "Record not found.....!!" << endl;
    }
    return flag;
}
void update_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS)
{
    bool flag2;
    int update_employ;
    string new_name;
    string new_desig;
    int new_salary;
    int new_login;
    string new_contact;
    system("CLS");
    header2();
    subheader("Main Menu", "Admin Portal ", "Update Record of Employ");
    gotoxy(16, 5);
    cout << "Enter login id of the employer you want to Update:";
    gotoxy(16, 6);
    cin >> update_employ;
    for (int i = 0; i < TOTAL_RECORDS; i++)
    {
        if (Employ_LoginA[i] == update_employ)
        {
            flag2 = true;
            gotoxy(16, 7);
            cout << "Enter new name:" << endl;
            gotoxy(16, 8);
            cin >> new_name;
            gotoxy(56, 7);
            cout << "Enter new designation:" << endl;
            gotoxy(56, 8);
            cin >> new_desig;
            gotoxy(96, 7);
            cout << "Enter new salary:" << endl;
            gotoxy(96, 8);
            cin >> new_salary;
            gotoxy(16, 9);
            cout << "Enter new log in id:" << endl;
            gotoxy(16, 10);
            cin >> new_login;
            gotoxy(56, 9);
            cout << "Enter new contact number:" << endl;
            gotoxy(56, 10);
            string contact;
            new_contact = count_contact(11, contact); // validation checker for contact count

            Employ_nameA[i] = new_name;
            Employ_DesigA[i] = new_desig;
            Employ_salaryA[i] = new_salary;
            Employ_LoginA[i] = new_login;
            Employ_ContactA[i] = new_contact;
        }
    }
    if (flag2 == true)
    {
        gotoxy(16, 12);
        cout << "Your record has been updated successfully..!! " << endl;
    }
    else if (flag2 == false)
    {
        gotoxy(16, 7);
        cout << "Record not found...!" << endl;
    }
}

// Employ functoins definitions
int Employ_menu(int option3)
{
    system("cls");
    header3();
    gotoxy(31, 7);
    cout << "Enter your option here:";
    gotoxy(31, 8);
    cout << "1-Take order of the costumers.";
    gotoxy(31, 9);
    cout << "2-Add more products.";
    gotoxy(31, 10);
    cout << "3-Delete products..";
    gotoxy(31, 11);
    cout << "4-Update products.";
    gotoxy(31, 12);
    cout << "5-Search product.";
    gotoxy(31, 13);
    cout << "6-Exit";
    gotoxy(31, 14);
    cin >> option3;
    return option3;
}

bool Employ_Menu(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count, int TOTAL_RECORDS)
{
    string username;
    int login;
    bool flag1 = false;
    bool flag2 = false;
    int employ_option;
    int option3;

    system("CLS");
    header3();
    gotoxy(31, 3);
    cout << "Enter your name:";
    gotoxy(90, 3);
    cout << "Enter you log in id:" << endl;
    gotoxy(31, 4);
    cin >> username;
    gotoxy(90, 4);
    cin >> login;
    system("cls");

    for (int i = 0; i < Employ_count; i++)
    {
        if (Employ_LoginA[i] == login)
        {
            flag1 = true;
            if (Employ_nameA[i] == username)
            {
                flag2 = true;

                gotoxy(31, 5);
                cout << "Employer name : " << Employ_nameA[i];
                gotoxy(88, 5);
                cout << "Employer Designation : " << Employ_DesigA[i] << endl;
                gotoxy(31, 6);
                cout << "--------------------------------------------------------------------------------------";
            }
        }
    }
    if (flag1 == false)
    {

        gotoxy(31, 5);
        cout << "Enter correct log in....." << endl;
    }
    else if (flag2 == false)
    {
        gotoxy(31, 5);
        cout << "Enter correct username....." << endl;
    }
    if (flag1 == true && flag2 == true)
    {
        return 1;
    }
    return 0;
}

void Take_Order(string nameA[], int priceA[], int quantityA[], string companyA[], int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int product_count, int costumer_count)
{
    //// costumer order k lye
    string c_name;
    string order;
    int quantity;
    int pieces;
    int rate;
    int amount;
    int left;
    bool flag = false;
    bool flag2 = false;

    system("CLS");
    header2();
    subheader("Main Menu", "Employ Portal ", "Take Order");
    view_products(nameA, priceA, quantityA, companyA, product_count);
    cout << endl;
    cout << "Enter name of the costumer........................... ";
    cin >> c_name;
    cout << "Enter name of the product costumer want to order..... ";
    cin >> order;
    for (int i = 0; i < TOTAL_RECORDS; i++)
    {
        if (nameA[i] == order)
        {
            flag = true;

            cout << "Enter no of pieces...................................: ";
            cin >> pieces;
            if (quantityA[i] >= pieces)
            {
                flag2 = true;
                quantityA[i] = quantityA[i] - pieces; // jitny bik gay utnay total ma say kam b krny hyn
                cout << "ENTER RATE..............................................";
                cin >> rate;
                system("CLS");
                header3();
                gotoxy(16, 3);
                cout << "Costumer name : " << c_name;
                gotoxy(16, 4);
                cout << "-------------------------------------------------------------------------------------------------------";
                gotoxy(16, 5);
                cout << "Product name";
                gotoxy(36, 5);
                cout << "Rate";
                gotoxy(56, 5);
                cout << "Quantity";
                gotoxy(96, 5);
                cout << "Amount";
                amount = pieces * rate;
                gotoxy(16, 6);
                cout << "-------------------------------------------------------------------------------------------------------";
                gotoxy(16, 7);
                cout << order;
                gotoxy(36, 7);
                cout << rate;
                gotoxy(56, 7);
                cout << pieces;
                gotoxy(96, 7);
                cout << amount << endl;

                add_costumer_record_in_arr(c_name, order, pieces, rate, amount, TOTAL_RECORDS, Costumer_name, Product_name, Quantity, Price, Bill, costumer_count);
            }
            else if (quantityA[i] < pieces)
            {
                flag2 = false;
                left = pieces - quantityA[i];
            }
        }
    }
    if (flag == false)
    {
        cout << "Product not found........!!" << endl;
    }
    else if (flag2 == false)
    {
        cout << " Only " << left << " available............  !!" << endl;
    }
}

void add_costumer_record_in_arr(string c_n, string o, int p, int r, int a, int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Quantity[], int Price[], int Bill[], int costumer_count)
{
    Costumer_name[costumer_count] = c_n;
    Product_name[costumer_count] = o;
    Quantity[costumer_count] = p;
    Price[costumer_count] = r;
    Bill[costumer_count] = a;
}

void show_costumer_records(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count)
{
    system("CLS");
    header2();
    subheader("Main Menu", "Employ Portal ", "Record of costumer");

    gotoxy(16, 4);
    cout << "-------------------------------------------------------------------------------" << endl;
    gotoxy(16, 5);
    cout << "C_Name          Order          Price         Quantity              Bill             " << endl;
    gotoxy(16, 6);
    cout << "-------------------------------------------------------------------------------" << endl;

    for (int i = 0; i < costumer_count; i++)
    { // product count is lye kyu k agar total record rkhty to 0 0 show hota
        cout << "\t"
             << "\t" << Costumer_name[i] << "\t"
             << "\t" << Product_name[i] << "\t"
             << "\t" << Price[i] << "\t"
             << "\t" << Quantity[i] << "\t"
             << "\t" << Bill[i] << endl;
    }
}

// Costumer functons definitions

int costumer_menu(int option4)
{
    system("CLS");
    header3();
    gotoxy(31, 7);
    cout << "Enter your option here:";
    gotoxy(31, 8);
    cout << "1-View all products";
    gotoxy(31, 9);
    cout << "2-Order.";
    gotoxy(31, 10);
    cout << "3-Search Product.";
    gotoxy(31, 11);
    cout << "4-Exit";
    gotoxy(31, 13);
    cin >> option4;
    return option4;
}

void Order(string nameA[], int priceA[], int quantityA[], string companyA[], int TOTAL_RECORDS, string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int product_count, int costumer_count)
{

    //// costumer order k lye
    string c_name;
    string order;
    int quantity;
    int pieces;
    int rate;
    int amount;
    int left;
    bool flag = false;
    bool flag2 = false;

    system("CLS");
    header3();
    subheader("Main Menu", "Costumer Portal ", "Order");
    view_products(nameA, priceA, quantityA, companyA, product_count);
    cout << endl;
    // order starts from here
    cout << "Enter your  name ........................... ";
    cin >> c_name;
    cout << "Enter name of the product................... ";
    cin >> order;
    for (int i = 0; i < TOTAL_RECORDS; i++)
    {
        if (nameA[i] == order)
        {
            flag = true;

            cout << "Enter no of pieces...................................: ";
            cin >> pieces;
            if (quantityA[i] >= pieces)
            {
                flag2 = true;
                quantityA[i] = quantityA[i] - pieces; // jitny bik gay utnay total ma say kam b krny hyn

                system("CLS");
                header3();
                gotoxy(16, 3);
                cout << "Costumer name : " << c_name;
                gotoxy(16, 4);
                cout << "-------------------------------------------------------------------------------------------------------";
                gotoxy(16, 5);
                cout << "Product name";
                gotoxy(36, 5);
                cout << "Rate";
                gotoxy(56, 5);
                cout << "Quantity";
                gotoxy(96, 5);
                cout << "Amount";
                amount = pieces * priceA[i];
                gotoxy(16, 6);
                cout << "-------------------------------------------------------------------------------------------------------";
                gotoxy(16, 7);
                cout << order;
                gotoxy(36, 7);
                cout << priceA[i];
                gotoxy(56, 7);
                cout << pieces;
                gotoxy(96, 7);
                cout << amount << endl;

                add_costumer_record_in_arr(c_name, order, pieces, rate, amount, TOTAL_RECORDS, Costumer_name, Product_name, Quantity, Price, Bill, costumer_count);
            }
            else if (quantityA[i] < pieces)
            {
                flag2 = false;
                left = pieces - quantityA[i];
            }
        }
    }
    if (flag == false)
    {
        cout << "Product not found........!!" << endl;
    }
    else if (flag2 == false)
    {
        cout << " Only " << left << " available............  !!" << endl;
    }
}

//--------------------------------------------File Handling-------------------------------------------
void store(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count)
{
    fstream newfile;
    newfile.open("products.txt", ios::out);
    for (int i = 0; i < product_count; i++)
    {
        newfile << nameA[i] << "," << priceA[i] << "," << quantityA[i] << "," << companyA[i] << endl;
    }
    newfile.close();
}

string parseData(string record, int field)
{
    int comma = 1;
    string item;
    for (int x = 0; x < record.length(); x++)
    {
        if (record[x] == ',')
        {
            comma = comma + 1;
        }
        else if (comma == field)
        {
            item = item + record[x];
        }
    }
    return item;
}
int load(string nameA[], int priceA[], int quantityA[], string companyA[], int product_count)
{
    fstream f;
    string record;
    int idx = 0;
    f.open("products.txt", ios::in);
    while (!(f.eof()))
    {
        getline(f, record);
        if (record != "")
        {
            nameA[idx] = parseData(record, 1);
            priceA[idx] = stoi(parseData(record, 2));
            quantityA[idx] = stoi(parseData(record, 3));
            companyA[idx] = parseData(record, 4);
            idx++;
        }
    }
    f.close();
    return idx;
}

void store_employ(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count)
{
    fstream newfile1;
    newfile1.open("Employ.txt", ios::out);
    for (int i = 0; i < Employ_count; i++)
    {
        newfile1 << Employ_nameA[i] << "," << Employ_DesigA[i] << "," << Employ_salaryA[i] << "," << Employ_LoginA[i] << "," << Employ_ContactA[i] << endl;
    }
    newfile1.close();
}
int load_employ_records(string Employ_nameA[], string Employ_DesigA[], int Employ_salaryA[], int Employ_LoginA[], string Employ_ContactA[], int Employ_count)
{
    fstream f;
    string record;
    int idx = 0;
    f.open("Employ.txt", ios::in);
    while (!(f.eof()))
    {
        getline(f, record);
        if (record != "")
        {
            Employ_nameA[idx] = parseData(record, 1);
            Employ_DesigA[idx] = parseData(record, 2);
            Employ_salaryA[idx] = stoi(parseData(record, 3));
            Employ_LoginA[idx] = stoi(parseData(record, 4));
            Employ_ContactA[idx] = parseData(record, 5);
            idx++;
        }
    }
    f.close();
    return idx;
}
void store_costumer(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count)
{
    fstream newfile2;
    newfile2.open("Costumer_record.txt", ios::out);
    for (int i = 0; i < costumer_count; i++)
    {
        newfile2 << Costumer_name[i] << "," << Product_name[i] << "," << Price[i] << "," << Quantity[i] << "," << Bill[i] << endl;
    }
    newfile2.close();
}
int load_costumer_records(string Costumer_name[], string Product_name[], int Price[], int Quantity[], int Bill[], int costumer_count)
{
    fstream f;
    string record;
    int idx = 0;
    f.open("Costumer_record.txt", ios::in);
    while (!(f.eof()))
    {
        getline(f, record);
        if (record != "")
        {
            Costumer_name[idx] = parseData(record, 1);
            Product_name[idx] = parseData(record, 2);
            Price[idx] = stoi(parseData(record, 3));
            Quantity[idx] = stoi(parseData(record, 4));
            Bill[idx] = stoi(parseData(record, 5));
            idx++;
        }
    }
    f.close();
    return idx;
}
