CXX=g++
CXXFLAGS = -std=c++11 -Wall -Wextra -pedantic -g

skipbo: main.o Pile.o Card.o DrawPile.o Player.o BuildPile.o Hand.o FaceUpPile.o SkipBoGame.o
	$(CXX) main.o Pile.o Card.o DrawPile.o Player.o Hand.o FaceUpPile.o BuildPile.o SkipBoGame.o -o skipbo

Pile.o: Pile.cpp Pile.h Card.h
	$(CXX) $(CXXFLAGS) -c Pile.cpp

Card.o: Card.cpp Card.h
	$(CXX) $(CXXFLAGS) -c Card.cpp

DrawPile.o: DrawPile.cpp DrawPile.h Pile.h Card.h
	$(CXX) $(CXXFLAGS) -c DrawPile.cpp

Player.o: Player.cpp Player.h PlayPile.h Hand.h
	$(CXX) $(CXXFLAGS) -c Player.cpp

BuildPile.o: BuildPile.cpp BuildPile.h Card.h FaceUpPile.h
	$(CXX) $(CXXFLAGS) -c BuildPile.cpp

Hand.o: Hand.cpp Hand.h Card.h Pile.h
	$(CXX) $(CXXFLAGS) -c Hand.cpp

FaceUpPile.o: FaceUpPile.cpp FaceUpPile.h Pile.h Card.h
	$(CXX) $(CXXFLAGS) -c FaceUpPile.cpp

SkipBoGame.o: SkipBoGame.cpp SkipBoGame.h Card.h Player.h BuildPile.h DrawPile.h PlayPile.h
	$(CXX) $(CXXFLAGS) -c SkipBoGame.cpp

main.o: main.cpp DrawPile.h SkipBoGame.h Pile.h Hand.h Card.h
	$(CXX) $(CXXFLAGS) -c main.cpp
clean:
	rm *.o skipbo
