CFILES := $(wildcard src/*.c)
FLAGS := -std=c99 -lm
DEBUG_FLAGS := -DDEBUG -g

app.exe: $(patsubst src/%.c, ./%.o, $(CFILES))
	gcc $(FLAGS) $^ -o $@

debug: $(patsubst src/%.c, ./%.o, $(CFILES))
	gcc $(FLAGS) $^ -o app.exe

run: app.exe
	./app.exe

clean:
	rm *.o *.exe *.d *.out *.dot *.png

%.o: src/%.c
	gcc $(FLAGS) -c -MD $<
