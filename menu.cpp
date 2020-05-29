#include <iostream>
#include "all.h"

using namespace std;

int menu(char * file_call, char * file_crew) {

    //Думаю, что к меню дополнительные комментарии не нужны. Не в main, потому что его
    //засорять нехорошо.

    int choice;

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

    case 1: print_crew(file_call, file_crew);
        break;
    case 2: edit_crew(file_call,file_crew);
        break;
    case 3: set_crew(file_call, file_crew);
        break;
    case 4: print_duty_crew(file_call, file_crew);
        break;
    case 5: add_call(file_call,file_crew);
        break;
    case 6: print_call(file_call,file_crew);
        break;
    case 7: set_time(file_call, file_crew);
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
