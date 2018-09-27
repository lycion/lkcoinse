
Debian
====================
This directory contains files used to package lkcoinsed/lkcoinse-qt
for Debian-based Linux systems. If you compile lkcoinsed/lkcoinse-qt yourself, there are some useful files here.

## lkcoinsecash: URI support ##


lkcoinse-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install lkcoinse-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your lkcoinse-qt binary to `/usr/bin`
and the `../../share/pixmaps/lkcoinse128.png` to `/usr/share/pixmaps`

lkcoinse-qt.protocol (KDE)

