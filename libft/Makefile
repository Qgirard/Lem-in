# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nivergne <nivergne@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/02/20 12:42:57 by nivergne          #+#    #+#              #
#    Updated: 2019/08/06 04:43:36 by nivergne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_LIBFT =					ft_atoi.c\
							ft_isalnum.c\
							ft_isalpha.c\
							ft_isascii.c\
							ft_isdigit.c\
							ft_isprint.c\
							ft_itoa.c\
							ft_memset.c\
							ft_putchar.c\
							ft_putchar_fd.c\
							ft_putendl.c\
							ft_putendl_fd.c\
							ft_putnbr.c\
							ft_putnbr_fd.c\
							ft_putstr.c\
							ft_putstr_fd.c\
							ft_strncat.c\
							ft_strrchr.c\
							ft_strchr.c\
							ft_strcpy.c\
							ft_strdup.c\
							ft_strequ.c\
							ft_striter.c\
							ft_striteri.c\
							ft_strlen.c\
							ft_strmap.c\
							ft_strmapi.c\
							ft_strcat.c\
							ft_strcmp.c\
							ft_strncpy.c\
							ft_strnequ.c\
							ft_strnstr.c\
							ft_strstr.c\
							ft_tolower.c\
							ft_toupper.c\
							ft_strncmp.c\
							ft_memset.c\
							ft_bzero.c\
							ft_memcpy.c\
							ft_memccpy.c\
							ft_memmove.c\
							ft_memchr.c\
							ft_memcmp.c\
							ft_strlcat.c\
							ft_memalloc.c\
							ft_memdel.c\
							ft_strnew.c\
							ft_strdel.c\
							ft_strclr.c\
							ft_strsub.c\
							ft_strjoin.c\
							ft_strnjoinf.c\
							ft_strtrim.c\
							ft_strsplit.c\
							ft_lstnew.c\
							ft_lstdelone.c\
							ft_lstdel.c\
							ft_lstadd.c\
							ft_lstiter.c\
							ft_lstmap.c\
							get_next_line.c\
							ft_realloctab.c

SRC_PRINTF =				ft_printf.c\
							parse.c\
							else.c\
							print_per.c\
							print_b.c\
							print_c.c\
							print_s.c\
							print_p.c\
							print_i.c\
							print_o.c\
							print_u.c\
							print_x.c\
							print_f.c\
							print_ff.c\
							width_csp.c\
							width_dioux.c\
							convert_base.c

UNDER	=					\x1b[4m
BOLD	=					\x1b[1m
REV		=					\x1b[7m
END		=					\x1b[0m

RED		=					\x1b[31m
GREEN	=					\x1b[32m
BLUE	=					\x1b[34m
YELLOW	=					\x1b[33m
CYAN	=					\x1b[36m
PURPLE	=					\x1b[35m
GREY	=					\x1b[40m
WHITE	=					\x1b[37m

IRED	=					\x1b[41m
IGREEN	=					\x1b[42m
IBLUE	=					\x1b[44m
IYELLOW	=					\x1b[43m
ICYAN	=					\x1b[46m
IPURPLE	=					\x1b[45m
IGREY	=					\x1b[40m
IWHITE	=					\x1b[47m

CC =						gcc
CFLAGS =					-Wall -Wextra -Werror

INCLUDE =					-I./include/

PATH_LIBFT =				./libft
PATH_PRINTF =				./ft_printf
PATH_OBJ =					./obj

OBJ_LIBFT =					$(SRC_LIBFT:.c=.o)
OBJ_PRINTF =				$(SRC_PRINTF:.c=.o)

FULL_LIBFT =				$(addprefix $(PATH_OBJ)/,$(OBJ_LIBFT))
FULL_PRINTF =				$(addprefix $(PATH_OBJ)/,$(OBJ_PRINTF))

all: $(NAME)

$(NAME): $(FULL_LIBFT) $(FULL_PRINTF)
	@ar rc $(NAME) $(FULL_LIBFT) $(FULL_PRINTF)
	@ranlib $(NAME)
	@echo "$(BOLD)$(CYAN)$(BOLD)LIBFT			$(BLUE)$(BOLD)compile		$(GREEN)[OK]$(END)"
	@echo "$(BOLD)$(CYAN)$(BOLD)PRINTF			$(BLUE)$(BOLD)compile		$(GREEN)[OK]$(END)"

$(PATH_OBJ)/%.o: $(PATH_LIBFT)/%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@echo "$(BOLD)$(CYAN)pre-compile libft	$(BLUE)$(patsubst obj/%, %, $(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -I/libft $(INCLUDE) -o $@ -c $<
	@printf "\33[2K"

$(PATH_OBJ)/%.o: $(PATH_PRINTF)/%.c
	@mkdir $(PATH_OBJ) 2> /dev/null || true
	@echo "$(BOLD)$(CYAN)pre-compile printf	$(BLUE)$(patsubst obj/%, %, $(basename $@))$(END)"
	@printf "\033[A"
	@$(CC) $(CFLAGS) -Ofast $(INCLUDE) -o $@ -c $<
	@printf "\33[2K"

clean:
	@rm -rf $(OBJ_LIBFT) $(OBJ_PRINTF)
	@echo "$(BOLD)$(CYAN)LIBFT$(BLUE)			obj		$(END)$(RED)[delete]$(END)"
	@echo "$(BOLD)$(CYAN)PRINTF$(BLUE)			obj		$(END)$(RED)[delete]$(END)"

fclean: clean
	@rm -rf ./obj $(NAME)
	@echo "$(BOLD)$(CYAN)LIBFT$(BLUE)			arc		$(END)$(RED)[delete]$(END)"
	
re: fclean all

.PHONY: all clean fclean re norme
