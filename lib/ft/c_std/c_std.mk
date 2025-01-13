# c_std.mk
# Parent ../../../Makefile
C_STD_SRCS := \
	lib/ft/c_std/ft_atoi.c \
	lib/ft/c_std/ft_bzero.c \
	lib/ft/c_std/ft_calloc.c \
	lib/ft/c_std/ft_isalnum.c \
	lib/ft/c_std/ft_isalpha.c \
	lib/ft/c_std/ft_isascii.c \
	lib/ft/c_std/ft_isdigit.c \
	lib/ft/c_std/ft_isprint.c \
	lib/ft/c_std/ft_isspace.c \
	lib/ft/c_std/ft_memchr.c \
	lib/ft/c_std/ft_memcmp.c \
	lib/ft/c_std/ft_memcpy.c \
	lib/ft/c_std/ft_memmove.c \
	lib/ft/c_std/ft_memset.c \
	lib/ft/c_std/ft_strchr.c \
	lib/ft/c_std/ft_strdup.c \
	lib/ft/c_std/ft_strlcat.c \
	lib/ft/c_std/ft_strlcpy.c \
	lib/ft/c_std/ft_strlen.c \
	lib/ft/c_std/ft_strncmp.c \
	lib/ft/c_std/ft_strnstr.c \
	lib/ft/c_std/ft_strrchr.c \
	lib/ft/c_std/ft_tolower.c \
	lib/ft/c_std/ft_toupper.c

C_STD_OBJS := $(C_STD_SRCS:%.c=$(OBJDIR)/%.o)
