CC = g++ 
LINKS = -I../include
FLAGS = -lncurses 
OBJECTS = src/character.o src/frame.o src/icerunner.o src/screen.o 
OUTPUT = bin/icerunner

main: $(OBJECTS)
	$(CC) $(OBJECTS) $(FLAGS) $(LINKS) -o $(OUTPUT)
character.o:
	g++ $(FLAGS) $(LINKS) -c character.cpp
frame.o:
	g++ $(FLAGS) $(LINKS) -c frame.cpp
icerunner.o:
	g++ $(FLAGS) $(LINKS) -c icerunner.cpp
screen.o:
	g++ $(FLAGS) $(LINKS) -c screen.cpp
.PHONY : clean
clean :
	-rm -f $(OBJECTS) $(OUTPUT)