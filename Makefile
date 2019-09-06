SOURCES = BSFunctions.cpp BSDeck.cpp BSCard.cpp BSPlayer.cpp BSMain.cpp
HEADERS = BSFunctions.hpp BSDeck.hpp BSCard.hpp BSPlayer.hpp
OBJECTS = $(SOURCES:.c=.o)
CXX = g++
CXXFLAGS = -g -std=c++14

%.o: %.cpp
	$(CXX) -c $(CXXFLAGS) $<

BSFunctions.o: BSFunctions.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

BSDeck.o: BSDeck.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

BSCard.o: BSCard.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

BSPlayer.o: BSPlayer.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

BSMain.o: BSMain.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

bs.exe: BSFunctions.o BSDeck.o BSCard.o BSPlayer.o BSMain.o
	$(CXX) -o $@ $^

testRot13cipher.exe: testRot13cipher.o rot13cipher.o ioutils.o
	$(CXX) -o $@ $^

clean: 
	$(RM) *.o *.exe
