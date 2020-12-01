# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: epetrill <epetrill@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/15 20:38:23 by epetrill          #+#    #+#              #
#    Updated: 2020/12/01 21:38:46 by epetrill         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	= Cub3D
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
OBJDIR	= objs
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR)
SRCS	= $(addprefix $(SRCDIR)/, ftbasic3.c ftbasic2.c mapprep.c param.c cub.c filetotab.c ftbasic.c error.c get_next_line.c get_next_line_utils.c error2.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
HDRS	= $(addprefix $(INCDIR)/, cub.h get_next_line.h)

all				:	$(NAME)


$(NAME)			:	$(OBJDIR) $(OBJS)
		$(CC) -g -o $@ $(OBJS)

$(OBJDIR)		:
		mkdir -p $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c $(HDRS)
		$(CC) $(CFLAGS) $(IFLAGS) -g -c -o $@ $<

clean			:
		/bin/rm -rf $(OBJDIR)

fclean			:	clean
		/bin/rm -f $(NAME)

re				:	fclean all


.PHONY			: cub
