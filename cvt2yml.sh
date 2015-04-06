#!/bin/bash
# vim ft=sh

#subset='coco-full-100'
#subset=$1

#base_dir='/homes/ycli/rcnn/datasets/VOCdevkit2007/data/'
annotation_dir=$1

cd Src
matlab <<< "wkDir = '$annotation_dir'; yml;"
cd ..
build/yaml2opencvyml $annotation_dir
