# Set the compiler to use as g++
CC = g++
CFLAGS = -Wall -Wextra -pedantic 
# LDFLAGS = -fsanitize=address

# Define the list of object files to create
OBJS = main.o Zoo.o Animal.o Enclosure.o  Zookeeper.o

# Define the target to run the program
# The target depends on the 'prog' target, which is responsible for creating the program executable
run: prog
	./prog

# Define the target to create the program executable
# The target depends on the object files defined in the 'OBJS' variable
prog: $(OBJS)
	$(CC) $(OBJS) -o prog

# MAIN
# Define the target to compile the main source file
# The target depends on the 'main.cpp' source file
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

# Animal
Animal.o: Animal.cpp Animal.hpp
	$(CC) $(CFLAGS) -c Animal.cpp

# Enclosure
Enclosure.o: Enclosure.cpp Enclosure.hpp
	$(CC) $(CFLAGS) -c Enclosure.cpp

# Zoo
Zoo.o: Zoo.cpp Zoo.hpp
	$(CC) $(CFLAGS) -c Zoo.cpp

# Zookeeper
Zookeeper.o: Zookeeper.cpp Zookeeper.hpp
	$(CC) $(CFLAGS) -c Zookeeper.cpp

clean:
	del $(OBJS) prog.exe
