#include <iostream>
#include <fstream>
#include "all.h"
#include "crew.h"
#include "call.h"
using namespace std;


/*Надо эти функции еще в заголовочный добавить и в меню на втором пункте, чтобы работало,и еще булевую переменную в классе*/
/*Функция добавления экипажа*/
	int add_crew(char * file_call, char * file_crew){
		ifstream fin;
		fin.open(file_crew);
		crew crew_add;
        fstream add;
    	add.open(file_crew, ios::app);
        cout<<"Введите данные об экипаже :"<<endl;
    	cin>> crew_add.doctor>>crew_add.paramedic>>crew_add.driver;
        crew_add.duty_status=0;
        crew_add.call_status=0;
        crew_add.duty_bool=false;
        
        add<<crew_add;
		add.close();
    		return 0;
	}

	/*Функция удаления экипажа*/

	int deletes_crew(char * file_call, char * file_crew){
		ifstream fin;
		fin.open(file_crew);
		if (!(fin.is_open()))
		{
			cout << "Ошибка! Не удалось открыть файл!!"<< endl;
		}

		int line_count=0;
		string str;
		while (getline(fin,str))	 
		{
			line_count++;		//снова подсчет количества строк в файле сrew 
		}
		fin.close();
		fin.open(file_crew);

		crew *crew_1 = new crew[line_count];
		crew crew_2;
		crew crew_3;
		
		/*Поиск экипажа по 3 фамилиям*/
		
		cout << "Введите экипаж который хотите удалить :"<< endl;
		cin >> crew_2.doctor >> crew_2.paramedic >> crew_2.driver;
	
		/*записываем в класс все остальные экипажи кроме экипажа который мы ходим удалить из базы*/

		int j = 0,number_line = 0;		/*number_line считает кол-во экипажей,если файл будет удален
							он измениться на (number_line-1)*/
		
		number_line = line_count;		
		
		for (int i = 0; i < line_count; i++) {
			fin >> crew_3;
			if (!(crew_3.doctor == crew_2.doctor) || (!(crew_3.paramedic == crew_2.paramedic)) || (!(crew_3.driver == crew_2.driver))){	
				crew_1[j] = crew_3;
				j++;
				number_line = j;
			}
			
    		}
		
		fin.close();
		/*Открываем пустой файл и перезаписываем все туда*/
		
		ofstream fout(file_crew,ios_base::trunc);
		for (int i = 0; i < number_line ; i++) {
		
        		fout <<  crew_1[i];
   	 	}
		fout.close();
		delete [] crew_1;
		
    		return 0;	
	}
