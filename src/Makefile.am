# Copyright (c) 2013-2016 The Lkcoinse Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

DIST_SUBDIRS = secp256k1 univalue

AM_LDFLAGS = $(PTHREAD_CFLAGS) $(LIBTOOL_LDFLAGS) $(HARDENED_LDFLAGS)
if ENABLE_GPERF
AM_CXXFLAGS = -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free $(HARDENED_CXXFLAGS)
AM_CPPFLAGS = -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free $(HARDENED_CPPFLAGS)
else
AM_CXXFLAGS = $(HARDENED_CXXFLAGS) $(ERROR_CXXFLAGS)
AM_CPPFLAGS = $(HARDENED_CPPFLAGS)
endif
if ENABLE_GPERF
AM_CXXFLAGS += -pg
AM_CPPFLAGS += -pg
AM_LDFLAGS  += -pg
endif
if ENABLE_GPROF
AM_CXXFLAGS += -pg
AM_CPPFLAGS += -pg
AM_LDFLAGS  += -pg
endif
if ENABLE_MUTRACE
AM_CXXFLAGS += -O0 -g -rdynamic
AM_CPPFLAGS += -O0 -g -rdynamic
AM_LDFLAGS  += -O0 -g -rdynamic
endif
EXTRA_LIBRARIES =
# lilcsmalloc.a

LKCOINSE_CONFIG_INCLUDES=-I$(builddir)/config
LKCOINSE_INCLUDES=-I$(builddir) -I$(builddir)/obj $(BDB_CPPFLAGS) $(BOOST_CPPFLAGS) $(LEVELDB_CPPFLAGS) $(CRYPTO_CFLAGS) $(SSL_CFLAGS)

LKCOINSE_INCLUDES += -I$(srcdir)/secp256k1/include
LKCOINSE_INCLUDES += -I$(srcdir)/univalue/include

LIBLKCOINSE_SERVER=liblkcoinse_server.a
LIBLKCOINSE_COMMON=liblkcoinse_common.a
LIBLKCOINSE_CONSENSUS=liblkcoinse_consensus.a
LIBLKCOINSE_CLI=liblkcoinse_cli.a
LIBLKCOINSE_UTIL=liblkcoinse_util.a
LIBLKCOINSE_CRYPTO=crypto/liblkcoinse_crypto.a
LIBLKCOINSEQT=qt/liblkcoinseqt.a
LIBSECP256K1=secp256k1/libsecp256k1.la
LIBUNIVALUE=univalue/libunivalue.la

if ENABLE_ZMQ
LIBLKCOINSE_ZMQ=liblkcoinse_zmq.a
endif
if BUILD_LKCOINSE_LIBS
LIBLKCOINSECONSENSUS=liblkcoinseconsensus.la
LIBLKCOINSECASH=liblkcoinsecash.la
endif
if ENABLE_WALLET
LIBLKCOINSE_WALLET=liblkcoinse_wallet.a
endif

$(LIBSECP256K1): $(wildcard secp256k1/src/*) $(wildcard secp256k1/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

$(LIBUNIVALUE): $(wildcard univalue/lib/*) $(wildcard univalue/include/*)
	$(AM_V_at)$(MAKE) $(AM_MAKEFLAGS) -C $(@D) $(@F)

# Make is not made aware of per-object dependencies to avoid limiting building parallelization
# But to build the less dependent modules first, we manually select their order here:
EXTRA_LIBRARIES += \
  $(LIBLKCOINSE_CRYPTO) \
  $(LIBLKCOINSE_UTIL) \
  $(LIBLKCOINSE_COMMON) \
  $(LIBLKCOINSE_CONSENSUS) \
  $(LIBLKCOINSE_SERVER) \
  $(LIBLKCOINSE_CLI) \
  $(LIBLKCOINSE_WALLET) \
  $(LIBLKCOINSE_ZMQ)

lib_LTLIBRARIES = $(LIBLKCOINSECASH) $(LIBLKCOINSECONSENSUS)

bin_PROGRAMS =
noinst_PROGRAMS =
TESTS =
BENCHMARKS =

if BUILD_LKCOINSED
  bin_PROGRAMS += lkcoinsed
endif

if BUILD_LKCOINSE_UTILS
  bin_PROGRAMS += lkcoinse-cli lkcoinse-tx lkcoinse-miner
endif

.PHONY: FORCE check-symbols check-security check-formatting
# lkcoinse core #
LKCOINSE_CORE_H = \
  addrman.h \
  allowed_args.h \
  base58.h \
  bandb.h \
  banentry.h \
  blockstorage/blockleveldb.h \
  blockstorage/sequential_files.h \
  blockstorage/blockstorage.h \
  bitnodes.h \
  bloom.h \
  cashaddr.h \
  cashaddrenc.h \
  chain.h \
  chainparams.h \
  chainparamsbase.h \
  chainparamsseeds.h \
  checkpoints.h \
  checkqueue.h \
  clientversion.h \
  coincontrol.h \
  coins.h \
  compat.h \
  compat/byteswap.h \
  compat/endian.h \
  compat/sanity.h \
  compressor.h \
  config.h \
  connmgr.h \
  consensus/consensus.h \
  consensus/tx_verify.h \
  core_io.h \
  core_memusage.h \
  dosman.h \
  dstencode.h \
  expedited.h \
  fast-cpp-csv-parser/csv.h \
  forks_csv.h \
  fs.h \
  graphene.h \
  graphene_set.h \
  httprpc.h \
  httpserver.h \
  iblt.h \
  iblt_params.h \
  init.h \
  key.h \
  keystore.h \
  dbwrapper.h \
  limitedmap.h \
  main.h \
  memusage.h \
  merkleblock.h \
  miner.h \
  net.h \
  nodestate.h \
  leakybucket.h \
  netaddress.h \
  netbase.h \
  noui.h \
  parallel.h \
  policy/fees.h \
  policy/policy.h \
  pow.h \
  protocol.h \
  random.h \
  reverselock.h \
  rpc/client.h \
  rpc/protocol.h \
  rpc/server.h \
  rpc/register.h \
  respend/respendaction.h \
  respend/respendlogger.h \
  respend/respendrelayer.h \
  respend/respenddetector.h \
  scheduler.h \
  script/sigcache.h \
  script/sign.h \
  script/standard.h \
  script/ismine.h \
  streams.h \
  support/allocators/secure.h \
  support/allocators/zeroafterfree.h \
  support/cleanse.h \
  support/pagelocker.h \
  sync.h \
  thinblock.h \
  threadsafety.h \
  timedata.h \
  torcontrol.h \
  txdb.h \
  txmempool.h \
  txorphanpool.h \
  ui_interface.h \
  uahf_fork.h \
  undo.h \
  unlimited.h \
  stat.h \
  tweak.h \
  requestManager.h \
  util.h \
  utilmoneystr.h \
  utiltime.h \
  validationinterface.h \
  versionbits.h \
  wallet/crypter.h \
  wallet/db.h \
  wallet/rpcwallet.h \
  wallet/wallet.h \
  wallet/walletdb.h \
  zmq/zmqabstractnotifier.h \
  zmq/zmqconfig.h\
  zmq/zmqnotificationinterface.h \
  zmq/zmqpublishnotifier.h


obj/build.h: FORCE
	@$(MKDIR_P) $(builddir)/obj
	@$(top_srcdir)/share/genbuild.sh $(abs_top_builddir)/src/obj/build.h \
	  $(abs_top_srcdir)
liblkcoinse_util_a-clientversion.$(OBJEXT): obj/build.h

# server: shared between lkcoinsed and lkcoinse-qt
liblkcoinse_server_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES) $(MINIUPNPC_CPPFLAGS) $(EVENT_CFLAGS) $(EVENT_PTHREADS_CFLAGS)
liblkcoinse_server_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_server_a_SOURCES = \
  globals.cpp \
  addrman.cpp \
  bandb.cpp \
  banentry.cpp \
  bitnodes.cpp \
  blockstorage/blockleveldb.cpp \
  blockstorage/sequential_files.cpp \
  blockstorage/blockstorage.cpp \
  bloom.cpp \
  chain.cpp \
  checkpoints.cpp \
  connmgr.cpp \
  consensus/tx_verify.cpp \
  dosman.cpp \
  expedited.cpp \
  forks_csv.cpp \
  graphene.cpp \
  httprpc.cpp \
  httpserver.cpp \
  iblt.cpp \
  init.cpp \
  dbwrapper.cpp \
  main.cpp \
  merkleblock.cpp \
  miner.cpp \
  net.cpp \
  nodestate.cpp \
  noui.cpp \
  parallel.cpp \
  policy/fees.cpp \
  policy/policy.cpp \
  pow.cpp \
  rest.cpp \
  rpc/blockchain.cpp \
  rpc/mining.cpp \
  rpc/misc.cpp \
  rpc/net.cpp \
  rpc/rawtransaction.cpp \
  rpc/server.cpp \
  respend/respendlogger.cpp \
  respend/respendrelayer.cpp \
  respend/respenddetector.cpp \
  script/sigcache.cpp \
  thinblock.cpp \
  script/ismine.cpp \
  timedata.cpp \
  torcontrol.cpp \
  txdb.cpp \
  txmempool.cpp \
  txorphanpool.cpp \
  tweak.cpp \
  uahf_fork.cpp \
  unlimited.cpp \
  requestManager.cpp \
  validationinterface.cpp \
  versionbits.cpp \
  $(LKCOINSE_CORE_H)

if ENABLE_ZMQ
liblkcoinse_zmq_a_CPPFLAGS = $(LKCOINSE_INCLUDES) $(ZMQ_CFLAGS)
liblkcoinse_zmq_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_zmq_a_SOURCES = \
  zmq/zmqabstractnotifier.cpp \
  zmq/zmqnotificationinterface.cpp \
  zmq/zmqpublishnotifier.cpp
endif


# wallet: shared between lkcoinsed and lkcoinse-qt, but only linked
# when wallet enabled
liblkcoinse_wallet_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
liblkcoinse_wallet_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_wallet_a_SOURCES = \
  wallet/crypter.cpp \
  wallet/db.cpp \
  wallet/rpcdump.cpp \
  wallet/rpcwallet.cpp \
  wallet/wallet.cpp \
  wallet/walletdb.cpp \
  $(LKCOINSE_CORE_H)

liblkcoinsecash_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
liblkcoinsecash_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

# base58.cpp
#  base58.h

liblkcoinsecash_a_SOURCES = \
  cashlib/cashlib.cpp \
  script/sigcommon.cpp \
  hash.cpp \
  hash.h \
  key.cpp \
  key.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  random.cpp \
  random.h \
  support/pagelocker.cpp \
  support/pagelocker.h \
  support/cleanse.cpp \
  support/cleanse.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  utiltime.cpp \
  utiltime.h

# crypto primitives library
crypto_liblkcoinse_crypto_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_CONFIG_INCLUDES)
crypto_liblkcoinse_crypto_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
crypto_liblkcoinse_crypto_a_SOURCES = \
  crypto/aes.cpp \
  crypto/aes.h \
  crypto/common.h \
  crypto/hmac_sha256.cpp \
  crypto/hmac_sha256.h \
  crypto/hmac_sha512.cpp \
  crypto/hmac_sha512.h \
  crypto/ripemd160.cpp \
  crypto/ripemd160.h \
  crypto/sha1.cpp \
  crypto/sha1.h \
  crypto/sha256.cpp \
  crypto/sha256.h \
  crypto/sha512.cpp \
  crypto/sha512.h

if USE_ASM
crypto_liblkcoinse_crypto_a_SOURCES += crypto/sha256_sse4.cpp
endif

# consensus: shared between all executables that validate any consensus rules.
liblkcoinse_consensus_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
liblkcoinse_consensus_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_consensus_a_SOURCES = \
  amount.h \
  arith_uint256.cpp \
  arith_uint256.h \
  consensus/merkle.cpp \
  consensus/merkle.h \
  consensus/params.h \
  consensus/validation.h \
  hash.cpp \
  hash.h \
  prevector.h \
  primitives/block.cpp \
  primitives/block.h \
  primitives/transaction.cpp \
  primitives/transaction.h \
  pubkey.cpp \
  pubkey.h \
  script/lkcoinseconsensus.cpp \
  script/interpreter.cpp \
  script/interpreter.h \
  script/sigcommon.cpp \
  script/script.cpp \
  script/script.h \
  script/script_error.cpp \
  script/script_error.h \
  serialize.h \
  tinyformat.h \
  uint256.cpp \
  uint256.h \
  utilstrencodings.cpp \
  utilstrencodings.h \
  version.h

# common: shared between lkcoinsed, and lkcoinse-qt and non-server tools
liblkcoinse_common_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
liblkcoinse_common_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_common_a_SOURCES = \
  amount.cpp \
  base58.cpp \
  cashaddr.cpp \
  cashaddrenc.cpp \
  chainparams.cpp \
  pow.cpp \
  coins.cpp \
  compressor.cpp \
  config.cpp \
  core_read.cpp \
  core_write.cpp \
  dstencode.cpp \
  key.cpp \
  keystore.cpp \
  netaddress.cpp \
  netbase.cpp \
  protocol.cpp \
  scheduler.cpp \
  script/sign.cpp \
  script/standard.cpp \
  versionbits.cpp \
  chain.cpp \
  $(LKCOINSE_CORE_H)

# util: shared between all executables.
# This library *must* be included to make sure that the glibc
# backward-compatibility objects and their sanity checks are linked.
liblkcoinse_util_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
liblkcoinse_util_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_util_a_SOURCES = \
  support/pagelocker.cpp \
  allowed_args.cpp \
  chainparamsbase.cpp \
  clientversion.cpp \
  compat/glibc_sanity.cpp \
  compat/glibcxx_sanity.cpp \
  compat/strnlen.cpp \
  fs.cpp \
  random.cpp \
  rpc/protocol.cpp \
  support/cleanse.cpp \
  sync.cpp \
  ui_interface.cpp \
  util.cpp \
  utilmoneystr.cpp \
  utilstrencodings.cpp \
  utiltime.cpp \
  $(LKCOINSE_CORE_H)

if GLIBC_BACK_COMPAT
liblkcoinse_util_a_SOURCES += compat/glibc_compat.cpp
endif

# cli: shared between lkcoinse-cli and lkcoinse-qt
liblkcoinse_cli_a_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES) $(EVENT_CFLAGS)
liblkcoinse_cli_a_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
liblkcoinse_cli_a_SOURCES = \
  rpc/client.cpp \
  $(LKCOINSE_CORE_H)

nodist_liblkcoinse_util_a_SOURCES = $(srcdir)/obj/build.h
#

# lkcoinsed binary #
lkcoinsed_SOURCES = lkcoinsed.cpp
lkcoinsed_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
lkcoinsed_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
lkcoinsed_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
lkcoinsed_SOURCES += lkcoinsed-res.rc
endif

lkcoinsed_LDADD = \
  $(LIBLKCOINSE_SERVER) \
  $(LIBLKCOINSE_COMMON) \
  $(LIBUNIVALUE) \
  $(LIBLKCOINSE_UTIL) \
  $(LIBLKCOINSE_WALLET) \
  $(LIBLKCOINSE_ZMQ) \
  $(LIBLKCOINSE_CONSENSUS) \
  $(LIBLKCOINSE_CRYPTO) \
  $(LIBLEVELDB) \
  $(LIBLEVELDB_SSE42) \
  $(LIBMEMENV) \
  $(LIBSECP256K1)

lkcoinsed_LDADD += $(BOOST_LIBS) $(BDB_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(MINIUPNPC_LIBS) $(EVENT_PTHREADS_LIBS) $(EVENT_LIBS) $(ZMQ_LIBS)

# lkcoinse-cli binary #
lkcoinse_cli_SOURCES = lkcoinse-cli.cpp
lkcoinse_cli_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES) $(EVENT_CFLAGS)
lkcoinse_cli_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
lkcoinse_cli_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
lkcoinse_cli_SOURCES += lkcoinse-cli-res.rc
endif

lkcoinse_cli_LDADD = \
  $(LIBLKCOINSE_CLI) \
  $(LIBUNIVALUE) \
  $(LIBLKCOINSE_UTIL)

lkcoinse_cli_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# lkcoinse-tx binary #
lkcoinse_tx_SOURCES = lkcoinse-tx.cpp
lkcoinse_tx_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES)
lkcoinse_tx_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
lkcoinse_tx_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
lkcoinse_tx_SOURCES += lkcoinse-tx-res.rc
endif

lkcoinse_tx_LDADD = \
  $(LIBUNIVALUE) \
  $(LIBLKCOINSE_COMMON) \
  $(LIBLKCOINSE_UTIL) \
  $(LIBLKCOINSE_CONSENSUS) \
  $(LIBLKCOINSE_CRYPTO) \
  $(LIBSECP256K1)

lkcoinse_tx_LDADD += $(BOOST_LIBS) $(CRYPTO_LIBS)
#

# lkcoinse-miner binary #
lkcoinse_miner_SOURCES = lkcoinse-miner.cpp \
  arith_uint256.cpp \
  arith_uint256.h \
  uint256.cpp \
  uint256.h


lkcoinse_miner_CPPFLAGS = $(AM_CPPFLAGS) $(LKCOINSE_INCLUDES) $(EVENT_CFLAGS)
lkcoinse_miner_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)
lkcoinse_miner_LDFLAGS = $(RELDFLAGS) $(AM_LDFLAGS) $(LIBTOOL_APP_LDFLAGS)

if TARGET_WINDOWS
lkcoinse_miner_SOURCES += lkcoinse-miner-res.rc
endif

lkcoinse_miner_LDADD = \
  $(LIBLKCOINSE_CLI) \
  $(LIBLKCOINSE_CRYPTO) \
  $(LIBUNIVALUE) \
  $(LIBLKCOINSE_UTIL)

lkcoinse_miner_LDADD += $(BOOST_LIBS) $(SSL_LIBS) $(CRYPTO_LIBS) $(EVENT_LIBS)
#

# lkcoinsecash library #
if BUILD_LKCOINSE_LIBS
liblkcoinsecash_la_SOURCES = $(liblkcoinsecash_a_SOURCES) $(crypto_liblkcoinse_crypto_a_SOURCES)

if GLIBC_BACK_COMPAT
  liblkcoinsecash_la_SOURCES += compat/glibc_compat.cpp
endif

liblkcoinsecash_la_LDFLAGS = $(AM_LDFLAGS) $(SSL_LIBS) $(CRYPTO_LIBS) $(BOOST_LIBS) -no-undefined $(RELDFLAGS)
liblkcoinsecash_la_LIBADD = $(LIBSECP256K1)
liblkcoinsecash_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(BOOST_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_LKCOINSE_INTERNAL
liblkcoinsecash_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#

# lkcoinseconsensus library #
if BUILD_LKCOINSE_LIBS
include_HEADERS = script/lkcoinseconsensus.h
liblkcoinseconsensus_la_SOURCES = $(crypto_liblkcoinse_crypto_a_SOURCES) $(liblkcoinse_consensus_a_SOURCES)

if GLIBC_BACK_COMPAT
  liblkcoinseconsensus_la_SOURCES += compat/glibc_compat.cpp
endif

liblkcoinseconsensus_la_LDFLAGS = $(AM_LDFLAGS) $(BOOST_LIBS) -no-undefined $(RELDFLAGS)
liblkcoinseconsensus_la_LIBADD = $(LIBSECP256K1)
liblkcoinseconsensus_la_CPPFLAGS = $(AM_CPPFLAGS) -I$(BOOST_CPPFLAGS) -I$(builddir)/obj -I$(srcdir)/secp256k1/include -DBUILD_LKCOINSE_INTERNAL
liblkcoinseconsensus_la_CXXFLAGS = $(AM_CXXFLAGS) $(PIE_FLAGS)

endif
#
CLEANFILES = $(EXTRA_LIBRARIES)

CTAES_DIST =  crypto/ctaes/bench.c
CTAES_DIST += crypto/ctaes/ctaes.c
CTAES_DIST += crypto/ctaes/ctaes.h
CTAES_DIST += crypto/ctaes/README.md
CTAES_DIST += crypto/ctaes/test.c

CLEANFILES += *.gcda *.gcno
CLEANFILES += compat/*.gcda compat/*.gcno
CLEANFILES += consensus/*.gcda consensus/*.gcno
CLEANFILES += crypto/*.gcda crypto/*.gcno
CLEANFILES += policy/*.gcda policy/*.gcno
CLEANFILES += primitives/*.gcda primitives/*.gcno
CLEANFILES += script/*.gcda script/*.gcno
CLEANFILES += support/*.gcda support/*.gcno
CLEANFILES += univalue/*.gcda univalue/*.gcno
CLEANFILES += wallet/*.gcda wallet/*.gcno
CLEANFILES += wallet/test/*.gcda wallet/test/*.gcno
CLEANFILES += zmq/*.gcda zmq/*.gcno

DISTCLEANFILES = obj/build.h

EXTRA_DIST = leveldb $(CTAES_DIST)

clean-local:
	-$(MAKE) -C secp256k1 clean
	-$(MAKE) -C univalue clean
	-rm -f leveldb/*/*.gcda leveldb/*/*.gcno leveldb/helpers/memenv/*.gcda leveldb/helpers/memenv/*.gcno
	-rm -rf test/__pycache__

.rc.o:
	@test -f $(WINDRES)
	## FIXME: How to get the appropriate modulename_CPPFLAGS in here?
	$(AM_V_GEN) $(WINDRES) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(CPPFLAGS) -DWINDRES_PREPROC -i $< -o $@

.mm.o:
	$(AM_V_CXX) $(OBJCXX) $(DEFS) $(DEFAULT_INCLUDES) $(INCLUDES) $(AM_CPPFLAGS) \
	  $(CPPFLAGS) $(AM_CXXFLAGS) $(QT_INCLUDES) $(AM_CXXFLAGS) $(PIE_FLAGS) $(CXXFLAGS) -c -o $@ $<

check-symbols: $(bin_PROGRAMS)
if GLIBC_BACK_COMPAT
	@echo "Checking glibc back compat..."
	$(AM_V_at) READELF=$(READELF) CPPFILT=$(CPPFILT) $(top_srcdir)/contrib/devtools/symbol-check.py < $(bin_PROGRAMS)
endif

check-security: $(bin_PROGRAMS)
if HARDEN
	@echo "Checking binary security..."
	$(AM_V_at) READELF=$(READELF) OBJDUMP=$(OBJDUMP) $(top_srcdir)/contrib/devtools/security-check.py < $(bin_PROGRAMS)
endif

check-formatting:
	@echo "Checking source formatting style..."
	(cd $(top_srcdir)/src; ../contrib/devtools/clang-format.py check clang-format-3.8 `cat ./.formatted-files`)

%.pb.cc %.pb.h: %.proto
	@test -f $(PROTOC)
	$(AM_V_GEN) $(PROTOC) --cpp_out=$(@D) --proto_path=$(abspath $(<D) $<)

if EMBEDDED_LEVELDB
include Makefile.leveldb.include
endif

if ENABLE_TESTS
include Makefile.test.include
endif

if ENABLE_BENCH
include Makefile.bench.include
endif

if ENABLE_QT
include Makefile.qt.include
endif

if ENABLE_QT_TESTS
include Makefile.qttest.include
endif
