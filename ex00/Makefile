SRCS	= $(shell find . -type f -name "*.c")
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -fsanitize=address
NAME	= rush-02

${NAME}: all

all:
	${CC} ${CFLAGS} -I includes -o ${NAME} ${SRCS}

fclean:
	rm -f ${NAME}

re: fclean all