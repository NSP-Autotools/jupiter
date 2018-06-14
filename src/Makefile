all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(prefix)/bin
	install -m 0755 jupiter $(prefix)/bin

clean:
	rm -f jupiter

.PHONY: all clean check install
