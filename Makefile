NAME = client

NAMES = server

# PRINTF = libftprintf.a

LIBFT = libft.a

SRC = client.c

SRCS = server.c

RM = rm -f

INCS	= -I ./inc/

CC = gcc

FLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

OBJS = $(SRCS:.c=.o)

all: $(NAME) $(NAMES)

$(NAME): $(OBJ)
		@make all -C libftp
		@${CC} $(FLAGS) $(SRC) libftp/$(LIBFT) -o $(NAME)

$(NAMES): $(OBJS)
		@make all -C libftp
		@${CC} $(FLAGS) $(SRCS) libftp/$(LIBFT) -o $(NAMES)


clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJS)
		make clean -C libftp

fclean: clean
		make clean -C libftp
		$(RM) $(NAME)
		$(RM) $(NAMES)
		$(RM) $(LIBFT)

re: fclean all

bonus : clean
	@make -C libft
	@${CC} $(FLAGS) $(SRC) libftp/$(LIBFT) -o $(NAME)
	@${CC} $(FLAGS) $(SRCS) libftp/$(LIBFT) -o $(NAMES)

.PHONY : all clean fclean re