SRCS	=	ft_printf.c \
			ft_printf_utils.c

OBJS	= $(SRCS:.c=.o)

NAME	= libftprintf.a
CC		= gcc
RM		= rm -rf
CFLAGS	= -Wall -Wextra -Werror
LIBC	= ar rcs


all :  ${NAME}

$(NAME) : ${OBJS}
	$(LIBC) $(NAME) $(OBJS)

clean :
	${RM} ${OBJS}

fclean : clean
	${RM} ${NAME}

re : fclean all

.PHONY: all clean fclean re
