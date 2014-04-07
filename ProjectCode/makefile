#  All Files
EX = gameMain.cpp
FILES = GameApplication.o RiskApplication.o
CFLAGS = -g -Wall
#  Main target
all: GameApplication.o RiskApplication.o
	g++ $(CFLAGS) $(EX) $(FILES) -o playRisk

#  Delete unwanted files
clean:
	rm -f -r playRisk *.o *.a *.dSYM

# Create Object Files
GameApplicaton.o: GameApplication.cpp
	g++ -c $(CFLAGS) $<

RiskApplication.o: RiskApplication.cpp
	g++ -c $(CFLAGS) $<
