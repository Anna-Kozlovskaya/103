#ifndef ALL_H
#define ALL_H


//Здесь объявлены все функции.
/*!
	\brief Функция меню
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
		
*/
int menu(char * file_call, char * file_crew);
/*!
	\brief Функция вывода базы данных экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int print_crew(char * file_call, char * file_crew);
/*!
	\brief Функция вывода истории вызовов 
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int print_call(char * file_call, char * file_crew);
/*!
	\brief Функция добавления экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int add_crew(char * file_call, char * file_crew); 
/*!
	\brief Функция удаления экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int deletes_crew(char * file_call, char * file_crew);
/*!
	\brief Функция назначения дежурных экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int set_crew(char * file_call, char * file_crew); 
/*!
	\brief Функция вывода дежурных экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int print_duty_crew(char * file_call, char * file_crew);
/*!
	\brief Функция принятия вызовов
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int add_call(char * file_call, char * file_crew);
/*!
	\brief Функция времени
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
	\return 0 если функция выполнена
*/
int set_time(char * file_call, char * file_crew);
/*!
	\brief Функция поиска экипажей
	\param file_call Текстовый документ с данными о вызовах
	\param file_crew Текстовый документ с данными о экипажах
  \return 0 если функция выполнена
*/
int search(char * file_call, char * file_crew);
#endif // ALL_H
