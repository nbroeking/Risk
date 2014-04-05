#  All Files
EX = gameMain GameApplication
CFLAGS = -g -Wall
#  Main target
all: $(EX)

#Generic Compile
#  Generic compile and link
%: %.cpp GameApplication.o gameMain.o
	g++ -o $@  $^ $(CFLAGS)

#  Delete unwanted files
clean:
	rm -f -r $(EX) *.o *.a *.dSYM

# Create Object Files
GameApplicaton.o: GameApplication.cpp
	g++ -c $(CFLAGS) $< $(LIBS)

gameMain.o: gameMain.cpp
	g++ -c $(CFLAGS) $< $(LIBS)
