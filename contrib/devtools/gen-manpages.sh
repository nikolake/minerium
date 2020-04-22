#!/bin/bash

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

MINERIUMD=${MINERIUMD:-$BINDIR/mineriumd}
MINERIUMCLI=${MINERIUMCLI:-$BINDIR/minerium-cli}
MINERIUMTX=${MINERIUMTX:-$BINDIR/minerium-tx}
MINERIUMQT=${MINERIUMQT:-$BINDIR/qt/minerium-qt}

[ ! -x $MINERIUMD ] && echo "$MINERIUMD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($MINERIUMCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for mineriumd if --version-string is not set,
# but has different outcomes for minerium-qt and minerium-cli.
echo "[COPYRIGHT]" > footer.h2m
$MINERIUMD --version | sed -n '1!p' >> footer.h2m

for cmd in $MINERIUMD $MINERIUMCLI $MINERIUMTX $MINERIUMQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
