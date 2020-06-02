#include <iostream>
#include "all.h"

using namespace std;

int menu(char * file_call, char * file_crew) {

    //Думаю, что к меню дополнительные комментарии не нужны. Не в main, потому что его
    //засорять нехорошо.

    int choice;
    system("clear");//Просто для более красивого меню(что-бы всё не было одно под другим)
    cout << "Выберите действие:" << endl;
    cout << "1 - вывести базу экипажей" << endl;
    cout << "2 - редактировать базу экипажей" << endl;
    cout << "3 - назначить дежурные экипажи" << endl;
    cout << "4 - вывести информацию о дежурных экипажах" << endl;
    cout << "5 - принять вызов" << endl;
    cout << "6 - вывести историю вызовов" << endl;
    cout << "7 - задать время" << endl;
    cout << "другая цифра - завершить работу" << endl;

    cin >> choice;

    switch (choice) {

    case 1: 
        system("clear");   
        print_crew(file_call, file_crew);
        break;
    case 2: 
        system("clear");
        edit_crew(file_call,file_crew);
        break;
    case 3: 
        system("clear");
        set_crew(file_call, file_crew);
        break;
    case 4: 
            system("clear");
            print_duty_crew(file_call, file_crew);
        break;
    case 5: 
        system("clear");
        add_call(file_call,file_crew);
        break;
    case 6: 
        system("clear");
        print_call(file_call,file_crew);
        break;
    case 7: 
        system("clear");
        set_time(file_call, file_crew);
        break;
    default: return 0;
        break;
    }

    return 0;
}

int ask(char * file_call, char * file_crew) {

    /*Эта функция спрашивает пользователя, что делать дальше в конце каждой пользовательской(!) фукнции.
    То есть если у нас появятся чисто технические ф-и типа автоматического сохранения,
    то ask применять не надо. В прошлой лабе мне надоело писать одно и тоже в конце каждой функции,
    и я написала этот ask.*/

    cout << "Выберите дальнейшее действие:" << endl
         << "0 - вернуться в меню" << endl
         << "другое число - выйти" << endl;
    int choice;
    cin >> choice;
    if (choice == 0) {
        menu(file_call, file_crew);
    }
    return 0;
}
