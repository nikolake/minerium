
Debian
====================
This directory contains files used to package mineriumd/minerium-qt
for Debian-based Linux systems. If you compile mineriumd/minerium-qt yourself, there are some useful files here.

## minerium: URI support ##


minerium-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install minerium-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your minerium-qt binary to `/usr/bin`
and the `../../share/pixmaps/minerium128.png` to `/usr/share/pixmaps`

minerium-qt.protocol (KDE)

