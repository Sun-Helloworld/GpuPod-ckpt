PLUGIN=ckptfile
CC = gcc
M32=0
CFLAGS = -g -O2
CPPFLAGS = 
CXX = g++
CXXFLAGS = -g -O2
LDFLAGS = 

# Allow the user to specify the install program.
INSTALL = /usr/bin/install -c
INSTALL_PROGRAM = ${INSTALL}
INSTALL_DATA = ${INSTALL} -m 644
INSTALL_SCRIPT = ${INSTALL}

MKDIR_P = /bin/mkdir -p
PACKAGE = dmtcp
PACKAGE_BUGREPORT = dmtcp-forum@lists.sourceforge.net
PACKAGE_NAME = DMTCP
PACKAGE_STRING = DMTCP 3.0.0
PACKAGE_TARNAME = dmtcp
PACKAGE_URL = http://dmtcp.sourceforge.net
PACKAGE_VERSION = 3.0.0
prefix=/usr/local
exec_prefix=${prefix}
datarootdir=${prefix}/share
bindir = ${exec_prefix}/bin
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
includedir = ${prefix}/include
infodir = ${datarootdir}/info
libdir = ${exec_prefix}/lib
pkglibdir = $(libdir)/dmtcp
top_builddir = ../..
top_srcdir = ../..
srcdir = .

targetdir = $(top_builddir)

ifeq ($(M32),1)
  targetdir = $(top_builddir)/lib/$(PACKAGE)/32
endif

LIBNAME=$(targetdir)/lib/${PACKAGE}/libdmtcp_${PLUGIN}.so

DMTCP_INCLUDE_PATH = $(top_srcdir)/include
JALIB_PATH = $(top_srcdir)/jalib

INCLUDES = -I$(JALIB_PATH) -I$(DMTCP_INCLUDE_PATH)

override CFLAGS += -fPIC
override CXXFLAGS += -fPIC
ifeq ($(M32),1)
CFLAGS += -m32 -Wa,--32
CXXFLAGS += -m32 -Wa,--32
LDFLAGS += -m32 -Wl,-m32 -Wl,-melf_i386 -Wa,--32
endif

COMPILE = $(CC) $(INCLUDES) $(CPPFLAGS) $(CFLAGS) -c -o $@
LINK = $(CC) $(CFLAGS) $(LDFLAGS) -o $@
CXXCOMPILE = $(CXX) $(INCLUDES) $(CPPFLAGS) $(CXXFLAGS) -c -o $@
CXXLINK = $(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@

HEADERS = $(DMTCP_INCLUDE_PATH)/util.h $(DMTCP_INCLUDE_PATH)/dmtcp.h \
	  $(JALIB_PATH)/jassert.h $(JALIB_PATH)/jalloc.h

OBJS = ckptfile.o

LIB_LDFLAGS = -shared -Wl,--unresolved-symbols=ignore-all

LDADD = -ldl -lpthread

all: default

default: build

build: ${LIBNAME}

tidy:
	rm -rf dmtcp-autotest-* ckpt_*_files
	rm -f ckpt_*.dmtcp dmtcp_restart_script* core*

clean: tidy
	-rm -f *.o
	-rm -f $(LIBNAME)

distclean: clean
	rm -f Makefile

install-libs: all
	${INSTALL_PROGRAM} ${LIBNAME} $(DESTDIR)$(pkglibdir)

uninstall-libs:
	rm -f $(DESTDIR)$(pkglibdir)/$(LIBNAME)

install: install-libs

uninstall: uninstall-libs

${LIBNAME}: $(OBJS) ${HEADERS}
	@rm -f ${LIBNAME}
	$(CXXLINK) $(OBJS) $(LIB_LDFLAGS) $(LDADD)

check: ${LIBNAME}
	@echo "Initializing..."
	@gcc -g -O0 test/ckpttest.c -o ./ckpttest
	@cp test/test1 test/test2 .
	@echo "${PWD}/test1:SAVE_AND_RESTORE=1;RESTART_PATH=/home/user/hello" >> ./test/ckptfiles.dat
	@echo "${PWD}/test2:SAVE_AND_RESTORE=0;RESTART_PATH=/tmp/test3" >> ./test/ckptfiles.dat
	DMTCP_CKPTFILES_DATA=./test/ckptfiles.dat ../../bin/dmtcp_launch --with-plugin ../../lib/dmtcp/libdmtcp_ckptfile.so  ./ckpttest &
	@sleep 3
	@echo "Checkpointing..."
	../../bin/dmtcp_command -bc
	../../bin/dmtcp_command -k
	@echo "Restarting..."
	rm -f ./test1 && cp ./test2 /tmp/test3 && rm -f ./test2
	../../bin/dmtcp_restart ckpt*.dmtcp
	@echo "Cleaning up..."
	@sleep 3
	rm -f ./ckpttest ./test1 ./test2 /tmp/test3 ./test/ckptfiles.dat
	rm -rf dmtcp-autotest-* ckpt_*_files
	rm -f ckpt_*.dmtcp dmtcp_restart_script*

%.o: %.c ${HEADERS}
	$(COMPILE)  $<

%.o: %.cpp ${HEADERS}
	$(CXXCOMPILE)  $<

.PHONY: default all build tidy clean distclean install uninstall
