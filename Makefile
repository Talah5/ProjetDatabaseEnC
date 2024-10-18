# Nom de l'exécutable
TARGET = mydb

# Options de compilation
CC = gcc
CFLAGS = -Wall -Wextra -g -std=c11 -Iinclude

# Liste des fichiers sources
SRCS = src/main.c src/table.c

# Fichiers objets générés
OBJS = $(SRCS:.c=.o)

# Règle par défaut, construction de l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compilation des fichiers .c en fichiers .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyage des fichiers objets et de l'exécutable
clean:
	rm -f $(OBJS) $(TARGET)

