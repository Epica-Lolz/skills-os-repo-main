#1/bin/sh
set -e
. ./iso.sh

qemu-system-$(./target-triplet-to-arch $HOST) -cdrom myos.iso
