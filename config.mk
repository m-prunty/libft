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

define progress_bar
    $(eval CURR_FILE = $(shell expr $(CURR_FILE) + 1))
    @printf "\r$(CYAN)⌛ [%-50s] %d/%d files$(CLR_RMV)\n" \
            "$$(printf '#%.0s' $$(seq 1 $$(expr $(CURR_FILE) \* 50 / $(TOTAL_FILES))))" \
            $(CURR_FILE) $(TOTAL_FILES)
endef
