## Process this file with automake to produce Makefile.in

lib_LTLIBRARIES = libquicksort.la
libquicksort_la_SOURCES = quicksort.c quicksort.h

bin_PROGRAMS = quicksort 
quicksort_SOURCES = quicksort.c
quicksort_LDADD = libquicksort.la
quicksort_CFLAGS = $(AM_CFLAGS)
