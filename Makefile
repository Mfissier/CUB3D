
SRC = main.c \
	  ./srcs/error.c \
	  ./srcs/utils.c \
	  ./srcs/utils2.c \
	  ./srcs/free.c \
	  ./srcs/parse_color.c \
	  ./srcs/parse_map.c \
	  ./srcs/init.c \
	  ./srcs/parse_texture.c \
	  ./srcs/check_wall.c

CC = gcc -Wall -Werror -Wextra -g 

NAME = cub3D.a

EXEC = cub3D

INCLUDE = -L .  #./minilibx-linux -lmlx -Ilmlx -lXext -lX11

OBJ = $(SRC:.c=.o)

all : $(EXEC) 

$(EXEC) : $(NAME) 
	ar rcs cub3D.a $(OBJ)
	${CC} -o cub3D cub3D.a $(INCLUDE) 

$(NAME) : $(OBJ) 
	make -C ./minilibx-linux
	make -C ./libft
	cp libft/libft.a .
	mv libft.a cub3D.a

$(OBJS)	:
	$(CC)  -c $(SRC) $(INCLUDE) 

clean : 
	make clean -C ./minilibx-linux
	make clean -C ./libft
	rm -rf $(OBJ)

fclean : clean
	make fclean -C ./libft
	rm -rf $(OBJ)
	rm -rf cub3D cub3D.a

re : fclean all 
	make fclean -C ./libft

run :
	./cub3D map.cub
