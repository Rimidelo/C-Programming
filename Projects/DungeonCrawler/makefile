cc = g++
OBJS = main.o Character.o Item.o Monster.o Dungeon.o Room.o Game.o Warrior.h Thief.h Mage.h Potion.h Sword.h Shield.h

run: prog
	./prog

prog: $(OBJS)
	$(cc) $(OBJS) -o prog

main.o: main.cpp
	$(cc) -c main.cpp

Character.o: Character.cpp Character.h
	$(cc) -c Character.cpp

Item.o: Item.cpp Item.h
	$(cc) -c Item.cpp

Monster.o: Monster.cpp Monster.h Character.h
	$(cc) -c Monster.cpp

Dungeon.o: Dungeon.cpp Dungeon.h Room.h
	$(cc) -c Dungeon.cpp

Room.o: Room.cpp Room.h Character.h Monster.h Item.h
	$(cc) -c Room.cpp

Game.o: Game.cpp Game.h Dungeon.h Character.h
	$(cc) -c Game.cpp

clean:
	rm -f $(OBJS) prog
