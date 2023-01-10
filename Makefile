NAME = pipex

SRC= ./utils/ft_printf.c ./utils/ft_printf_utils.c \
	./utils/get_next_line.c ./utils/get_next_line_utils.c \
	./utils/ft_split.c ./utils/m_strjoin.c  ./utils/utils_libft.c main.c

OBJ= $(SRC:.c=.o)

CC = cc

#CFLAGS=  -Wall -Wextra -Werror 

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