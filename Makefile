##
## EPITECH PROJECT, 2019
## bistromatic
## File description:
## bistromatic makefile
##

CC =		gcc

RM =		rm -f

NAME =		bistromatic

COMPILEFLAG =	-Wall -Wextra -pedantic -g

INCLUDE =	-I./include/

USELESS_F =	$(shell find -name '*~')

CFLAGS =	$(COMPILEFLAG) $(INCLUDE)

SRC	=	$(shell find src/ -name '*.c')
SRC	+=	$(shell find lib/ -name '*.c')

OBJ	=	$(SRC:.c=.o)

$(OBJDIR)%.o:	%.c
		@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME):	$(OBJ)
		@$(RM) $(NAME)
		@$(CC) $(OBJ) -o $(NAME) $(CFLAGS)
		@echo -e "\033[01m\033[05m\033[31m\033[03m[${NAME}]\033[00m"
		@$(RM) $(OBJ)
		@$(RM) $(OBJLIB)
		@$(RM) $(USELESS_F)


all:		$(NAME)

clean:
		@$(RM) $(OBJ)
		@$(RM) $(USELESS_F)
		@echo -e "Removing objects  ..."

fclean:		clean
		@$(RM) $(NAME)
		@echo -e "Removing binary : ... {${NAME}}"

re:		fclean all

.PHONY:		all clean fclean re
