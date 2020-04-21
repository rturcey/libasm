SRCS		= ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s
SRCS_BONUS	= ft_atoi_base_bonus.s ft_list_push_front_bonus.s ft_list_size_bonus.s \
				ft_list_sort_bonus.s ft_list_remove_if_bonus.s

OBJS		= $(SRCS:.s=.o)
OBJS_BONUS	= $(SRCS_BONUS:.s=.o)

CC			= clang
CFLAGS		= -Wall -Wextra -Werror 

NA			= nasm
NAFLAGS		= -f elf64

NAME		= libasm.a

TEST		= test.c
TEST_BONUS	= test_bonus.c
EXEC		= test
EXEC_BONUS	= test_bonus

%.o:		%.s
			$(NA) $(NAFLAGS) $<

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rcs $@ $^

test:		$(NAME)
			$(CC) $(CFLAGS) $(TEST) -I ./includes/ -L ./ -lasm -o $(EXEC)

bonus:		$(OBJS) $(OBJS_BONUS)
			ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

test_bonus:	bonus
			$(CC) $(CFLAGS) $(TEST_BONUS) -I ./includes/ -L ./ -lasm -o $(EXEC_BONUS)

clean :
			rm -f $(OBJS) $(OBJS_BONUS)

fclean :	clean
			rm -f $(NAME) $(EXEC) $(EXEC_BONUS)

re :		fclean all