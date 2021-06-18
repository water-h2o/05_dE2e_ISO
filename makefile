CC=g++
CPPFLAGS=-c -g -Wall -std=c++17 `root-config --cflags` -I/usr/include/eigen3/ -I./include -I/usr/include
LDFLAGS=`root-config --glibs` -L/usr/lib/x86_64-linux-gnu -lgsl -lgslcblas -lm -lstdc++fs
#SOURCES= ./src/main.cpp ./src/getFilesInDir.cpp 
OBJECTS=main.o dE2elec.o getFilesInDir.o decompressInput.o generalTools.o
EXECUTABLE=test

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) $(LDFLAGS) -o $@

generalTools.o: ./src/generalTools.cpp
	$(CC) ./src/generalTools.cpp $(CPPFLAGS) -o $@

decompressInput.o: ./src/decompressInput.cpp
	$(CC) ./src/decompressInput.cpp $(CPPFLAGS) -o $@

getFilesInDir.o: ./src/getFilesInDir.cpp
	$(CC) ./src/getFilesInDir.cpp $(CPPFLAGS) -o $@

dE2elec.o: ./src/dE2elec.cpp
	$(CC) ./src/dE2elec.cpp $(CPPFLAGS) -o $@

main.o: ./src/main.cpp
	$(CC) ./src/main.cpp $(CPPFLAGS) -o $@

clean:
	rm ./*~ ./*.o ./main
