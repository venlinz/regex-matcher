# simple make file


CC		=	gcc
CFLAGS	=	-Wall -g

aorb: main.c args.o aorb.o dir.o
	$(CC) $(CFLAGS) $^ -o $@

aorb.o: aorb.c aorb.h
	$(CC) $(CFLAGS) -c $^

dir.o: dir.h dir.c
	$(CC) $(CFLAGS) -c $^

args.o: args.c args.h
	$(CC) $(CFLAGS) -c $^
