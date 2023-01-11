NAME = pipex

SRC= ./utils/ft_printf.c ./utils/ft_printf_utils.c  ./utils/ft_split.c \
	./utils/utils_libft.c ./utils/utils_libft_one.c  main.c free_list.c

OBJ= $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror 

$(RM) = rm -f 
  
all: $(NAME)

$(NAME): $(OBJ) 
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)
	
push: fclean
	git add . && git commit -m "push" && git push

re: fclean all