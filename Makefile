SRC = main.c \
		p_movements.c \
		data_input.c\
		get_next_line/get_next_line.c\
		get_next_line/get_next_line_utils.c\
		Check_valid.c\
		so_long.c\
		end_game.c\
		render.c\
		ft_itoa.c display_score.c\
		ft_putstr_fd.c\
		ft_putnbr_fd.c 
OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror
CC = cc
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = so_long
RM = rm -f
HEADER = so_long.h

all : $(NAME)

$(NAME) :	$(OBJ) $(HEADER)
	gcc $(MLXFLAGS) $(FLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(HEADER)
	$(CC) -c $< -o $@
clean :
	$(RM) $(OBJ)

fclean : clean 
	$(RM) $(OBJ) $(NAME)

re : fclean all
