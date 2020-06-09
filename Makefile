SRC = add_call.o call.o crew.o edit_crew.o menu.o print_call.o print_crew.o print_duty_crew.o set_crew.o set_time.o main.o search.o

all: app all.h crew.h call.h

app: $(SRC)
	g++ $(SRC) -o app

call.o: call.cpp
	g++ -c -o call.o call.cpp

crew.o: crew.cpp
	g++ -c -o crew.o crew.cpp

add_call.o: add_call.cpp
	g++ -c -o add_call.o add_call.cpp

edit_crew.o: edit_crew.cpp
	g++ -c -o edit_crew.o edit_crew.cpp

print_crew.o: print_crew.cpp
	g++ -c -o print_crew.o print_crew.cpp

print_call.o: print_call.cpp
	g++ -c -o print_call.o print_call.cpp

print_duty_crew.o: print_duty_crew.cpp
	g++ -c -o print_duty_crew.o print_duty_crew.cpp

set_crew.o: set_crew.cpp
	g++ -c -o set_crew.o set_crew.cpp

set_time.o: set_time.cpp
	g++ -c -o set_time.o set_time.cpp

search.o: search.cpp
	g++ -c -o search.o search.cpp

menu.o: menu.cpp
	g++ -c -o menu.o menu.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -rf $(SRC)




