#include "all.h"
#include "crew.h"
#include "call.h"

/*Функция добавления экипажа*/
	int add_crew(char * file_call, char * file_crew){
		ifstream fin;
		fin.open(file_crew);
		if (!(fin.is_open()))
		{
			cout << "Ошибка! Не удалось открыть файл!!"<< endl;
		}
	
		int line_count=0;
		string str;

		while (getline(fin,str))	//подсчет количества строк в файле сrew 
		{
			line_count++;
		}

		fin.close();
		fin.open(file_crew);

		crew *crew_1 = new crew[line_count];
		crew crew_2;
		int a,b,c;
		for (int i = 0; i < line_count; i++) 
		{
        	fin >> crew_1[i];
    	}
		fin.close();

		//тут просто идет перезапись в файл с добавленным экипажем

		ofstream fout(file_crew,ios_base::trunc);
		cout << "Добавьте экипаж и информацию о нем: "<< endl;
		cin >> crew_2;
		for (int i = 0; i < line_count; i++) {
        		fout << crew_1[i];
    	}
		fout << crew_2;
    	
		fout.close();
		delete [] crew_1;
		ask(file_call, file_crew);
    	return 0;
	}
