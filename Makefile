NAME = libft
FLAGS = -Wall  -Werror -Wextra  

BONUSDIR = bonus
PRINTDIR = ft_printf
GNLDIR = get_next_line

SRC = ${wildcard ft_*.c}
BSRC = ${wildcard $(BONUSDIR)/ft_*.c}
PSRC = ${wildcard $(PRINTDIR)/ft_*.c}
GNLSRC = ${wildcard $(GNLDIR)/*bonus.c}

SOLIB =  lib 
CC = cc

all: bonus print gnl ${NAME}  
	${MAKE} so
	${MAKE} clean 


bonus:
	@cp libft.h $(BONUSDIR)
	gcc ${FLAGS} -c ${BSRC}
	ar rcs ${BONUSDIR}.apt *.o

print: 
	@cp libft.h $(PRINTDIR)
	gcc ${FLAGS} -c ${PSRC}
	ar rcs ${PRINTDIR}.apt *.o

gnl:
	gcc ${FLAGS} -c ${GNLSRC}
	ar rcs ${GNLDIR}.apt *.o


${NAME}:
	gcc ${FLAGS} -c ${SRC}
	ar rcs ${NAME}.a *.o

so:	
	gcc -shared -o libft.so -Wl,--whole-archive ${wildcard *.a} -Wl,--no-whole-archive ${wildcard *.apt} 
##$(CC) -nostartfiles -fPIC $(FLAGS) $(SRC)
##gcc -nostartfiles -shared -o libft.so $(OBJ) 
##${clean}

clean::
	rm -f *.o

fclean: clean
	rm -f *.a *.apt *.so

re:	fclean all

.PHONY : all all_so clean fclean re so bonus print 
	
