CFLAGS = -g -O0

src/jupiter: src/main.c
	$(CC) $(CPPFLAGS) $(CFLAGS) -Isrc -I$(srcdir)/src -I. -o $@ $(srcdir)/src/main.c

check: all
	./src/jupiter | grep "Hello from .*jupiter!"
	@echo "*** ALL TESTS PASSED ***"

install:
	install -d $(DESTDIR)$(bindir)
	install -m 0755 src/jupiter $(DESTDIR)$(bindir)

uninstall:
	rm -f $(DESTDIR)$(bindir)/jupiter
	-rmdir $(DESTDIR)$(bindir) >/dev/null 2>&1

clean:
	rm -f src/jupiter
