SRCS	= main.c \

OBJS	= ${addprefix objects/, ${SRCS:.c=.o}}

NAME	= fdf

RM		= rm -rf

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

LIBFT	= libs/libft/libft.a
FT_PRINTF = libs/ft_printf/libftprint.a
GNL = libs/gnl/gnl.a
MLXLIB	=	mlx_linux/libmlx.a -lXext -lX11 -lm -lz


MLXLIB	=	MLX42/libmlx42.a -lXext -lX11 -lm -lz

${NAME}:	${OBJS} dir
				${CC} ${CFLAGS} ${OBJS} ${LIBFT} $(FT_PRINTF) ${MLXLIB} ${GNL} -o ${NAME}
dir:
				mkdir -p objects
				make -C libs/libft
				make -C libs/ft_printf
				make -C libs/gnl
				make -C libs/MLX42

# Ajuste para compilar los archivos en objects/
objects/%.o: src/%.c Makefile

				${CC} ${CFLAGS} -c $< -MMD -o $@

clean:
				nake clean -C libs/gnl/
				make clean -C libs/libft/
				make clean -C libs/ft_printf/
				make clean -C libs/MLX42
				${RM} objects/

fclean:		clean
				make clean -C libs/MLX42
				make fclean -C libs/libft
				make fclean -C libs/ft_printf
				make fclean -C libs/gnl
				${RM} ${NAME}

re:			fclean all

.PHONY:		clean fclean re all

