# Compilateur
CXX = g++

# Options de compilation
CXXFLAGS = -Wall -Wextra -std=c++11

# Fichiers sources
SRCS = livres.cpp gestion_livres.cpp

# Fichiers objets (générés à partir des sources)
OBJS = $(SRCS:.cpp=.o)

# Nom de l'exécutable
TARGET = gestion_livres

# Règle par défaut
all: $(TARGET)

# Règle pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Règle pour générer les fichiers objets
%.o: %.cpp livres.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Nettoyage des fichiers générés
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (ne correspondent pas à des fichiers)
.PHONY: all clean