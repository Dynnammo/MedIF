PROGRAM_NAME = MedIF
COMPILER = g++
COMPFLAGS = -ansi -pedantic -Wall -std=c++14 -Wno-reorder

COMPPART = $(COMPILER) $(COMPFLAGS) -c
COMPFINAL = $(COMPILER) $(COMPFLAGS) -o
all: $(PROGRAM_NAME) clean

$(PROGRAM_NAME): main.cpp Analyse.o Initialisation.o Maladie.o Medecin.o Attribut_intervalle.o Attribut_enumeration.o Attribut.o Test.o Empreinte.o Menu.o
	$(COMPFINAL) $(PROGRAM_NAME) main.cpp Analyse.o Initialisation.o Maladie.o Medecin.o Attribut_intervalle.o Attribut_enumeration.o Attribut.o Test.o Empreinte.o Menu.o

Analyse.o: Analyse.cpp Analyse.h
	$(COMPPART) Analyse.cpp

Test.o : Test.cpp Test.h
	$(COMPPART) Test.cpp

Initialisation.o :Initialisation.cpp Initialisation.h 
	$(COMPPART) Initialisation.cpp

Maladie.o :Maladie.cpp Maladie.h 
	$(COMPPART) Maladie.cpp

Medecin.o :Medecin.cpp Medecin.h 
	$(COMPPART) Medecin.cpp

Attribut.o : Attribut.cpp Attribut.h 
	$(COMPPART) Attribut.cpp	

Empreinte.o : Empreinte.cpp Empreinte.h
	$(COMPPART) Empreinte.cpp	

	
Attribut_intervalle.o : Attribut_intervalle.cpp Attribut_intervalle.h 
	$(COMPPART) Attribut_intervalle.cpp

Attribut_enumeration.o :Attribut_enumeration.cpp Attribut_enumeration.h 
	$(COMPPART) Attribut_enumeration.cpp

Menu.o :Menu.cpp Menu.h 
	$(COMPPART) Menu.cpp

.PHONY : clean
clean:
	rm *.o
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)
