CPPC?=g++
AR?=ar
OPTFLAGS?=-g3 -ggdb
CFLAGS= $(OPTFLAGS) -I include
LDFLAGS= -lpthread
OBJECTS=../obs/AttackEvent.o ../obs/CLEventDelegate.o ../obs/CommandHandler.o ../obs/DisplayEvent.o ../obs/EventMarshlingStrategy.o ../obs/GameApplication.o ../obs/GameHandler.o ../obs/GameMain.o ../obs/Gamestate.o ../obs/BasicFileDescriptor.o ../obs/NotificationPool.o ../obs/Socket.o ../obs/Thread.o ../obs/QuitEvent.o ../obs/RiskApplication.o
BINARY=../PlayRisk
all: $(OBJECTS)
	$(CPPC) -o $(BINARY) $(OBJECTS) $(LDFLAGS)

genmake:
	find . -name genmake.sh -exec {} \;

setup:
	mkdir -p obs/

../obs/AttackEvent.o: AttackEvent.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/CLEventDelegate.o: CLEventDelegate.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/CommandHandler.o: CommandHandler.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/DisplayEvent.o: DisplayEvent.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/EventMarshlingStrategy.o: EventMarshlingStrategy.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/GameApplication.o: GameApplication.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/GameHandler.o: GameHandler.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/GameMain.o: GameMain.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/Gamestate.o: Gamestate.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/BasicFileDescriptor.o: os_ss/BasicFileDescriptor.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/NotificationPool.o: os_ss/NotificationPool.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/Socket.o: os_ss/Socket.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/Thread.o: os_ss/Thread.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/QuitEvent.o: QuitEvent.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

../obs/RiskApplication.o: RiskApplication.cpp
	$(CPPC) $(CFLAGS) -o $@ -c $<

