# ft_ext.mk
# Parent: ../../../Makefile
FT_EXT_SRCS := \
	lib/ft/ft_ext/ft_atoi_base.c \
	lib/ft/ft_ext/ft_itoa.c \
	lib/ft/ft_ext/ft_putchar_fd.c \
	lib/ft/ft_ext/ft_putendl_fd.c \
	lib/ft/ft_ext/ft_putnbr_fd.c \
	lib/ft/ft_ext/ft_putstr_fd.c \
	lib/ft/ft_ext/ft_split.c \
	lib/ft/ft_ext/ft_striteri.c \
	lib/ft/ft_ext/ft_strjoin.c \
	lib/ft/ft_ext/ft_strmapi.c \
	lib/ft/ft_ext/ft_strtrim.c \
	lib/ft/ft_ext/ft_substr.c

FT_EXT_OBJS := $(FT_EXT_SRCS:%.c=$(OBJDIR)/%.o)
