SRCS	= ft_main.c \

OBJS	= ${addprefix objects/, ${SRCS:.c=.o}} 

NAME	= fractol

RM		= rm -rf

CC		= gcc
## pa no incluir cosas
CFLAGS	= -Wall -Wextra -Werror -I ./libs/MLX42/include/MLX42 -I ./includes

LIBFT	= ./libs/libft/libft.a
FT_PRINTF = ./libs/ft_printf/libftprint.a
GNL = ./libs/gnl/gnl.a
MLXLIB	=	mlx_linux/libmlx.a -lXext -lX11 -lm -lz


MLXLIB	=	MLX42/libmlx42.a -lXext -lX11 -lm -lz

${NAME}:	dir ${OBJS}
				${CC} ${CFLAGS} ${OBJS} -l:${LIBFT} -l:$(FT_PRINTF) -l:${MLXLIB} -l:${GNL} -o ${NAME}
dir:
				mkdir -p objects
				make -C libs/libft
				make -C libs/ft_printf
				make -C libs/gnl
				make -C libs/MLX42/build

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

