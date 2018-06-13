all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	cp jupiter /usr/bin
	chown root:root /usr/bin/jupiter
	chmod +x /usr/bin/jupiter

clean:
	rm -f jupiter

.PHONY: all clean check install
