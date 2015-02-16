AM_CFLAGS = $(JSON_CFLAGS) $(XML2_CFLAGS)
AM_LDFLAGS = $(JSON_LIBS) $(XML2_LIBS)

bin_PROGRAMS=xml2jsonc
xml2jsonc_SOURCES=main.c
xml2jsonc_CPPFLAGS = -I$(top_srcdir)/src
xml2jsonc_LDADD = ../libs/libxml2json-c-0.1.la

