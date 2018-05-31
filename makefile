PROGRAM_NAME = MedIF
COMPILER = g++
COMPFLAGS = -ansi -pedantic -Wall -std=c++11

COMPPART = $(COMPILER) $(COMPFLAGS) -c
COMPFINAL = $(COMPILER) $(COMPFLAGS) -o

$(PROGRAM_NAME): main.cpp Analyse.o Empreinte.o Initialisation.o Maladie.o Medecin.o Patient.o Personne.o
	$(COMPFINAL) $(PROGRAM_NAME) main.cpp Analyse.o Empreinte.o Initialisation.o Maladie.o Medecin.o Patient.o Personne.o

Analyse.o: Analyse.cpp Analyse.h
	$(COMPPART) Analyse.cpp

Empreinte.o : Empreinte.h 
	

Initialisation.o :Initialisation.cpp Initialisation.h 
	$(COMPPART) Initialisation.cpp

Maladie.o :Maladie.cpp Maladie.h 
	$(COMPPART) Maladie.cpp

Medecin.o :Medecin.cpp Medecin.h 
	$(COMPPART) Medecin.cpp

Patient.o : Patient.h 

Personne.o :Personne.cpp Personne.h 
	$(COMPPART) Personne.cpp

.PHONY : clean
clean:
	rm *.o
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)