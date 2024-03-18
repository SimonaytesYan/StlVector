FLAGS    = -O2
COMPILER = g++ $(FLAGS)

SRC = Src/
BIN = Bin/
ELF_FILE = $(BIN)run

compile: create_folders
	$(COMPILER) $(SRC)main.cpp -o $(ELF_FILE)

run: compile
	./$(ELF_FILE)

create_folders:
	-mkdir $(BIN)

clean:
	rm -r $(BIN)
