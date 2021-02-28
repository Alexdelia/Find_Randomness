# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/02/28 17:38:13 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 	Find_Randomness
CC = 	gcc -Wall -Werror -Wextra
RM = 	rm -rf
# FLAGS =	-O2

# **************************************************************************** #

MAKEFLAGS += --silent

B =		$(shell tput bold)
BLA =	$(shell tput setaf 0)
RED =	$(shell tput setaf 1)
GRE =	$(shell tput setaf 2)
YEL =	$(shell tput setaf 3)
BLU =	$(shell tput setaf 4)
MAG =	$(shell tput setaf 5)
CYA =	$(shell tput setaf 6)
WHI =	$(shell tput setaf 7)
D =		$(shell tput sgr0)
BEL =	$(shell tput bel)
CLR =	$(shell tput el 1)

# **************************************************************************** #
#	 LIB	#

LBPATH =	./libft/
LBNAME =	$(LBPATH)libft.a
LBINC =		-I$(LBPATH)

# **************************************************************************** #

SRCSPATH =	./srcs/
OBJSPATH =	./objs/
INC =		./includes/

SRCSNAME = main.c \
			ft_random/ft_linear_congruential_generator.c \
			ft_use_of_random/ft_find_period.c \
			ft_use_of_random/ft_perf.c \
			ft_use_of_random/ft_map_debug.c \
			ft_use_of_random/ft_binary_show.c \
			ft_arg.c \
			ft_utils.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJSNAME = $(SRCSNAME:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))
OBJS = $(OBJSPATH)*.o

# *************************************************************************** #

all:
	@make -C $(LBPATH)
	@mkdir $(OBJSPATH) 2> /dev/null || true
	@$(CC) -I$(INC) -c $(SRCS)
	@mv *.o $(OBJSPATH)
	@$(CC) $(OBJS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(NAME)
	@echo "$(B)$(MAG)$(BEL)\n\tFind_Randomness compiled! Have fun.\n$(D)"

$(LIBFTM):
	@make -C $(LBPATH) -f Makefile

libft:	$(LIBFTM)
	@echo "$(B)Libft compiled.$(D)"

clean:
	@$(RM) $(OBJS)
	@make -C $(LBPATH) -f Makefile clean
	@rmdir $(OBJSPATH) 2> /dev/null || true
	@echo "$(B)Cleared.$(D)"


fclean: clean
	@$(RM) $(NAME) $(MLXM)
	@make -C $(LBPATH) -f Makefile fclean

re: fclean all

.PHONY: all, clean, fclean, re, libft

# **************************************************************************** #
