NAME = libasm.a

SRCS =	ft_strlen.s\
		ft_strcpy.s\
		ft_strcmp.s

OBJS = $(SRCS:.s=.o)

INCLUDE = -L. -lasm

FLAGS = -v -Wall -Wextra -Werror

%.o	: %.s
	nasm -f elf64 $< -o $@
# Mac compil would've been nasm -f macho64 $< -o $@

$(NAME): $(OBJS) 
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -f $(OBJS)

test: all
	clang main.c -o test_libasm $(INCLUDE)
	./test_libasm

fclean: clean
	rm -f $(NAME)
	rm -f test_libasm
	rm -f test

re: fclean all