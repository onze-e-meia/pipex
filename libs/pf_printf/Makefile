# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tforster <tfforster@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/06 16:03:51 by tforster          #+#    #+#              #
#    Updated: 2024/03/28 15:28:00 by tforster         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GRN = \033[0;32m
YLW = \033[0;33m
BLU = \033[0;34m
MAG = \033[0;35m
CYA = \033[0;36m
WHT = \033[0;37m
RST = \033[0m

NAME	=	libpfprintf.a

SRCS	=	pf_printf.c \
			pf_putchar.c pf_putstr.c pf_putnbr_base.c \

SRCS_BONUS	=	pf_printf_bonus.c \
			pf_lst_bonus.c \
			pf_addchar_bonus.c pf_addstr_bonus.c pf_addnbr_base_bonus.c \
			pf_atoi_flags_bonus.c pf_flags_bonus.c \
			pf_conv_bonus.c pf_conv_nbs_bonus.c \

PATH_OBJS = objs
OBJS = $(SRCS:%.c=$(PATH_OBJS)/%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(PATH_OBJS)/%.o)

DEL_SRCS = $(OBJS_BONUS)
DEL_LIB = $(SRCS_BONUS:%.c=%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
	DEL_SRCS := $(OBJS)
	OBJS = $(OBJS_BONUS)
	DEL_LIB = $(SRCS:%.c=%.o)
endif

all: $(NAME)

$(NAME): $(OBJS)
	rm -rf $(DEL_SRCS)
	ar -d $(NAME) $(DEL_LIB)
	@echo "${BLU}pf_printf => Library $@ DONE${RST}"

$(OBJS): $(PATH_OBJS)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@
	@echo "${GRN}pf_printf => Object $@ DONE${RST}"
	ar rcs $(NAME) $@
	@echo "${YLW}pf_printf => Object $@ ADDED to $(NAME) ${RST}"


bonus:
	@make WITH_BONUS=TRUE --no-print-directory

clean:
	rm -rf $(PATH_OBJS)
	@echo "${RED}CLEAN Objects $(OBJS) DELETED${RST}"

fclean: clean
	rm -rf $(NAME)
	@echo "${RED}FCLEAN Objects $(NAME) DELETED${RST}"

re: fclean all

.PHONY: all bonus clean fclean re
