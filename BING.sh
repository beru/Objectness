#!/bin/bash
# vim ft=sh

wkDir=$1
prefix="gdb --args"
#prefix=
$prefix build/objNess $wkDir
