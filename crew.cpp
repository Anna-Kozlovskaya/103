#include<fstream>
#include<iostream>
#include<string>
#include "interface.h"
#include "crew.h"
using namespace std;

ostream& operator<< (ostream& os, const crew& crew) {
    os << crew.doctor << " " << crew.paramedic << " " <<
          crew.driver << " " << crew.duty_status << " " << crew.call_status << " " << crew.duty_bool << endl;
    return os;
}

istream& operator>> (istream& is, crew& crew) {
    is >> crew.doctor >> crew.paramedic >> crew.driver >> crew.duty_status >> crew.call_status >> crew.duty_bool;
    return is;
}
void crew::print_crew(char * file_call, char * file_crew)
{
	ifstream fin;
	fin.open(file_crew);
	if (!(fin.is_open()))
	{
		cout << "Error file not open!!"<< endl;
	}
	int line_count=0;
	string str;
	while (getline(fin,str))    //подсчет количества строк в файле сrew 
	{
		line_count++;
	}
	fin.close();
	fin.open(file_crew);
	crew *crew_1 = new crew[line_count];
			//считываем оставшиеся числа в файле,чтобы выводились только фамилии							
	for (int i = 0; i < line_count; i++) 
    	{
        	fin >> crew_1[i];
		cout << " Экипаж № " << i+1 <<endl;
        	cout << "Доктор   : " << crew_1[i].doctor << endl << "Санитар  : " << crew_1[i].paramedic << endl << "Водитель : " << crew_1[i].driver << endl;
		cout << endl;
    	}
	fin.close();
	delete [] crew_1;   
}
int crew::add_crew(char * file_call, char * file_crew)
{
	ifstream fin;
	fin.open(file_crew);
	crew crew_add;
        fstream add;
    	add.open(file_crew, ios::app);
        cout<<"Введите данные об экипаже :"<<endl;
	cout<<"Врач : "<<endl;
    	cin>> crew_add.doctor;
	cout<<"Санитар : "<<endl;
	cin>>crew_add.paramedic;
	cout<<"Водитель : "<<endl;
	cin>>crew_add.driver;
        crew_add.duty_status=0;
        crew_add.call_status=0;
        crew_add.duty_bool=false;
        add<<crew_add;
	add.close();
    	return 0;

}
int crew::deletes_crew(char * file_call, char * file_crew)
{
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
		
	cout << "Введите фамилии членов экипажа, который хотите удалить :"<< endl;
	cout<<"Врач : " <<endl;
	cin >> crew_2.doctor;
	cout<<"Санитар : "<<endl;
	cin>> crew_2.paramedic;
	cout<<"Водитель :"<<endl;
	cin>> crew_2.driver;

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

int crew::set_crew(char * file_call, char * file_crew)
{
	int n1,n2,N,i;
	N=0;     
        fstream set;
	set.open(file_crew,ios::in);
    	string str;
	while (getline(set,str))    //подсчет количества строк в файле сrew 
	{
        	N++;
	}
	set.close();
	set.open(file_crew,ios::in);
	crew *set_crew = new crew[N];
			//считываем оставшиеся числа в файле,чтобы выводились только фамилии							
	for ( i = 0; i <N; i++) 
    	{
        	set >> set_crew[i];
        	cout<<"Экипаж №"<<i+1<<endl;
        	cout <<"Доктор : "<< set_crew[i].doctor << " Санитар : " << set_crew[i].paramedic << " Водитель : " << set_crew[i].driver << endl;
    	}
	set.close();
    	cout<<"Выберите два экипажа на дежурство"<<endl;
    	cin>>n1;
    	cin>>n2;   
   
    	while((n1 == n2) || ((n1 < 1)||(n1 > N)) || ((n2 < 1)||(n2 > N))){
               	cout<<"Экипажи выбранны некорректно, повторите попытку"<<endl;
       		cin>>n1;
        	cin>>n2;   
   
    	}
	ofstream fout(file_crew,ios_base::trunc);
	for ( i = 0; i < N; i++) 
    	{
        	if((i + 1) == n1)
				set_crew[i].duty_bool=true;
		if((i + 1) == n2)
				set_crew[i].duty_bool=true;
        	fout << set_crew[i];
    	}
     
    	fout.close();
    	delete [] set_crew;
	return 0;

}


int crew::print_duty_crew(char * file_call, char * file_crew)
{
ifstream fin;
	fin.open(file_crew);
	if (!(fin.is_open()))
	{
		cout << "Error file not open!!"<< endl;
	}
	int line_count=0;
	string str;
	while (getline(fin,str))    //подсчет количества строк в файле сrew 
	{
		line_count++;
	}
	fin.close();
	fin.open(file_crew);
	crew *crew_1 = new crew[line_count];
						
	for (int i = 0; i < line_count; i++) 
    	{
        	fin >> crew_1[i];
		if (crew_1[i].duty_bool == true){
			cout << "Экипаж № "<< i+1 << endl;
        		cout <<"Доктор :" << crew_1[i].doctor << " Санитар : " << crew_1[i].paramedic << " Водитель : " << crew_1[i].driver <<" Часов на дежурстве : "<< crew_1[i].duty_status<<" Освободится с вызова через : "<<crew_1[i].call_status<< endl;
		}
    	}
	fin.close();
	delete [] crew_1;
        return 0;
}

int crew::search(char * file_call, char * file_crew)
{
	ifstream fin;
	fin.open(file_crew);
	if (!(fin.is_open()))
	{
		cout << "Ошибка! Не удалось открыть файл!!"<< endl;
	}
	int line_count=0;
	string str;
	while (getline(fin,str))    //подсчет количества строк в файле сrew 
	{
		line_count++;
	}
	fin.close();
	fin.open(file_crew);

	crew crew_2;
	crew crew_3;
	
	cout << "Введите экипаж который хотите найти: "<< endl;
	cin >> crew_2.doctor >> crew_2.paramedic >> crew_2.driver;

	for (int i = 0; i < line_count ; i++) {
		fin >> crew_3;
			if ((crew_3.doctor == crew_2.doctor) && (crew_3.paramedic == crew_2.paramedic) && (crew_3.driver == crew_2.driver)){
				cout << "Экипаж найден :" << endl;	
				cout << crew_3;
			}	
			
    	}
	fin.close();	
	return 0;
}






