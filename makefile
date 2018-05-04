PROGRAM_NAME = MedIF
COMPILER = g++
COMPFLAGS = -ansi -pedantic -Wall -std=c++11

COMPPART = $(COMPILER) $(COMPFLAGS) -c
COMPFINAL = $(COMPILER) $(COMPFLAGS) -o

$(PROGRAM_NAME): mainAnalyse.cpp Analyse.o 
	$(COMPFINAL) $(PROGRAM_NAME) mainAnalyse.cpp Analyse.o

Types.o: Analyse.cpp Analyse.h
	$(COMPPART) Analyse.cpp

.PHONY : clean
clean:
	rm *.o
run: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)