.SECONDEXPANSION:
OBJS = reduce.o myrandom.o
reduce : ${OBJS}
	mpicc -o $@ $^
%.o : %.c
	mpicc -c -O2 $<

clean :
	rm -f reduce *.o *~
