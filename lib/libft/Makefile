# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wichitt <wichitt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/15 17:50:21 by caunhach          #+#    #+#              #
#    Updated: 2023/12/20 08:13:19 by wichitt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
INCLUDES_PATH = inc
INCLUDES = inc/libft.h
SRCS = ft_isalnum.c \
       ft_isprint.c \
       ft_memcmp.c \
       ft_putchar_fd.c \
       ft_split.c \
       ft_isspace.c \
       ft_strlcat.c \
       ft_strncmp.c \
       ft_substr.c \
       ft_atoi.c \
       ft_isalpha.c \
       ft_itoa.c \
       ft_memcpy.c \
       ft_putendl_fd.c \
       ft_strchr.c \
       ft_strlcpy.c \
       ft_strnstr.c \
       ft_tolower.c \
       ft_bzero.c \
       ft_isascii.c \
       ft_memmove.c \
       ft_putnbr_fd.c \
       ft_strdup.c \
       ft_strlen.c \
       ft_strrchr.c \
       ft_toupper.c \
       ft_calloc.c \
       ft_isdigit.c \
       ft_memchr.c \
       ft_memset.c \
       ft_putstr_fd.c \
       ft_strjoin.c \
       ft_strmapi.c \
       ft_strtrim.c \
       ft_striteri.c \
       ft_printf.c \
       print_char.c \
       print_str.c \
       print_ptr.c \
       print_int.c \
       print_hex.c \
       print_unsigned.c \
       get_next_line.c \
       ft_atoi_base.c \
       ft_lstnew.c \
       ft_lstadd_front.c \
       ft_lstclear.c \
       ft_lstdelone.c \
       ft_lstiter.c \
       ft_lstlast.c \
       ft_lstmap.c \
       ft_lstadd_back.c \
       ft_lstsize.c \
	   ft_issign.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS): $(SRCS) $(INCLUDES)
	gcc $(FLAGS) -c $(SRCS) $(INCLUDES)

all: $(NAME)

clean:
	rm -f $(OBJS)
	rm -f $(INCLUDES_PATH)/libft.h.gch

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
