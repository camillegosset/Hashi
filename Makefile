CXX=g++
CXXFLAGS=-Wall -std=c++11

SRC=./src
BUILD=./build
INCLUDE=./inc

OBJECTS=$(BUILD)/main.o $(BUILD)/Grille.o $(BUILD)/Ile.o $(BUILD)/IleOuPont.o $(BUILD)/Pont.o

# Construction du programme final
$(BUILD)/Hashi: $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Construction de chaque fichier source
$(OBJECTS): $(BUILD)/%.o: $(SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# Nettoyage du dossier source
clean:
	rm -r $(BUILD)/*
