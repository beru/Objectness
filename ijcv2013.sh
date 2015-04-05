#!/bin/bash
# vim ft=sh


#subset='coco-full-100'
subset=$1
base_dir='/homes/ycli/rcnn/datasets/VOCdevkit2007/data/'
#prefix="gdb --args"
prefix=
$prefix build/ijcv2013 $base_dir/$subset/
