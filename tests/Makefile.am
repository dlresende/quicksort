## Process this file with automake to produce Makefile.in

TESTS = check_quicksort
check_PROGRAMS = check_quicksort
check_quicksort_SOURCES = check_quicksort.c $(top_builddir)/src/quicksort.h
check_quicksort_CFLAGS = @CHECK_CFLAGS@
check_quicksort_LDADD = $(top_builddir)/src/libquicksort.la @CHECK_LIBS@
