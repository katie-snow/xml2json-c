dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.59)
AC_INIT(Xml2json-c, 0.1)

AC_CANONICAL_HOST
AM_INIT_AUTOMAKE()

AC_PROG_CC
AM_PROG_CC_C_O

AC_CONFIG_MACRO_DIR([m4])
LT_INIT

PKG_CHECK_MODULES([JSON], [json-c >= 0.11])
PKG_CHECK_MODULES([XML2], [libxml-2.0 >= 2.9.1])

AC_SUBST([XML2JSONC_LIB_VERSION], [0.1])

AC_CONFIG_FILES([Makefile 
                src/test/Makefile
                src/libs/Makefile             
                xml2json-c-${XML2JSONC_LIB_VERSION}.pc:xml2json-c.pc.in])
AC_OUTPUT

