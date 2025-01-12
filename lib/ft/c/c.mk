# c.mk
# Parent ../../../Makefile
C_SRCS := \
	lib/ft/c/ft_atoi.c \
	lib/ft/c/ft_bzero.c \
	lib/ft/c/ft_calloc.c \
	lib/ft/c/ft_isalnum.c \
	lib/ft/c/ft_isalpha.c \
	lib/ft/c/ft_isascii.c \
	lib/ft/c/ft_isdigit.c \
	lib/ft/c/ft_isprint.c \
	lib/ft/c/ft_memchr.c \
	lib/ft/c/ft_memcmp.c \
	lib/ft/c/ft_memcpy.c \
	lib/ft/c/ft_memmove.c \
	lib/ft/c/ft_memset.c \
	lib/ft/c/ft_strchr.c \
	lib/ft/c/ft_strdup.c \
	lib/ft/c/ft_strlcat.c \
	lib/ft/c/ft_strlcpy.c \
	lib/ft/c/ft_strlen.c \
	lib/ft/c/ft_strncmp.c \
	lib/ft/c/ft_strnstr.c \
	lib/ft/c/ft_strrchr.c \
	lib/ft/c/ft_tolower.c \
	lib/ft/c/ft_toupper.c

C_OBJS := $(C_SRCS:%.c=$(OBJDIR)/%.o)
