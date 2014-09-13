.PHONY: clean all re run

cflags=-c -Wall -O99
mods=$(wildcard *.c)
objs=$(patsubst %.c,%.o,$(mods))
final=checker

all: $(final)

%.o: %.c $(wildcard *.h)
	gcc $(cflags) $<	-o $@

$(final): $(objs)
	gcc $(objs) -o $(final)

clean:
	rm -f $(objs) $(final)

re: clean all

run: $(final)
	cp ../solver/rubik .
	./$(final) 5000
