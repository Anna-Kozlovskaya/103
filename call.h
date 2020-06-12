#ifndef CALL_H
#define CALL_H
#include <string>
#include <iostream>

using namespace std;
/*!
	\brief  Класс для работы с вызовами 
*/
class call
{
private:
    string address; ///< адрес (улица.номер дома.номер квартиры)
    int time_to; ///< время до пациента (число часов)
    string need_hosp; ///< необходимость госпитализации (есть, нет)
    int time_back; ///< время до больницы, если осуществляется госпиализация (число часов)
    string assigned_crew; ///< назначенный экипаж (фамилия врача)
    string status; ///< статус вызова (выехали, выполнена госпитализация, завершен)
    /*!
			\brief Перегрузка операторов вывода
			\param os Поток данных
			\param call Данные вызовов
	*/
    friend ostream& operator<< (ostream& os, const call& call);
    /*!
		   \brief Перегрузка операторов ввода
		   \param is Поток данных
		   \param call Данные вызовов
   */
    friend istream& operator>> (istream& is, call& call);

    friend int print_call(char * file_call, char * file_crew);
    friend int add_call(char * file_call, char * file_crew);
    friend int set_time(char * file_call, char * file_crew);
    friend int print_duty_crew(char * file_call, char * file_crew);
    friend int set_crew(char * file_call, char * file_crew);
};

#endif // CALL_H
