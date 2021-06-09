# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcambaki <j.cambakidis@gmail.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 13:37:35 by jcambaki          #+#    #+#              #
#    Updated: 2021/04/21 19:08:02 by jcambaki         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

# Colors
GREY = \033[4;34m
RED = \033[1;31m
GREEN = \033[3;32m
YELLOW = \033[2;49;33m
BLUE = \033[4;34m
BLUEE = \033[3;34m
PURPLE = \033[3;35m
CYAN = \033[3;36m
RESET = \033[0m
ICONOK = \033[1;32m
ICONKO = \033[1;31m
CO_DELET = \033[3;31m
CO_A_OUT = \033[96m
WHITE = \033[1;49;97m

NAME		= 	cub3d

LIBFT		=	./libft/libft.a

-include 	sources.mk

CFLAGS		= 	-Wall -Wextra -Werror -g3 -Ofast -flto -march=native -ffast-math

LFLAGS		=	-L minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit -lpthread

INCLUDES	= 	-Iincludes \
				-Iminilibx_opengl_20191021

OBJS		= 	$(SRCS:.c=.o)

GCC			= 	@cc

RM			= 	@rm -f

all:			$(NAME)

lbxmk:
				@${MAKE} -C ./minilibx_opengl_20191021 all
				@printf "\033[2K\r$(CYAN)\nminilibx$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n\n"

lbft:
				@${MAKE} -C ./libft all
				@printf "\033[2K\r$(CYAN)libft$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n\n"

%.o:			%.c includes/cub3d.h $(LIBFT)
				$(GCC) $(CFLAGS) $(INCLUDES) -c $< -o $@
				@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(PURPLE)$<$(RESET)"

$(NAME): 		lbxmk lbft includes/cub3d.h $(OBJS)
				$(GCC) $(CFLAGS) -o $(NAME) ${LIBFT} $(OBJS) $(LFLAGS)
				@printf "\033[2K\r$(BLUE)$(NAME)$(RESET)$(BLUEE): $(ICONOK)Compiled [√]$(RESET)\n"


clean:
				$(RM) $(OBJS)
				@${MAKE} -C ./libft clean
				@printf "\033[2K\r$(CYAN)cleaning$(RESET)$(BLUEE): $(ICONOK)Complete [√]$(RESET)\n"

fclean:			clean
				@$(RM) $(NAME)
				@${MAKE} -C ./libft fclean

re:				fclean	all

norminette: 	clean
				@echo " "
				norminette srcs
				@echo " "
				norminette includes

sh:				
				./scripts/make.sh

.PHONY:			make all clean fclean re lbxmk sh norminette