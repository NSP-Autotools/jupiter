all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(bindir)
	install -m 0755 jupiter $(bindir)

uninstall:
	rm -f $(bindir)/jupiter
	-rmdir $(bindir) >/dev/null 2>&1

clean:
	rm -f jupiter

.PHONY: all clean check install uninstall
