game: GameCharacter.o game.o
	c++ -o game GameCharacter.o game.o

GameCharacter.o: GameCharacter.cpp
	c++ -c GameCharacter.cpp

game.o: game.cpp
	c++ -c game.cpp

clean:
	rm *.o game


