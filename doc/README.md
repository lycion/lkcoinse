Lkcoinse Unlimited 0.12.1b
=========================

Setup
---------------------
[Lkcoinse Unlimited](http://www.lkcoinse.info) is a fork of the original Lkcoinse client and it builds the backbone of the network.  It downloads and stores the entire history of Lkcoinse transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more.

- [Getting the most out of Xtreme thinblocks](bu-xthin.md)
- [Setting up an Xpedited Relay Network](bu-xpedited-forwarding.md)

Running
---------------------
The following are some helpful notes on how to run Lkcoinse on your native platform.

### Unix

Unpack the files into a directory and run:

- `bin/lkcoinse-qt` (GUI) or
- `bin/lkcoinsed` (headless)

### Windows

Unpack the files into a directory, and then run lkcoinse-qt.exe.

### OS X

Drag Lkcoinse-Unlimited to your applications folder, and then run Lkcoinse-Unlimited.

### Need Help?

* See the documentation at the [Lkcoinse Wiki](https://en.lkcoinse.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#lkcoinse](http://webchat.freenode.net?channels=lkcoinse) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=lkcoinse).
* Ask for help on the [LkcoinseTalk](https://lkcoinsetalk.org/) forums, in the [Technical Support board](https://lkcoinsetalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Lkcoinse on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [Dependencies](dependencies.md)
- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)
- [Windows Build Notes](build-windows.md)
- [OpenBSD Build Notes](build-openbsd.md)
- [Gitian Building Guide](gitian-building.md)

Development
---------------------
The Lkcoinse repo's [root README](/README.md) contains relevant information on the development process and automated testing.

- [Developer Notes](developer-notes.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/lkcoinse/doxygen/)
- [Translation Process](translation_process.md)
- [Translation Strings Policy](translation_strings_policy.md)
- [Unit Tests](unit-tests.md)
- [Unauthenticated REST Interface](REST-interface.md)
- [Shared Libraries](shared-libraries.md)
- [BIPS](bips.md)
- [Dnsseed Policy](dnsseed-policy.md)

### Resources
* Discuss on the [LkcoinseTalk](https://lkcoinsetalk.org/) forums, in the [Development & Technical Discussion board](https://lkcoinsetalk.org/index.php?board=6.0).
* Discuss project-specific development on #lkcoinse-core-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=lkcoinse-core-dev).
* Discuss general Lkcoinse development on #lkcoinse-dev on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=lkcoinse-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Fuzz-testing](fuzzing.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
