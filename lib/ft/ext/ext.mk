# ext.mk
# Parent: ../../../Makefile
EXT_SRCS := \
	lib/ft/ext/ft_isnum.c

EXT_OBJS := $(EXT_SRCS:%.c=$(OBJDIR)/%.o)
