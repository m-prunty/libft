# c_ext.mk
# Parent ../../../Makefile
C_EXT_SRCS := \
	lib/ft/c_ext/ft_atol.c \
	lib/ft/c_ext/ft_strtol.c \

C_EXT_OBJS := $(C_EXT_SRCS:%.c=$(OBJDIR)/%.o)
