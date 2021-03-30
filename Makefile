NAME		+= checker
#NAME		+= push_swap

SRCS_DIR		+= sources/checker/
#SRCS_DIR		+= sources/push_swap/

SRCS			+= main.c

vpath %.c $(SRCS_DIR)

HDRS_DIR		= includes/

HDRS			+= checker.h

vpath %.h $(HDRS_DIR)

OBJS_DIR		= objects/

OBJS			= $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))

LIBFT_DIR	= libft/

CC			= clang

CFLAGS		+= -Wall
CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	+= -I $(HDRS_DIR)
CPPFLAGS	+= -I $(LIBFT_DIR)

LDFLAGS		+= -L $(LIBFT_DIR)

LDLIBS		+= -lft

ifeq ($(d), 0)
	CFLAGS	+= -Wpadded
	CFLAGS	+= -g3
	CFLAGS	+= -fsanitize=address,undefined
	LDFLAGS	+= -fsanitize=address,undefined
endif

all:			$(NAME)

$(NAME):		$(LIBFT_DIR)libft.a $(OBJS)
				$(CC) $(LDFLAGS) -o $@ $(OBJS) $(LDLIBS)

$(OBJS_DIR)%.o:	%.c
				$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJS):		$(HDRS) $(LIBFT_DIR)libft.a | $(OBJS_DIR)

$(OBJS_DIR):
				mkdir $@

$(LIBFT_DIR)libft.a:
				$(MAKE) -C $(LIBFT_DIR) bonus custom

lib:
				$(MAKE) -C $(LIBFT_DIR) bonus custom
				$(MAKE) $(NAME)

clean:
				$(MAKE) -C $(LIBFT_DIR) fclean
				$(RM) -r $(OBJS_DIR)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all clean fclean re libft
