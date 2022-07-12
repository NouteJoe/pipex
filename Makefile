# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmuni-re <jmuni-re@student.42mulhouse.fr>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 17:58:58 by jmuni-re          #+#    #+#              #
#    Updated: 2022/07/12 15:50:07 by jmuni-re         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME 	=	pipex

SRCS 	=	pipex.c

OBJS	=	${SRCS:.c=.o}

CC		=	gcc

RM 		=	rm -f


CFLAGS 	=	-Wall -Wextra -Werror

${NAME}: 	${OBJS}
			${CC} $(CFLAGS)  ${SRCS}  ./libft/libft.a -o $(NAME)


all: 		${NAME}

clean:
			@${RM} ${OBJS}

fclean:		clean
			@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
