

NAME = libft.a

SOURCES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_itoa.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
			ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
			ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c \
			ft_substr.c ft_tolower.c ft_toupper.c ft_memcpy.c ft_strlcat.c ft_strlcpy.c \
			ft_printf.c ft_prtptr.c ft_putchar.c ft_putnbr_base.c ft_putstr.c get_next_line.c \
			get_next_line_utils.c \
			ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c \
			ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_lstmap.c

OBJECTS = $(SOURCES:.c=.o)

BONUS_OBJECTS = $(LST:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

%.o : %.c

	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJECTS)
	@ar rcs $(NAME) $(OBJECTS)

$(NAME_BONUS): 

clean:

	@rm -f $(OBJECTS) $(BONUS_OBJECTS) 

fclean: clean

	@rm -f $(NAME)

re: fclean all


bonus:  all $(OBJECTS) $(BONUS_OBJECTS)
		@ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)


.PHONY: all clean fclean re bonus