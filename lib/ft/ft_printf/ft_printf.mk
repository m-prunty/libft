# ft_printf.mk
# Parent: ../../../Makefile
PRINTF_SRCS := \
	lib/ft/ft_printf/ft_iputnums.c \
	lib/ft/ft_printf/ft_iputstrchar.c \
	lib/ft/ft_printf/ft_printf.c

PRINTF_OBJS := $(PRINTF_SRCS:%.c=$(OBJDIR)/%.o)
