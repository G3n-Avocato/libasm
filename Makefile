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
 
OBJSDIR = obj

OBJS = $(patsubst %.s,$(OBJSDIR)/%.o,$(SRCS_FT))

NAME_BONUS = bonus/libasm_bonus.a

EXEC_BONUS = libasm_bonus

SRCS_BONUS = bonus/main_bonus.c

SRCS_FT_BONUS = bonus/ft_list_push_front.s \
				bonus/ft_list_size.s \
				bonus/ft_list_sort.s \
				bonus/ft_strcmp.s

OBJS_BONUS = $(patsubst %.s,$(OBJSDIR)/%.o,$(SRCS_FT_BONUS))

NASM_FLAGS = -f elf64

all: build $(NAME)
	@clang -g -o $(EXEC) $(SRCS) $(NAME)
	@printf "$(GREEN)> MAKE OK!\n"

build:
	@mkdir -p $(OBJSDIR)
	@printf "$(GREEN)> obj/ OK!\n"

$(OBJSDIR)/%.o: %.s
	@nasm $(NASM_FLAGS) $< -o $@

$(NAME): $(OBJS)
	@ar rcs $@ $(OBJS)

bonus: build-bonus $(NAME_BONUS)
	@clang -g -o $(EXEC_BONUS) $(SRCS_BONUS) $(NAME_BONUS)
	@printf "$(GREEN)> MAKE BONUS OK!\n"

build-bonus:
	@mkdir -p $(OBJSDIR)/bonus
	@printf "$(GREEN)> $(OBJSDIR)/bonus OK!\n"

$(NAME_BONUS): $(OBJS_BONUS)
	@ar rcs $@ $(OBJS_BONUS)

clean:
	@rm -f $(OBJSDIR)/*.o

clean-bonus:
	@rm -f $(OBJSDIR)/bonus/*.o
	@rm -rf $(OBJSDIR)/bonus

fclean: clean-bonus clean
	@rm -rf $(OBJSDIR)
	@rm -f $(NAME) $(EXEC)
	@rm -f $(NAME_BONUS) $(EXEC_BONUS)
	@printf "$(GREEN)> CLEAN OK!\n"

re: fclean all

.PHONY: all clean fclean re bonus clean-bonus build build-bonus