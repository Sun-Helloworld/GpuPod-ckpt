CC=gcc
CXX=g++
EXTRAMAKEFLAGS=CC="${CC}" CXX="${CXX}"

PLUGINS=$(dir $(wildcard */Makefile))

default:
	for file in $(PLUGINS); do \
	  ( cd $$file && ${MAKE} ${EXTRAMAKEFLAGS} ); \
	done

tidy:
	for file in $(PLUGINS); do \
	  ( cd $$file && ${MAKE} ${EXTRAMAKEFLAGS} tidy ); \
	done

clean:
	for file in $(PLUGINS); do \
	  ( cd $$file && ${MAKE} ${EXTRAMAKEFLAGS} clean ); \
	done

distclean:
	for file in $(PLUGINS); do \
	  ( cd $$file && ${MAKE} ${EXTRAMAKEFLAGS} distclean ); \
	done
	rm -f Makefile

.PHONY: default clean distclean
