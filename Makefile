# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpons <tpons@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/28 17:07:43 by tpons             #+#    #+#              #
#    Updated: 2020/03/28 17:16:17 by tpons            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = 

OBJS = $(SRCS:.s=.o)


$(NAME) : $(OBJS)


all : $(NAME)


test :


clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all