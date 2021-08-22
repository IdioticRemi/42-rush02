SRCS	= ./src/charft.c ./src/dictft.c ./src/fileft.c ./src/main.c ./src/parseft.c ./src/putft.c ./src/stringft.c ./src/stringft2.c ./src/watift.c ./src/watift2.c
CC		= gcc
CFLAGS 	= -Wall -Wextra -Werror -fsanitize=address
NAME	= rush-02

${NAME}: all

all:
	${CC} ${CFLAGS} -I includes -o ${NAME} ${SRCS}

fclean:
	rm -f ${NAME}

re: fclean all