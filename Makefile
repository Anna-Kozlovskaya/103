SRC =  crew.o  call.o  menu.o   main.o 

all: app all.h crew.h call.h

app: $(SRC)
	g++ $(SRC) -o app
crew.o: crew.cpp
	g++ -c -o crew.o crew.cpp


call.o: call.cpp
	g++ -c -o call.o call.cpp


menu.o: menu.cpp
	g++ -c -o menu.o menu.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -rf $(SRC)




