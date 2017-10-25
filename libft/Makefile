# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpetit <vpetit@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/18 21:24:23 by vpetit            #+#    #+#              #
#    Updated: 2017/10/24 13:57:52 by vpetit           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = .

INCL_DIR = .

SRC = ft_atoi \
		ft_malloc \
		ft_error \
		ft_bzero \
		ft_isalnum \
		ft_isalpha \
		ft_isascii \
		ft_isdigit \
		ft_isprint \
		ft_itoa \
		ft_stoabase \
		ft_itoabase \
		ft_ltoabase \
		ft_ctoabase \
		ft_l_to_oct \
		ft_wstrto_nstr \
		ft_wcharto_str \
		ft_lstadd \
		ft_lstdel \
		ft_lstdelone \
		ft_lstiter \
		ft_lstmap \
		ft_lstnew \
		ft_memalloc \
		ft_memccpy \
		ft_memchr \
		ft_memcmp \
		ft_memcpy \
		ft_memdel \
		ft_memmove \
		ft_memset \
		ft_putchar \
		ft_putchar_fd \
		ft_put_x_char \
		ft_putendl \
		ft_putendl_fd \
		ft_putnbr \
		ft_putnbr_fd \
		ft_put_llnbr \
		ft_put_ullnbr \
		ft_putstr \
		ft_putnstr \
		ft_putn_ustr \
		ft_putstr_fd \
		ft_strcat \
		ft_strchr \
		ft_strclr \
		ft_strcmp \
		ft_strcpy \
		ft_strdel \
		ft_strdup \
		ft_strequ \
		ft_striter \
		ft_striteri \
		ft_strjoin \
		ft_strlcat \
		ft_strlen \
		ft_wstrlen \
		ft_strmap \
		ft_strmapi \
		ft_strncat \
		ft_strncmp \
		ft_strncpy \
		ft_strnequ \
		ft_strnew \
		ft_strnstr \
		ft_strrchr \
		ft_strsplit \
		ft_strstr \
		ft_strsub \
		ft_strtrim \
		ft_tolower \
		ft_toupper \
		ft_strtoupper \
		ft_range \
		ft_isblank \
		ft_isinvisible \
		ft_foreach \
		ft_count_if \
		ft_max \
		ft_min \
		ft_abs \
		ft_intlen \
		ft_lintlen \
		ft_llintlen \
		ft_ullintlen \
		ft_power \
		ft_llpower

INCL = libft

all: $(NAME)

$(NAME): $(foreach element,$(SRC), $(SRC_DIR)/$(element).c)
	@gcc -Wall -Werror -Wextra -c $^ -I$(INCL_DIR)
	@ar -rc $@ $(foreach element,$(SRC), $(element).o)

clean:
	@/bin/rm -f $(foreach element,$(SRC), $(element).o)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
