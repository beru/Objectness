#!/bin/bash
# vim ft=sh


#subset='coco-full-100'
subset=$1
base_dir='/homes/ycli/rcnn/datasets/VOCdevkit2007/data/'
#prefix="gdb --args"
prefix=
result=$2


if [ ! -d $base_dir/$subset/IJCV2013 ]
then
    cwd=`pwd`
    cd ~/rcnn/
    matlab <<< "subset = '$subset'; dump_selective_search;"
    cd $cwd
fi
$prefix build/ijcv2013 $base_dir/$subset/ >> $result
