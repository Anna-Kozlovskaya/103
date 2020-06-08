#include <iostream>
#include "all.h"
#include <cstdlib>

using namespace std;

int menu(char * file_call, char * file_crew) {

    //Думаю, что к меню дополнительные комментарии не нужны. Не в main, потому что его
    //засорять нехорошо.
    for(;;){
        int choice,choice_1;
        system("clear");//Просто для более красивого меню(что-бы всё не было одно под другим)
        cout << "Выберите действие:" << endl;
        cout << "1 - вывести базу экипажей" << endl;
        cout << "2 - редактировать базу экипажей" << endl;
        cout << "3 - назначить дежурные экипажи" << endl;
        cout << "4 - вывести информацию о дежурных экипажах" << endl;
        cout << "5 - принять вызов" << endl;
        cout << "6 - вывести историю вызовов" << endl;
        cout << "7 - задать время" << endl;
        cout << "8 - поиск экипажа" << endl;
        cout << "9 - завершить работу" << endl;

        cin >> choice;
        if(choice<1 || choice>8)
				cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;

    	while(choice==1){ 
            system("clear");   
            print_crew(file_call, file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
	while(choice==2){  
            system("clear");
			cout << "Выберите действие:" << endl;
    		cout << "1 - добавить экипаж в базу экипажей" << endl;
    		cout << "2 - удалить экипаж из базы экипажей" << endl;
			cout << "0 - Вернуться в меню" << endl;
			cin >> choice_1;
			if(choice_1<0 || choice_1>2)
				cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
            
			    while(choice_1==1){ 
            		    system("clear");   
            		    add_crew(file_call, file_crew);
					    cout << "0-Вернуться в меню "<<endl;
					    cin >>choice_1;
					    if(choice_1<0 || choice_1>0)
						        cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
			    }
			    while(choice_1==2){
					    system("clear");   
            		    deletes_crew(file_call, file_crew);
					    cout << "0-Вернуться в меню "<<endl;
					    cin >>choice_1;
					    if(choice_1<0 || choice_1>0)
						        cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
			    }
			while(choice_1==0){
				menu(file_call,file_crew);
			    }
			}
        while(choice==3){ 
            system("clear");   
            set_crew(file_call, file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
	while(choice==4){ 
            system("clear");   
            print_duty_crew(file_call, file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
        while(choice==5){ 
            system("clear");   
            add_call(file_call,file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
        while(choice==6){ 
            system("clear");   
            print_call(file_call,file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
         while(choice==7){ 
            system("clear");   
            set_time(file_call, file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
        while(choice==8){ 
            system("clear");   
            search(file_call, file_crew);
			cout << "0 - Вернуться в меню"<<endl;
			cin >> choice ;
				if(choice<0 || choice>0)
					cout << "Введите нужную цифру соответствующую пункту!!!!!" << endl;
		}
	while(choice==9){
		return 0;
	}
    }
	
}
