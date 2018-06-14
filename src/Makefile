all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(prefix)/bin
	install -m 0755 jupiter $(prefix)/bin

uninstall:
	rm -f $(prefix)/bin/jupiter
	-rmdir $(prefix)/bin >/dev/null 2>&1

clean:
	rm -f jupiter

.PHONY: all clean check install uninstall
