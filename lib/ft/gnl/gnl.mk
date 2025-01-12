# gnl.mk
# Parent: ../../../Makefile
GNL_SRCS := \
	lib/ft/gnl/get_next_line_bonus.c \
	lib/ft/gnl/get_next_line_utils_bonus.c \

GNL_OBJS := $(PRINTF_SRCS:%.c=$(OBJDIR)/%.o)
