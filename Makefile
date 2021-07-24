# simple make file


CC		=	gcc
CFLAGS	=	-Wall -g


reg : main.c args.o regex.o dir.o misc.o bufio.o
	$(CC) $(CFLAGS) $^ -o $@

aorb.o : regex.c regex.h
	$(CC) $(CFLAGS) -c $^

dir.o : dir.h dir.c
	$(CC) $(CFLAGS) -c $^

args.o : args.c args.h
	$(CC) $(CFLAGS) -c $^

misc.o : misc.c misc.h
	$(CC) $(CFLAGS) -c $^

bufio.o : bufio.c bufio.h
	$(CC) $(CFLAGS) -c $^

.PHONY : cleanall
cleanall :
	-rm aorb *.o
	-rm *.gch

.PHONY : clean 
clean :
	-rm *.o
	-rm *.gch

.PHONY : cleanin
cleanin :
	-rm *.gch

.PHONY : fast
fast : main.c args.o aorb.o dir.o misc.o bufio.o
	$(CC) -O2 $^ -o $@
