#include <iostream>
#include <fstream>
#include "interface.h"
#include "crew.h"
#include "call.h"
using namespace std;

ostream& operator<< (ostream& os, const call& call) {

    os << call.address << " " << call.time_to << " "
       << call.need_hosp << " " << call.time_back << " " << call.assigned_crew << " " << call.status << endl;
    return os;
}
istream& operator>> (istream& is, call& call) {
    is >> call.address >> call.time_to >> call.need_hosp >>
          call.time_back >> call.assigned_crew >> call.status;
    return is;
}

int call::add_call(char * file_call, char * file_crew)
{
        int N,i;
    	N=0;	
    	call add_call;
    	fstream add;
	add.open(file_call,ios::app);

	cout<<"Заполните информацию о вызове:"<<endl;
	cout<<"Адрес : "<<endl;
	cin>>add_call.address;
	cout<<"Время пути до адреса :"<<endl;
	cin>>add_call.time_to;
	cout<<"Надобность госпитализации да/нет :"<<endl;
	cin>>add_call.need_hosp;
	if(add_call.need_hosp=="да")
	{
	    cout<<"Время пути обратно : "<<endl;
	    cin>>add_call.time_back;
	}
	else
	add_call.time_back=0;
	fstream crews;
	crews.open(file_crew,ios::in);
	if (!crews)
	{
		cout << "Error file not open!!"<< endl;
	}
	
	string str;
	while (getline(crews,str))    //подсчет количества строк в файле сrew 
	{
		N++;
	}
	crews.close();
	crew *crew_1 = new crew[N];
	crews.open(file_crew,ios::in);
	int Ncrew;
	int Ncrew_1=-1;
	int Ncrew_2=-1;
	cout<<"Выберите экипаж, который хотите назначить на вызов :"<<endl;
						
	for (int i = 0; i < N; i++) 
    	{
        	crews >> crew_1[i];
		if (crew_1[i].duty_bool == true){

			cout << "Экипаж № "<< i+1 << endl;
        		cout << crew_1[i].doctor << " " << crew_1[i].paramedic << " " << crew_1[i].driver << endl;
			if (Ncrew_1<0)
				Ncrew_1=i;
			else 
				Ncrew_2=i;
		}
    	}
	crews.close();
	cin>>Ncrew;
	
	switch (Ncrew)
	{
		case 1:
		{
			if ((crew_1[Ncrew_1].duty_status+add_call.time_to+add_call.time_back)>=24)
			{
				cout<<"Первышение возможных часов на смене. Назначьте новые экипажи."<<endl;
				return 0;
			}
			add_call.assigned_crew=crew_1[Ncrew_1].doctor;
			crew_1[Ncrew_1].call_status += add_call.time_to + add_call.time_back;
			add_call.status="выехали";
			break;
		}
		case 2:
		{
			if ((crew_1[Ncrew_2].duty_status+add_call.time_to+add_call.time_back)>=24)
			{
				cout<<"Первышение возможных часов на смене. Назначьте новые экипажи."<<endl;
				return 0;
			}
			add_call.assigned_crew=crew_1[Ncrew_2].doctor;
			crew_1[Ncrew_2].call_status += add_call.time_to + add_call.time_back;
			add_call.status="выехали";
			break;
		}
		default :
		{
			cout<<"Некорректный ввод."<<endl;
			return 0;
		}

	}
		
  	add<<add_call;
   	add.close();
	crews.open(file_crew,ios::trunc | ios::out);
	for (i = 0; i < N ; i++) {
	    	crews <<  crew_1[i];
   	 }
	crews.close();
  	delete [] crew_1;

	return 0;
}

int call::print_call(char * file_call, char * file_crew)
{
	int N,i;
	N=0;
	call *call_1;
	fstream print_call;
	print_call.open(file_call,ios::in);
	if (!print_call)
	{
		cout << "Error file not open!!"<< endl;
	}
	
	string str;
	while (getline(print_call,str))   
	{
		N++;
	}
	print_call.close();
	call_1 = new call[N];
	print_call.open(file_call,ios::in);
	
										
	for (i = 0; i < N; i++) 
    	{
        	print_call >> call_1[i];
        	cout <<"Адрес : "<< call_1[i].address << endl <<"Время до адреса : "<< call_1[i].time_to << endl <<"Необходимость госпитализации : "<<call_1[i].need_hosp << endl <<"Время Обратно : "<< call_1[i].time_back << endl <<"Фамилия врача : "<<call_1[i].assigned_crew << endl << "Статус вызова : "<<call_1[i].status <<endl;
		cout<<endl;
    	}
	print_call.close();
	delete [] call_1;
        return 0;

}

int call::set_time(char * file_call, char * file_crew)
{
int Ncrew, Ncall, i, j;
    Ncrew = 0; Ncall = 0;

    int hour;

    cout << "Сколько часов прошло?" << endl;
    cin >> hour;

    fstream fcrew; fstream fcall;
    fcrew.open(file_crew,ios::in);
    fcall.open(file_call,ios::in);
    string str;

    while (getline(fcrew,str)) {
        Ncrew++;
    }
    fcrew.close();

    while (getline(fcall,str)) {
        Ncall++;
    }
    fcall.close();

    fcrew.open(file_crew,ios::in);
    fcall.open(file_call,ios::in);
    crew *crews = new crew[Ncrew];
    call *calls = new call[Ncall];

    for (i = 0; i < Ncrew; i++) {
        fcrew >> crews[i];

        if (crews[i].duty_bool == true) {
            //тут проверяем, закончилась ли смена
            crews[i].duty_status = crews[i].duty_status + hour;
            if (crews[i].duty_status >= 24) {
                cout << "У экипажа доктора "<< crews[i].doctor << " закончилась смена." << endl;
                crews[i].duty_status = 0;
                crews[i].call_status = 0;
                crews[i].duty_bool = false;
            }
            //теперь нужно изменить статус соотвествующего вызова
            crews[i].call_status = crews[i].call_status - hour;
            if (crews[i].call_status <= 0) {
                for (j = 0; j < Ncall; j++) {
                    crews[i].call_status = 0;
                    fcall >> calls[j];
                    if (calls[j].assigned_crew == crews[i].doctor) {
                        calls[j].status = "Завершен";
                    }
                }
            }
        }

    }
    fcrew.close();
    fcall.close();

    fcall.open(file_call,ios::trunc);
    fcall.close();
    fcrew.open(file_crew,ios::trunc);
    fcrew.close();

    //записываем изменения
    fcall.open(file_call, ios::out);
    for ( i = 0; i < Ncall ; i++) {
        fcall << calls[i];
    }
    fcall.close();
    delete [] calls;

    fcrew.open(file_crew, ios::out);
    for (i = 0; i < Ncrew ; i++) {
        fcrew << crews[i];
    }
    fcrew.close();
    delete [] crews;

    return 0;
}


