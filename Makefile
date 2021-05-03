EXEC = exe

CC = gcc
CFLAGS = -Wall -Wextra
#LDFlags =

#ensemble des .c
SRC = main.c \
	fonctions.c \

#ensemble des .o
OBJ = $(addprefix obj/,$(SRC:.c=.o))	


all : obj/ $(EXEC)

#créer le repertoire obj qui contiendra les .o
obj/ : 
	mkdir -p obj

#créer l'executable avec l'ensemble des .o
# $@ = la cible ; $^ l'ensemble des composants
$(EXEC) : $(OBJ)            
	$(CC) $^ -o $@           

#créer les .o à partir du .c
# % = remplace le nom du fichier pour éviter des redondances dans le makefile
# $< = le premier composant (ici le seul) ; $@ = la cible 
obj/%.o : src/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

#supprime le repertoire obj et son contenu 
clean :
	rm -rf obj

#appel la fonction clean puis supprime l'executable
mrproper : clean
	rm -rf $(EXEC)
