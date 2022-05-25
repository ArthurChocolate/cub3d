NAME		=	cub3d

SRC_D		=	srcs
GNL_D		=	gnl
LIBFT_D		=	libft

SRCS		=	${SRC_D}/map_reader.c \
				${SRC_D}/map_validate.c \
				\
				${GNL_D}/get_next_line.c \
				${GNL_D}/get_next_line_utils.c \

OBJS		=	${SRCS:.c=.o}

INCLUDE		=	-I ./include -I./minilibx

CC			=	gcc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror
MLX_FLAGS	=	-framework OpenGL -framework AppKit

MLX_PATH	=	./minilibx/libmlx.a
LIBFT_PATH	=	./libft/libft.a

all: ${NAME}

${NAME}: ${OBJS}
	${MAKE} -C ${dir ${LIBFT_PATH}}
	${MAKE} -C ${dir ${MLX_PATH}}
	cp ${MLX_PATH} .
	${CC} ${CFLAGS} ${LIBFT_PATH} ${MLX_PATH} ${OBJS} ${MLX_FLAGS} -o ${NAME}

%.c: %.o
	${CC} ${CFLAGS} ${INCLUDE} -c $< -o $@

clean:
	${MAKE} clean -C ${dir ${LIBFT_PATH}}
	${MAKE} clean -C ${dir ${MLX_PATH}}
	${RM} ${OBJS}

fclean: clean
	${MAKE} fclean -C ${dir ${LIBFT_PATH}}
	${RM} ${NAME}
	${RM} libmlx.a

re: fclean all

.PHONY: all clean fclean re