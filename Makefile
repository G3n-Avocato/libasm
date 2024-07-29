GREEN=\033[32m

NAME = libasm.a

EXEC = libasm

SRCS = main.c

SRCS_FT = ft_strlen.s \
		ft_strcpy.s \
		ft_strcmp.s \
		ft_write.s \
		ft_read.s \
		ft_strdup.s

OBJS = $(SRCS_FT:.s=.o)

NASM_FLAGS = -f elf64

all: $(NAME)
	@clang -g -o $(EXEC) $(SRCS) $(NAME)
	@printf "$(GREEN)> MAKE OK!\n"
	
%.o: %.s
	@nasm $(NASM_FLAGS) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME) $(EXEC)
	@printf "$(GREEN)> CLEAN OK!\n"

re: fclean all

.PHONY: all clean fclean re