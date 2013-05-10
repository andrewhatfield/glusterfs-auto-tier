
xlator_LTLIBRARIES = vs.la
xlatordir = $(libdir)/glusterfs/$(PACKAGE_VERSION)/xlator/cluster

vs_source = vs.c \
	$(top_builddir)/xlators/lib/src/libxlator.c

vs_la_SOURCES = $(vs_source)

#dht_common_source = dht-layout.c dht-helper.c dht-linkfile.c dht-rebalance.c \
#	dht-selfheal.c dht-rename.c dht-hashfn.c dht-diskusage.c \
#	dht-common.c dht-inode-write.c dht-inode-read.c dht-shared.c \
#	$(top_builddir)/xlators/lib/src/libxlator.c

#dht_la_SOURCES = $(dht_common_source) dht.c

#nufa_la_SOURCES = $(dht_common_source) nufa.c
#switch_la_SOURCES = $(dht_common_source) switch.c

#dht_la_LDFLAGS = -module -avoid-version
#dht_la_LIBADD = $(top_builddir)/libglusterfs/src/libglusterfs.la

vs_la_LDFLAGS = -module -avoid-version
vs_la_LIBADD = $(top_builddir)/libglusterfs/src/libglusterfs.la

noinst_HEADERS = vs.h \
	$(top_builddir)/xlators/lib/src/libxlator.h

#noinst_HEADERS = dht-common.h dht-mem-types.h \
#	$(top_builddir)/xlators/lib/src/libxlator.h

AM_CPPFLAGS = $(GF_CPPFLAGS) -I$(top_srcdir)/libglusterfs/src \
	-I$(top_srcdir)/xlators/lib/src

AM_CFLAGS = -Wall $(GF_CFLAGS)

CLEANFILES =

uninstall-local:
	rm -f $(DESTDIR)$(xlatordir)/vs.so

install-data-hook:
	ln -sf vs.so $(DESTDIR)$(xlatordir)/vs.so
