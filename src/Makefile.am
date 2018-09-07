SUBDIRS = modules/hithere

bin_PROGRAMS = jupiter
jupiter_SOURCES = main.c module.h
jupiter_CPPFLAGS = -I$(top_srcdir)/include
jupiter_LDADD = ../libjup/libjupiter.la -dlopen modules/hithere/hithere.la
