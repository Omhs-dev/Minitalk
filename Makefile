NAME = client

NAMES = server

PRINTF = libftprintf.a

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

$(NAME):
		@make clean -C libft
		@make -C printf
		@${CC} $(FLAGS) $(SRC) libft/$(LIBFT) printf/$(PRINTF) -o $(NAME)

$(NAMES):
		@make clean -C libft
		@make -C printf
		@${CC} $(FLAGS) $(SRCS) libft/$(LIBFT) printf/$(PRINTF) -o $(NAMES)


clean:
		@$(RM) $(OBJ)
		@$(RM) $(OBJS)
		make clean -C libft
		make clean -C printf

fclean: clean
		make clean -C libft
		make clean -C printf
		$(RM) $(NAME)
		$(RM) $(NAMES)
		$(RM) $(PRINTF)
		$(RM) $(LIBFT)

re: fclean all

bonus : clean
	@make -C printf
	@${CC} $(FLAGS) $(SRC) libft/$(LIBFT) printf/$(PRINTF) -o $(NAME)
	@${CC} $(FLAGS) $(SRCS) libft/$(LIBFT) printf/$(PRINTF) -o $(NAMES)

.PHONY : all clean fclean re