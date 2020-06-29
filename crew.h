#ifndef CREW_H
#define CREW_H
#include <string>
#include <iostream>
#include "call.h"
using namespace std;
/*!
	\brief  Класс для работы с базой данных экипажей
*/
class crew
{
friend class call;
private:
    string doctor;///< фамилия врача
    string paramedic;///< фамилия фельдшера
    string driver;///< фамилия водителя
    int duty_status;///< статус дежурства: число часов на дежурстве
    int call_status;///< статус вызова: когда освободится с текущего вызова
    bool duty_bool;///< статус дежураства(на дежурстве/не на дежурстве)		
    /*!
			\brief Перегрузка операторов вывода
			\param os Поток данных
			\param crew Данные вызовов
	*/
    friend ostream& operator<< (ostream& os, const crew& crew);
    /*!
		   \brief Перегрузка операторов ввода
		   \param is Поток данных
		   \param crew Данные вызовов
   */
    friend istream& operator>> (istream& is, crew& crew);

    
    
   
    
    
   // friend int add_call(char * file_call, char * file_crew);
    //friend int set_time(char * file_call, char * file_crew);
    
public :
	void print_crew(char * file_call, char * file_crew);
	int add_crew(char * file_call, char * file_crew);
	int deletes_crew(char * file_call, char * file_crew);
	int set_crew(char * file_call, char * file_crew);
	int print_duty_crew(char * file_call, char * file_crew);
	int search(char * file_call, char * file_crew);

};

#endif // CREW_H
