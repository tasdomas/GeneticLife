CFLAGS = -O0 -Wall -ggdb3

SRCS = \
	lib_life.c\
	gl.c

OBJS := $(patsubst %.c,%.o,$(SRCS))

all: clean gl

.o: .c
	$(CC) -c $< -o $@ $(CFLAGS)

gl: $(OBJS)
	$(CC) $(CFLAGS)\
		$(OBJS)\
	 	-o gl

clean:
	rm -f $(OBJS) gl
