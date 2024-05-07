# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 14:23:38 by tforster          #+#    #+#              #
#    Updated: 2024/05/07 15:19:07 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED		=	\033[0;31m
GRN		=	\033[0;32m
YLW		=	\033[0;33m
BLU		=	\033[0;34m
MAG		=	\033[0;35m
CYA		=	\033[0;36m
WHT		=	\033[0;37m
RST		=	\033[0m

NAME	=	pipex

FILES	=	pipex.c pipex_utils.c args_utils.c\
			check_access.c check_file.c\
			parse_param.c parse_args.c parse_utils.c


SRCDIR	=	src
SRC		=	$(FILES:%.c=$(SRCDIR)%.o)

OBJDIR	=	obj
OBJ		=	${FILES:%.c=$(OBJDIR)/%.o}

CC		=	cc
CFLGS	=	-Wextra -Wall -Werror

LIBFT	=	./libs/libft
PF_PF	=	./libs/pf_printf

INCLUDE	=	-I ./include -I $(LIBFT) -I $(PF_PF)
LIBS	=	$(LIBFT)/libft.a $(PF_PF)/libpfprintf.a

DEL		=	$(OBJ_BNS)

all: $(NAME)

$(NAME): $(LIBS) $(OBJ)
	rm -rf $(DEL)
	$(CC) $(CFLGS) $(OBJ) $(LIBS) $(INCLUDE) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLGS) $(INCLUDE) -c $< -o $@
	@echo "${GRN}Compile $@ DONE${RST}"

$(LIBS):
	@make -C $(LIBFT)
	@make -C $(PF_PF)

clean:
	@rm -rf $(OBJDIR)
	@echo "${RED}CLEAN:	Objects $(OBJ) DELETED${RST}"

fclean: clean
	@make fclean -sC $(LIBFT)
	@echo "${RED}CLEAN:	Lib $(LIBFT) DELETED${RST}"
	@make fclean -sC $(PF_PF)
	@echo "${RED}CLEAN:	Lib $(PF_PF) DELETED${RST}"
	@rm -rf $(NAME)
	@echo "${RED}FCLEAN $(NAME) DELETED${RST}"

re: clean all

.PHONY: all, clean, fclean, re
