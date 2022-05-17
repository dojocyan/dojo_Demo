
Debian
====================
This directory contains files used to package Dojochaind/Dojochain-qt
for Debian-based Linux systems. If you compile Dojochaind/Dojochain-qt yourself, there are some useful files here.

## Dojochain: URI support ##


Dojochain-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install Dojochain-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your Dojochain-qt binary to `/usr/bin`
and the `../../share/pixmaps/Dojochain128.png` to `/usr/share/pixmaps`

Dojochain-qt.protocol (KDE)

