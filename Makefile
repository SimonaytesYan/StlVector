FLAGS    = -O2
COMPILER = g++ $(FLAGS)

SRC = Src/
BIN = Bin/
ELF_FILE = $(BIN)run

compile:
	$(COMPILER) $(SRC)main.cpp -o $(ELF_FILE)

run: compile
	./$(ELF_FILE)
	
