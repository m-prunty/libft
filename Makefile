################################################################################
#                                     CONFIG                                   #
################################################################################
NAME	:= libft.a
FLAGS	:= -Wall -Werror -Wextra -g

BDIR	:= bonus
PDIR	:= ft_printf
GDIR	:= get_next_line
EDIR	:= extras
OBJDIR	:= objects
INCLUDE	:= include

CC := gcc ${FLAGS} -I${INCLUDE} 
################################################################################
#                                     COLOURS                                  #
################################################################################
CLR_RMV     := \033[0m
RED         := \033[1;31m
GREEN       := \033[1;32m
YELLOW      := \033[1;33m
BLUE        := \033[1;34m
CYAN        := \033[1;36m
PURPLE      := \033[1;35m
BOLD        := \033[1m
################################################################################
#                                  ALL SRCS                                    #
################################################################################
SRC := \
	   ft_atoi.c \
	   ft_atoi_base.c \
	   ft_bzero.c \
	   ft_calloc.c \
	   ft_isalnum.c \
	   ft_isalpha.c \
	   ft_isascii.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c \
	   ft_putstr_fd.c \
	   ft_split.c \
	   ft_strchr.c \
	   ft_strdup.c \
	   ft_striteri.c \
	   ft_strjoin.c \
	   ft_strlcat.c \
	   ft_strlcpy.c \
	   ft_strlen.c \
	   ft_strmapi.c \
	   ft_strncmp.c \
	   ft_strnstr.c \
	   ft_strrchr.c \
	   ft_strtrim.c \
	   ft_substr.c \
	   ft_tolower.c \
	   ft_toupper.c \

BSRC := $(addprefix $(BDIR)/, \
		ft_lstadd_front.c \
		ft_lstclear.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstlast.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_lstsize.c \
		ft_lstadd_back.c \
		)
PSRC :=  $(addprefix $(PDIR)/, \
		 ft_iputnums.c \
		 ft_iputstrchar.c \
		 ft_printf.c \
		 )
GSRC := $(addprefix $(GDIR)/, \
		get_next_line_bonus.c \
		get_next_line_utils_bonus.c \
		)
ESRC := $(addprefix $(EDIR)/, \
		ft_isnum.c \
		)

################################################################################
#                                 CREATE OBJS                                  #
################################################################################
OBJECTS  := $(addprefix $(OBJDIR)/, $(SRC:.c=.o))	
BOBJECTS := $(addprefix $(OBJDIR)/, $(BSRC:.c=.o))
POBJECTS := $(addprefix $(OBJDIR)/, $(PSRC:.c=.o))
GOBJECTS := $(addprefix $(OBJDIR)/, $(GSRC:.c=.o))
EOBJECTS := $(addprefix $(OBJDIR)/, $(ESRC:.c=.o))

ALL_OBJS := $(OBJECTS) $(BOBJECTS) $(POBJECTS) $(GOBJECTS) $(EOBJECTS)
################################################################################
#                                 PROGRESS BAR                                 #
################################################################################
TOTAL_FILES = $(words $(ALL_OBJS) )
CURR_FILE   := 0

define progress_bar
$(eval CURR_FILE = $(shell expr $(CURR_FILE) + 1))
@printf "\r$(CYAN)⌛ [%-50s] %d/%d files$(CLR_RMV) \n" \
	"$$(printf '#%.0s' $$(seq 1 $$(expr $(CURR_FILE) \* 50 / $(TOTAL_FILES)))) " \
	$(CURR_FILE) $(TOTAL_FILES) 
endef
################################################################################
#                                COMPILATION                                   #
################################################################################
all: banner $(NAME) 

banner:
	@printf "%b" "$(PURPLE)"
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                         Building libft                        ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@printf "%b" "$(CLR_RMV)"

$(NAME): $(ALL_OBJS)
	@echo "\n$(GREEN)✅ All files compiled successfully!$(CLR_RMV)"
	@$(AR) -rcs $@ $^
	@echo "$(GREEN)📚 Library $(YELLOW)$(NAME)$(GREEN) created successfully!$(CLR_RMV)"

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -rcs $(NAME) $?

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR) $(OBJDIR)/$(BDIR) $(OBJDIR)/$(PDIR) \
		$(OBJDIR)/$(GDIR) $(OBJDIR)/$(EDIR)
	$(CC) $(CFLAGS) -c $< -o $@
	$(call progress_bar)

clean:
	@echo -n "Do you want to clean libft object files? [y/N] " && read ans && \
		if [ $${ans:-N} = y ]; then \
		echo "Cleaning objects..."; \
		rm -f $(ALL_OBJS); \
		rm -rf $(OBJDIR); \
		echo "$(RED)🗑️  Cleaned object files$(CLR_RMV)"; \
		else \
		echo "$(GREEN)✅ Clean aborted$(CLR_RMV)"; \
		fi

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Cleaned $(NAME)$(CLR_RMV)"

re: fclean all

.PHONY: all clean fclean re bonus banner

################################################################################
#                                 END                                          #
################################################################################
