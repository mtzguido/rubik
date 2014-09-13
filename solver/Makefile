.PHONY: clean all re run

CFLAGS=-c -Wall -Wextra -pedantic -std=c99 -O99
MODS=$(wildcard *.c)
OBJS=$(patsubst %.c,%.o,$(MODS))
TARGET=rubik

all: $(TARGET)

%.o: %.c *.h
	$(CC) $(CFLAGS) $<	-o $@

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

re: clean all
