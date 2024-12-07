#--------------------------------------------------#
################# PROGRAM NAME #####################
#--------------------------------------------------#
NAME		+= push_swap

#-----------------------------------------------#
################### PATHS #######################
#-----------------------------------------------#
HDRS_PATH	+= ./includes/
SRCS_PATH	+= ./sources/
OBJS_PATH	+= ./objects/

#-----------------------------------------------#
################## HEADERS ######################
#-----------------------------------------------#
HDRS			+= push_swap.h

vpath %.h $(HDRS_PATH)

#-----------------------------------------------#
################## SOURCES ######################
#-----------------------------------------------#
SRCS			+= main.c

vpath %.c $(SRCS_PATH)

#-----------------------------------------------#
################## OBJECTS ######################
#-----------------------------------------------#
OBJS		+= $(addprefix $(OBJS_PATH), $(SRCS:.c=.o))

#------------------------------------------------#
################## COMPILER ######################
#------------------------------------------------#
CC			= cc

#-----------------------------------------------#
################### FLAGS #######################
#-----------------------------------------------#
CFLAGS		+= -Wall
//CFLAGS		+= -Werror
CFLAGS		+= -Wextra

CPPFLAGS	+= -I $(HDRS_PATH)

# Multiple header directories
#CPPFLAGS	+= $(foreach DIR, $(HDRS_DIRS), $(addprefix -I , $(DIR)))

#-----------------------------------------------#
################# LIBRARIES #####################
#-----------------------------------------------#
LIBFT_PATH	+= ./libft/
LIBFT_NAME	+= libft.a
CPPFLAGS	+= -I $(LIBFT_PATH)
LDFLAGS		+= -L $(LIBFT_PATH)
LDLIBS		+= -lft

#-----------------------------------------------#
################### DEBUG #######################
#-----------------------------------------------#
ifeq ($(d), 0)
	CFLAGS	+= -g3
	CFLAGS	+= -Wpadded
	CFLAGS	+= -fsanitize=address,undefined
	LDFLAGS	+= -fsanitize=address,undefined
endif


#-----------------------------------------------#
################### RULES #######################
#-----------------------------------------------#
all:			$(NAME)

$(NAME):	$(LIBFT_PATH)$(LIBFT_NAME) $(OBJS)
					$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $@

$(OBJS_PATH)%.o:	%.c
					$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(OBJS):	Makefile $(HDRS) | $(OBJS_PATH)

$(OBJS_PATH):
					mkdir -p $@

$(LIBFT_PATH)$(LIBFT_NAME):
					$(MAKE) -C $(LIBFT_PATH) bonus custom

lib:
					$(MAKE) -C $(LIBFT_PATH) bonus custom
					$(MAKE) $(NAME)

clean:
					$(MAKE) -C $(LIBFT_PATH) fclean
					$(RM) -r $(OBJS_PATH)

fclean:		clean
					$(RM) $(NAME)

re:				fclean all

.PHONY:		all clean fclean re libft
