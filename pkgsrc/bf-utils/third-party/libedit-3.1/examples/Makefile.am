
LDADD = ../src/libedit.la
AM_CFLAGS = -I../src
#LDADD = $(top_builddir)/src/libedit.la
#AM_CFLAGS = -I$(top_srcdir)/src

noinst_PROGRAMS  = tc1 fileman

tc1_SOURCES      = tc1.c
fileman_SOURCES  = fileman.c

if WIDECHAR
noinst_PROGRAMS += wtc1
wtc1_SOURCES     = wtc1.c
endif

