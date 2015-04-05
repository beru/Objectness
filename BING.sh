#!/bin/bash
# vim ft=sh

subset=$1
base_dir='/homes/ycli/rcnn/datasets/VOCdevkit2007/data/'
prefix="gdb --args"
prefix=
$prefix build/objNess $base_dir/$subset/
