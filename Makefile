################################################################################
#                                  MAIN MAKEFILE                                 #
################################################################################
NAME := libft.a

include config.mk

include lib/ft/c/c.mk
include lib/ft/bonus/bonus.mk
include lib/ft/ft_ext/ft_ext.mk
include lib/ft/ft_printf/ft_printf.mk
include lib/ft/ext/ext.mk
include lib/ft/gnl/gnl.mk

ALL_OBJS := $(C_OBJS) $(BONUS_OBJS) $(FT_EXT_OBJS) $(PRINTF_OBJS) $(EXT_OBJS) $(GNL_OBJS)

################################################################################
#                                  TARGETS                                       #
################################################################################
all: banner $(NAME)

$(NAME): $(ALL_OBJS)
	@echo "$(GREEN)✅ All files compiled successfully!$(CLR_RMV)"
	@$(AR) -rcs $@ $^
	@echo "$(GREEN)📚 Library $(YELLOW)$(NAME)$(GREEN) created successfully!$(CLR_RMV)"

clean:
	@echo -n "Do you want to clean libft object files? [y/N] " && read ans && \
	if [ $${ans:-N} = y ]; then \
		echo "Cleaning objects..."; \
		rm -rf $(OBJDIR); \
		echo "$(RED)🗑️  Cleaned object files$(CLR_RMV)"; \
	else \
		echo "$(GREEN)✅ Clean aborted$(CLR_RMV)"; \
	fi

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🗑️  Cleaned $(NAME)$(CLR_RMV)"

re: fclean all

.PHONY: all clean fclean re banner

################################################################################
#                                  RULES                                         #
################################################################################
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
	$(call progress_bar)

banner:
	@printf "%b" "$(PURPLE)"
	@echo "╔═══════════════════════════════════════════════════════════════╗"
	@echo "║                         Building libft                        ║"
	@echo "╚═══════════════════════════════════════════════════════════════╝"
	@printf "%b" "$(CLR_RMV)"
