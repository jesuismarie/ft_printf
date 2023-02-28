NAME			= libftprintf.a
SRCS			= $(shell find . -name '*.c' ! -name '*bonus.c')
OBJS			= $(SRCS:.c=.o)
SRCS_B			= $(shell find  . -name '*_bonus.c')
OBJS_B			= $(SRCS_B:.c=.o)
RM				= rm -f
AR				= ar rcs
CC				= cc
FLAGS 			= -Wall -Wextra -Werror

.c.o: 
				$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(OBJS) 
					$(AR) $(NAME) $(OBJS)
clean:	
				$(RM) $(OBJS) $(OBJS_B)

fclean:			clean
					$(RM) $(NAME)

re: 			fclean all

bonus:			$(OBJS_B)
					$(AR) $(NAME) $(OBJS_B)

.PHONY:			all clean fclean bonus re