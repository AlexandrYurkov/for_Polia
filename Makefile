NAME		=	minishell

HEADER		=	minishell.h

SRCS		= 	for_sanya.c \
				ft_split.c \
				listfun.c \
				utils.c \
				swap_val_list.c \
				free_list.c \
				ft_unset.c \
				ft_export.c \
				ft_env.c \
				ft_cd.c \
				ft_pwd.c \
				ft_echo.c \
				ft_exit.c

OBJS		=	$(SRCS:.c=.o)

FLAGS		=	-Wall -Wextra -Werror -g 
CC			=	gcc
GCC			=	$(CC) -g #$(FLAGS)


all:			$(NAME)

%.o:			%.c $(HEADER)
				$(GCC) -c -o $@ $<
 
$(NAME):		$(OBJS)
				$(GCC) $(OBJS) -o $(NAME)

clean:				
				rm -f $(OBJS)
			
fclean:			clean
				rm -f $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re