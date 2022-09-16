/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eavedill <eavedill@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 18:05:43 by eavedill          #+#    #+#             */
/*   Updated: 2022/09/15 18:18:08 by eavedill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
SRC			=		ft_isalpha 

SRCS		=	$(addsuffix, .c , $(SRC))

HEAAD		= ./includes/

OBJS		= ${SRCS: .c = .o}

CC			= gcc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror -I

NAME		= Libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:		$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re 