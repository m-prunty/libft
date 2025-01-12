# bonus.mk
# Parent: ../../../Makefile
BONUS_SRCS := \
	lib/ft/bonus/ft_lstadd_back.c \
	lib/ft/bonus/ft_lstadd_front.c \
	lib/ft/bonus/ft_lstclear.c \
	lib/ft/bonus/ft_lstdelone.c \
	lib/ft/bonus/ft_lstiter.c \
	lib/ft/bonus/ft_lstlast.c \
	lib/ft/bonus/ft_lstmap.c \
	lib/ft/bonus/ft_lstnew.c \
	lib/ft/bonus/ft_lstsize.c

BONUS_OBJS := $(BONUS_SRCS:%.c=$(OBJDIR)/%.o)
