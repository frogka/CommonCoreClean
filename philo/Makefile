# Nom du projet
NAME = philo


# Fichiers sources
SRCS = philo.c \
		init.c \
		philo_routine.c \
		parsing.c \
		mutex.c \
		error.c \
		forks.c 

#Couleurs pour afficher les messages
RED = \033[31m
CYAN = \033[36m
PURPLE = \033[35m
YELLOW = \033[98m
BLUE = \033[34m
JADE = \033[92m
RESET = \033[0m

# Compilateur
CC = cc

# Flags
CFLAGS = -Wall -Wextra -Werror -g -pthread

# Fichiers objets générés
OBJ = $(SRCS:.c=.o)


$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "$(JADE)Philosopher project compiled successfully!$(RESET)"
	@echo "$(YELLOW)Compilation terminée. Exécutez ./$(NAME) pour lancer le programme.$(RESET)"
	@echo "$(PURPLE)To run the program, use: ./$(NAME) [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]$(RESET)"

# Règle générique pour compiler les fichiers .c en .o
%.o: %.c
	@echo "$(JADE)Compilation de $<...$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I .

# Règle par défaut pour compiler le programme
all: $(NAME)
	

# Nettoyage des fichiers objets
clean:
	@echo "$(RED)Nettoyage des objets...$(RESET)"
	rm -f $(OBJ)

# Nettoyage complet (objets + programme)
fclean: clean
	@echo "$(RED)Nettoyage complet...$(RESET)"
	rm -f $(NAME)

# Règle pour tout refaire (nettoyage complet + recompilation)
re: fclean all

# Déclaration des cibles sans fichiers associés
.PHONY: all clean fclean re
