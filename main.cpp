#include <iostream>
#include "interface.h"

using namespace std;

int main(int argc, char* argv[])
{
    if (argc < 3) {
            cout << "Ошибка. Не введены имена файлов."<< endl;
            return 0;
        }

        interface::menu(argv[1], argv[2]);
        cout << "Завершено." << endl;
    return 0;
}
