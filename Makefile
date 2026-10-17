CC ?= gcc
AR ?= ar
RANLIB ?= ranlib
STRIP ?= strip

CFLAGS += -D_GNU_SOURCE -std=gnu99 -I. -Ishorkcommon -Os
LDFLAGS += -static

SRC = $(wildcard src/*.c)

shorkut: $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o shorkut $(LDFLAGS)
	$(STRIP) shorkut

PREFIX ?= /
BINDIR = $(PREFIX)/sbin

install: shorkut
	install -d $(DESTDIR)$(BINDIR)
	install -m 755 shorkut $(DESTDIR)$(BINDIR)

uninstall:
	rm -f $(DESTDIR)$(BINDIR)/shorkut

clean:
	rm -f shorkut

.PHONY: install uninstall clean
