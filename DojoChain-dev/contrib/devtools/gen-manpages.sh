#!/bin/sh

TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
SRCDIR=${SRCDIR:-$TOPDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

DojoCHAIND=${DojoCHAIND:-$SRCDIR/Dojochaind}
DojoCHAINCLI=${DojoCHAINCLI:-$SRCDIR/Dojochain-cli}
DojoCHAINTX=${DojoCHAINTX:-$SRCDIR/Dojochain-tx}
DojoCHAINQT=${DojoCHAINQT:-$SRCDIR/qt/Dojochain-qt}

[ ! -x $DojoCHAIND ] && echo "$DojoCHAIND not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
BTCVER=($($DojoCHAINCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }'))

# Create a footer file with copyright content.
# This gets autodetected fine for Dojochaind if --version-string is not set,
# but has different outcomes for Dojochain-qt and Dojochain-cli.
echo "[COPYRIGHT]" > footer.h2m
$DojoCHAIND --version | sed -n '1!p' >> footer.h2m

for cmd in $DojoCHAIND $DojoCHAINCLI $DojoCHAINTX $DojoCHAINQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BTCVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BTCVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
