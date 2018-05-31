PROGRAM_NAME = MedIF
COMPILER = g++
COMPFLAGS = -ansi -pedantic -Wall -std=c++11

COMPPART = $(COMPILER) $(COMPFLAGS) -c
COMPFINAL = $(COMPILER) $(COMPFLAGS) -o

$(PROGRAM_NAME): main.cpp Analyse.o Initialisation.o Maladie.o Medecin.o
	$(COMPFINAL) $(PROGRAM_NAME) main.cpp Analyse.o Initialisation.o Maladie.o Medecin.o

Analyse.o: Analyse.cpp Analyse.h
	$(COMPPART) Analyse.cpp
	

Initialisation.o :Initialisation.cpp Initialisation.h 
	$(COMPPART) Initialisation.cpp

Maladie.o :Maladie.cpp Maladie.h 
	$(COMPPART) Maladie.cpp

Medecin.o :Medecin.cpp Medecin.h 
	$(COMPPART) Medecin.cpp

.PHONY : clean
clean:
	rm *.o
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)