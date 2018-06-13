all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

clean:
	rm -f jupiter

.PHONY: all clean check
