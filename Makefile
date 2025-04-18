# Main
NAME				=	im-gui-minilibx.a
CC					=	clang

CFLAGS				=	-Wall -Werror -Wextra -O3 -O2 -ffast-math -march=native -Ilibs/ft_libc/includes -Ilibs/minilibx_linux -Iincludes -fPIE -g
CMLX_FLAGS				= -lXext -lX11 -lm -lz
RM					=	rm -rf
MAKE				=	make --no-print-directory -C

# Colors
RESET				=	\033[0m
BLACK				=	\033[0;30m
RED					=	\033[0;31m
GREEN				=	\033[1;32m
YELLOW				=	\033[0;33m
BLUE				=	\033[0;34m
PURPLE				=	\033[1;35m
CYAN				=	\033[1;36m
WHITE				=	\033[0;37m

# Symbols
OK					=	✓
FAIL				=	✗
INFO				=	ⓘ

# Sources and Objects
FT_LIBC 			= ./libs/ft_libc/ft_libc.a
MLX_LIB 			= ./libs/minilibx_linux/libmlx_Linux.a
MLX_LIB_PATH 		= ./libs/minilibx_linux/

SRCS				=	src/main.c\
						src/loop.c\
						src/mouse.c\
						src/init.c\
						src/destroy/destroy.c\
						src/upscaler/upscaler.c\
						src/utils/rectangle.c\
						src/alpha_images/alpha_images.c\
						src/alpha_images/put.c\
						src/alpha_images/free_alpha.c\
						src/panels/panel_add_button.c\
						src/panels/panel_add_component.c\
						src/panels/panel_pre_render.c\
						src/panels/panel_background.c\
						src/panels/panel_creation.c\
						src/panels/panel_destruction.c\
						src/panels/panel_render_on_window.c\
						src/components/button/button.c\
						src/components/checkbox/checkbox.c\
						src/components/destroy_components.c\
						src/components/state.c\
						src/components/getter.c\
						src/components/utils.c\
						src/imgs/manipulation.c\
						src/imgs/split.c\
						src/png/png_file.c\
						src/png/igmlx_png_to_alpha_image.c\
						src/fonts/font_loader.c\
						src/fonts/get.c\
						src/fonts/print.c\
						src/fonts/destroy_fonts.c\
						src/utils/timer/timer.c\
						src/utils/alloc/balloc.c\
						src/hooks/hook.c\
						src/logs/logs.c\
						src/rendering/pre_render.c\
						src/rendering/render.c

TESTS				=	tests/main.c
TESTS_OBJ_DIR		=	objects/_tests
TESTS_OBJS			=	$(patsubst %.c, $(TESTS_OBJ_DIR)/%.o, $(TESTS))

SRC_COUNT			=	$(words $(SRCS))
OBJ_DIR				=	objects/main
OBJS				=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(SRCS))

all : $(NAME)

$(NAME) : header $(FT_LIBC) $(OBJ_DIR) $(MLX_LIB)
		@ar rcs $@ $(OBJS) $(FT_LIBC) $(MLX_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR): $(OBJS)
		@if [ ! -d "$(OBJ_DIR)" ]; \
			then mkdir -p "$(OBJ_DIR)"; \
		fi
		@if [ ! -e "$(NAME)" ]; then \
			printf "$(GREEN)Compiled $(OK)\n" ; \
		fi


$(TESTS_OBJ_DIR)/%.o: %.c
		@mkdir -p $(dir $@)
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "$(GREEN)$(OK)$(RESET)"

$(TESTS_OBJ_DIR): $(TESTS_OBJS)
		@if [ ! -d "$(TESTS_OBJ_DIR)" ]; \
			then mkdir -p "$(TESTS_OBJ_DIR)"; \
		fi
		@if [ ! -e "$(NAME)" ]; then \
			printf "$(GREEN)Compiled $(OK)\n" ; \
		fi

$(FT_LIBC) :
	@if [ ! -e "$(shell dirname $@)" ]; then \
		git clone git@github.com:R0-main/ft_libc.git $(shell dirname $@); \
	fi;
	@$(MAKE) $(shell dirname $@) SAFE=0

$(MLX_LIB):
	@if [ ! -e "$($@)" ]; then \
		git clone https://github.com/42Paris/minilibx-linux.git $(shell dirname $@); \
		cd $(shell dirname $@) && ./configure && cd .. ;\
	fi;
	make re -C $(MLX_LIB_PATH) --no-print-directory

tests : $(TESTS_OBJS) $(NAME) $(FT_LIBC) $(MLX_LIB)
	@$(RM) tests.out
	@$(CC) $(CMLX_FLAGS) $(CFLAGS) $(TESTS_OBJS) $(NAME) $(FT_LIBC) $(MLX_LIB) -o tests.out

dev	 : clean-objs all tests
	valgrind --track-fds=yes --trace-children=yes --show-leak-kinds=all --leak-check=full -q ./tests.out

clean-objs :
		@$(RM) $(OBJ_DIR)
		@$(RM) $(TESTS_OBJ_DIR)
		@$(RM) $(NAME)

clean : clean-objs
		@$(MAKE) $(shell dirname $(FT_LIBC)) fclean
		@make clean -C $(MLX_LIB_PATH) --no-print-directory

fclean : clean
		@$(RM) $(NAME)
		@$(RM) $(TESTS_OBJS) ./tests.out

re : fclean all

.PHONY: all clean fclean re header tests clean-objs
