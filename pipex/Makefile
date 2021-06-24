CC=gcc
SRCS=src/main.c\
	src/pipex.c\
	src/ft_split_sp.c\
	src/pipex_utils.c
SRCB=bonus/main_bonus.c\
	bonus/pipex_bonus.c\
	bonus/ft_split_sp_bonus.c\
	bonus/pipex_utils_bonus.c
OBJS=$(SRCS:.c=.o)
OBJB=$(SRCB:.c=.o)
NAME=pipex
HEADER=-I include/mand/
HEADERB=-I include/bonus/
CFLAG=-Wall -Werror -Wextra
LIBFT_DIR=./utils/libft
LIBFT_NAME=libft.a

ifdef WITH_BONUS
	OBJ_FILES = $(OBJB)
else
	OBJ_FILES = $(OBJS)
endif

ifdef WITH_BONUS
%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADERB)
else
%.o: %.c
	$(CC) $(CFLAG) -c -o $@ $< $(HEADER)
endif

all: $(NAME)

$(NAME): $(LIBFT_NAME) $(OBJ_FILES)
	$(CC) $(CFLAG) -L. -lft -o $@ $(OBJ_FILES)

$(LIBFT_NAME):
	make bonus -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(LIBFT_NAME) .

bonus:
	make WITH_BONUS=1 all

clean:
	rm -f $(OBJS) $(OBJB)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -f $(NAME) $(LIBFT_NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all bonus clean fclean re
