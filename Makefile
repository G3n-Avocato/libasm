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

NAME_BONUS = bonus/libasm_bonus.a

EXEC_BONUS = libasm_bonus

SRCS_BONUS = bonus/main_bonus.c

SRCS_FT_BONUS = bonus/ft_list_push_front.s \
				bonus/ft_list_size.s \
				bonus/ft_list_sort.s

OBJS_BONUS = $(SRCS_FT_BONUS:.s=.o)

NASM_FLAGS = -f elf64

all: $(NAME)
	@clang -g -o $(EXEC) $(SRCS) $(NAME)
	@printf "$(GREEN)> MAKE OK!\n"
	
%.o: %.s
	@nasm $(NASM_FLAGS) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

bonus: $(NAME_BONUS)
	@clang -g -o $(EXEC_BONUS) $(SRCS_BONUS) $(NAME_BONUS)
	@printf "$(GREEN)> MAKE BONUS OK!\n"

$(NAME_BONUS): $(OBJS_BONUS)
	@ar rcs $@ $(OBJS_BONUS)

clean:
	@rm -f $(OBJS)

clean-bonus:
	@rm -f $(OBJS_BONUS)

fclean: clean clean-bonus
	@rm -f $(NAME) $(EXEC)
	@rm -f $(NAME_BONUS) $(EXEC_BONUS)
	@printf "$(GREEN)> CLEAN OK!\n"

re: fclean all

.PHONY: all clean fclean re bonus clean-bonus