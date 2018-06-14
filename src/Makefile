all: jupiter

jupiter: main.c
	gcc -g -O0 -o $@ main.c

check: all
	./jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(DESTDIR)$(bindir)
	install -m 0755 jupiter $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/jupiter
	-rmdir $(DESTDIR)$(bindir) >/dev/null 2>&1

clean:
	rm -f jupiter

.PHONY: all clean check install uninstall
