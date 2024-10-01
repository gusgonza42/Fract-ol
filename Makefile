# <-- Program Name --> #
NAME = fractol

# <-- Compilation Command --> #
CC = gcc

# <-- Compilation Flags --> #
CFLAGS = # -Wall -Werror -Wextra

# <-- Header Flags --> #
CPPFLAGS = -I ./libft -I ./ft_printf -I ./minilibx-linux

# <-- LD Linkers Flags Library--> #
LDLIBS = -lft -lftprintf -lmlx -Lmlx_linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

# <-- LD Route Flags --> #
LDFLAGS = -L ./libft -L ./ft_printf -L ./minilibx-linux

# <-- Remove Command -->#
RM = rm -f

# <-- HEADER --> #
HEADER = fractol.h

# <-- MAKEFILE --> #
MAKEFILE = Makefile

# <-- Files --> #
SRC_FILES = ft_main.c ft_init.c ft_events.c ft_math_utils.c ft_render.c


# <-- Objects --> #
OBJS = $(SRC_FILES:.c=.o)

# <-- Main Target --> #
all: $(NAME)

# <--Program Creation--> #
$(NAME): $(OBJS)
	@make -sC libft
	@make -sC ft_printf
	@make -sC minilibx-linux
	@echo "✅ 🚀 0bjects created successfully by $(NAME)!"
	@$(CC) -o $@ $(OBJS) $(CPPFLAGS) $(LDFLAGS) $(LDLIBS)
	@echo "✅ 🛰  $(NAME) created successfully!"

# <-- Objects Creation --> #
%.o: %.c $(HEADER) $(MAKEFILE)
	@echo "🧩 ☁️  Compiling... $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	@echo "🔨 🦔 $@ created!"

# <-- Objects Destruction --> #
clean:
	@$(RM) $(OBJS) 
	@make clean -sC libft
	@make clean -sC ft_printf
	@make -k clean -sC minilibx-linux || echo "Skipping clean in minilibx-linux"
	@echo "🗑️  🚀 Objects destroyed successfully by $(NAME)!"

# <-- Clean Execution + libft.a Destruction --> #
fclean: clean
	@$(RM) $(NAME)
	@make fclean -sC libft
	@make fclean -sC ft_printf
	@make -k fclean -sC minilibx-linux || echo "Skipping fclean in minilibx-linux"
	@echo "🗑️  🛰  $(NAME) destroyed successfully by $(NAME)!"

# <-- Re Execution -->
re:
	@make fclean
	@make all

# <-- Targets Declaration --> #
.PHONY : all clean fclean re
