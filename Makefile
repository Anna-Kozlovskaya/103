SRC =  crew.o  call.o  interface.o   main.o 

all: app interface.h crew.h call.h

app: $(SRC)
	g++ $(SRC) -o app
crew.o: crew.cpp
	g++ -c -o crew.o crew.cpp


call.o: call.cpp
	g++ -c -o call.o call.cpp


interface.o: interface.cpp
	g++ -c -o interface.o interface.cpp

main.o: main.cpp
	g++ -c -o main.o main.cpp

clean:
	rm -rf $(SRC)




