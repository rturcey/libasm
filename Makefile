SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s ft_atoi_base_bonus.s
OBJS		= $(SRCS:.s=.o)

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

NA			= nasm
NAFLAGS		= -f elf64 

NAME		= libasm.a

TEST		= test.c
EXEC		= test

%.o:		%.s
			$(NA) $(NAFLAGS) $<

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^

test:		$(NAME)
			$(CC) $(CFLAGS) $(TEST) -I ./includes/ -L ./ -lasm -o $(EXEC)

clean :
			rm -f $(OBJS)

fclean :	clean
			rm -f $(NAME) $(EXEC)

re :		fclean all