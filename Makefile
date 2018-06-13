package = jupiter
version = 1.0
tarname = $(package)
distdir = $(tarname)-$(version)

all clean jupiter:
	cd src && $(MAKE) $@

dist: $(distdir).tar.gz

$(distdir).tar.gz: $(distdir)
	tar chof - $(distdir) | gzip -9 -c > $@
	rm -rf $(distdir)

$(distdir): FORCE
	mkdir -p $(distdir)/src
	cp Makefile $(distdir)
	cp src/Makefile src/main.c $(distdir)/src

FORCE:
	rm -f $(distdir).tar.gz
	rm -rf $(distdir)

.PHONY: FORCE all clean dist
