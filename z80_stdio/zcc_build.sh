#!/bin/bash

export PATH=/home/eric/projects/z88dk/bin:$PATH
export ZCCCFG=/home/eric/projects/z88dk/lib/config


zcc +z80 -m -g -s --max-allocs-per-node2000 -SO3 -startup=1 -clib=sdcc_iy @zproject.lst -o $1 -lm -create-app -pragma-include:simz80.inc --c-code-in-asm

scp $1.bin pi@192.168.7.2:/home/projects/z80_host

