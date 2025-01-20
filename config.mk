# config.mk
# Parent: ./Makefile
# Header: ./include/libft.h
CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -g
INCLUDE := -Iinclude

OBJDIR  := objects
LIBDIR  := lib

CLR_RMV := \033[0m
RED     := \033[1;31m
GREEN   := \033[1;32m
YELLOW  := \033[1;33m
BLUE    := \033[1;34m
CYAN    := \033[1;36m
PURPLE  := \033[1;35m
BOLD    := \033[1;1m

TOTAL_FILES = $(words $(ALL_OBJS))
CURR_FILE   := 0

# Bar style
BAR_WIDTH   := 50
BAR_CHAR    := \#
CLEAR_LINE  := \033[0K
MOVE_UP     := \033[1A

define progress_bar
	$(eval CURR_FILE := $(shell expr $(CURR_FILE) + 1))
	@printf "\n$(CLEAR_LINE)\r$(YELLOW)▶ $(PURPLE)%s$(CLR_RMV)" "$<"
	@printf "$(CLEAR_LINE)\r$(CYAN)⌛ [%-$(BAR_WIDTH)s] %3d/%-3d files$(CLR_RMV)" \
		"$$(printf '$(BAR_CHAR)%.0s' $$(seq 1 $$(expr $(CURR_FILE) \* $(BAR_WIDTH) / $(TOTAL_FILES))))" \
		$(CURR_FILE) $(TOTAL_FILES)
	@printf "\n$(MOVE_UP)"
endef
