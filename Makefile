# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eakman <eakman@student.42kocaeli.com.tr    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 17:14:59 by eakman            #+#    #+#              #
#    Updated: 2023/11/12 21:10:57 by eakman           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFTPATH	= library/libft

NAME		= so_long
HEADER		= includes/so_long.h

MINILIBX	= library/minilibx_opengl/


CC			= gcc
CFLAGS		= -Wall -Werror -Wextra
RM			= rm -f
ECHO		= echo

OPENGL		= -framework OpenGL -framework AppKit

MINILIBXCC	= -I mlx -L $(MINILIBX) -lmlx


COMPILEPRM	= $(MINILIBXCC) $(OPENGL) -o $(NAME) libft.a $(MINILIBX)/libmlx.a
MANDATORYFILES = source/checks.c \
 				source/draw.c \
 				source/initiliazers.c \
 				source/move.c \
 				source/path_finding.c \
 				source/render.c \
 				source/so_long.c \
 				source/utils_error.c \
 				source/map_name_check.c

			
MANDATORYOBJ	=	$(MANDATORYFILES:.c=.o)
start:
			@make all
all:		$(NAME)
$(NAME):	$(MANDATORYFILES)
			@echo "Minilibx library is compiling..."
			@make -s -C $(MINILIBX) 2> /dev/null
			@echo "================================"
			@echo "Libft library is compiling..."
			@make -C $(LIBFTPATH) 2> /dev/null
			@cp $(LIBFTPATH)/libft.a .
			@$(CC) $(CFLAGS) $(MANDATORYFILES) $(COMPILEPRM)
			@echo "================================"
			@echo "DONE!"
clean:
			@$(RM) -r $(MANDATORYOBJ) 2> /dev/null
			@make clean -C $(MINILIBX) 2> /dev/null
			@make clean -C $(LIBFTPATH) 2> /dev/null
fclean:		clean
			@$(RM) -rf $(LIBFTPATH)/libft.a
			@$(RM) -r $(NAME)
			@$(RM) -rf libft.a
re:			fclean all
			@$(ECHO) -n "$(GREEN)Cleaned and rebuilt everything for [so_long]!"
.PHONY:		all clean fclean re norm