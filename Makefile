# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adelille <adelille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/30 19:21:49 by adelille          #+#    #+#              #
#    Updated: 2021/02/11 16:11:33 by adelille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Find_Randomness
CC = clang -Wall -Werror -Wextra
RM = rm -rf

LBPATH = ./libft/
LBNAME = $(LBPATH)libft.a
LBINC = -I$(LBPATH)

SRCSPATH = ./srcs/
OBJSPATH = ./objs/
INC = ./includes/

SRCSNAME = main.c \
		   ft_use_of_random/ft_find_period.c \
		   ft_utils.c

SRCS = $(addprefix $(SRCSPATH), $(SRCSNAME))
OBJS = $(SRCS:.c=.o)
#OBJS = $(addprefix $(OBJSPATH), $(OBJSNAME))

all: $(NAME)

%.o: %.c
	$(CC) -I$(INC) $(LBINC) -c $< -o $@

$(NAME): $(OBJS)
	make -C $(LBPATH)
	$(CC) $(OBJS) $(LBNAME) -L$(LBPATH) $(LBINC) -I$(INC) -o $(NAME)
	$(info Find_Randomness compiled !)

$(LIBFTM):
	make -C $(LBPATH) -f Makefile

#$(OBJSPATH)%.o : %.c
#	@mkdir $(OBJSPATH) 2> /dev/null || true
#	@$(CC) -I $(INC) -c $< -o $@

libft:	$(LIBFTM)

clean:
	$(RM) $(OBJS)
	make -C $(LBPATH) -f Makefile clean
#	@rmdir $(OBJSPATH) 2> /dev/null || true

fclean: clean
	$(RM) $(NAME) $(MLXM)
	make -C $(LBPATH) -f Makefile fclean

re: fclean $(NAME)

.PHONY: all, clean, fclean, re, libft
