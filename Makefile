NAME = libft.a
FLAGS = -Wall  -Werror -Wextra  -g

BDIR = bonus
PDIR = ft_printf
GDIR = get_next_line
EDIR = extras
INC = include

SRC = ${wildcard *.c}
BSRC = ${wildcard $(BDIR)/ft_*.c}
PSRC = ${wildcard $(PDIR)/ft_*.c}
GSRC = ${wildcard $(GDIR)/*bonus.c}
ESRC = ${wildcard $(EDIR)/ft_*.c}

OBJECTS = $(SRC:.c=.o)
BOBJECTS = $(BSRC:.c=.o)
POBJECTS = $(PSRC:.c=.o)
GOBJECTS = $(GSRC:.c=.o)
EOBJECTS = $(ESRC:.c=.o)

SOLIB =  lib 
CC = gcc ${FLAGS} -I${INC}/ -c 

ALL_OBJS = $(OBJECTS) $(BOBJECTS) $(POBJECTS) $(GOBJECTS) $(EOBJECTS)

all: $(NAME) clean

$(NAME): $(ALL_OBJS)
	$(AR) -rcs $@ $^

bonus: $(OBJECTS) $(BOBJECTS)
	$(AR) -rcs $(NAME)  $?

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(ALL_OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all


#########################


ifeq ("x","y")

all: bonus print gnl ${NAME}  
	${MAKE} so
	${MAKE} clean 


bonus:
	${CC} ${BSRC}
	ar rcs ${BDIR}.apt *.o

print: 
	${CC} ${PSRC}
	ar rcs ${PDIR}.apt *.o

gnl:
	@cp ${GNLSRC} .


${NAME}:
	${CC} ${SRC}
	ar rcs ${NAME}.a *.o

so:	
	gcc -shared -o libft.so -Wl,--whole-archive ${wildcard *.a} -Wl,--no-whole-archive ${wildcard *.apt} 
	##$(CC) -nostartfiles -fPIC $(FLAGS) $(SRC)
	##gcc -nostartfiles -shared -o libft.so $(OBJ) 
	##${clean}

clean:
	rm -f *.o

fclean: clean
	rm -f *.a *.apt *.so

re:	fclean all

.PHONY : all all_so clean fclean re so bonus print 



endif
