### General var ###

CC= gcc
FLAGS= -Werror -Wextra -Wall

### Name ###

NAME= tdenion.filler

### libft ###

LIBFT= lib/libft.a

### Srcs ###

FILES= filler.c parse_map.c parse_piece.c print.c search_place.c lst.c tool.c
SRCS= $(addprefix $(SRC_PATH)/, $(FILES))


### Objects ###

OBJS= $(SRCS:.c=.o)

### Path ###

SRC_PATH= srcs
INCLUDE= -I include -I lib/includes

### Colors ###

RESET=\033[0m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
MAGENTA=\033[35m
CYAN=\033[36m
WHITE=\033[37m

### Rules ###

all:$(NAME)

$(NAME):$(OBJS)
	@make -C lib
	@echo "$(GREEN)Compilation $(YELLOW)de $(RED)$@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ $^ $(LIBFT)

%.o:%.c
	@echo "$(GREEN)Compilation $(YELLOW)de $(RED)$@$(RESET)"
	@$(CC) $(FLAGS) $(INCLUDE) -o $@ -c $<

clean:
	@make -C lib clean
	@echo "$(GREEN)Suppression $(YELLOW)des $(RED)objets$(RESET)"
	@rm -f $(OBJS)

aclean:
	@rm -f $(OBJS)

fclean: aclean
	@make -C lib fclean
	@echo "$(GREEN)Suppression $(YELLOW)de $(RED)$(NAME)$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY:all clean aclean fclean re test

test: all
	@ mv $(NAME) resources/players/
	@./resources/filler_vm -f resources/maps/map00 -p2 resources/players/tdenion.filler -p1 resources/players/abanlin.filler
	@ rm resources/players/$(NAME)
