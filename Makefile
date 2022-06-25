LIBFT		= ./libft/libft.a
MINILIBX	= ./minilibx/libmlx_Linux.a
INCLUDE 	= -I./includes

SRC			= ./main.c \

OBJM		= ${SRC:.c=.o}

CC			= gcc
CFLAGS		= -g3 -O3
MLXFLAGS	= -lXext -lX11 -lm
RM			= rm -f
NAME		= cub3D

all:		${NAME}

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) $(MLXFLAGS) -c $< -o $@

$(NAME):	$(LIBFT) $(MINILIBX) ${OBJM}
			$(CC) $(CFLAGS) $(OBJM) $(LIBFT) $(MINILIBX) $(MLXFLAGS) -o $(NAME)

$(LIBFT):
			$(MAKE) -C ./libft

$(MINILIBX):
			$(MAKE) -C ./minilibx

clean:
			$(MAKE) -C ./libft clean
			$(MAKE) -C ./minilibx clean
			${RM} ${OBJM}

fclean:		clean
			$(MAKE) -C ./libft fclean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
