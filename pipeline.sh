#!/bin/bash
# vim ft=sh


ts=`date '+%F-%H-%M-%S'`
subsets=(coco-full-100 coco-full-101 coco-full-102 coco-full-103 coco-subset-100)
#subsets=(coco-subset-100)
rm -f results.$ts
result=results/results.$ts
mkdir -p results
for subset in ${subsets[@]}
do
    ./cvt2yml.sh $subset
    echo $subset >> $result
    ./BING.sh $subset >> $result
    ./ijcv2013.sh $subset $result
done

python ~/rcnn/email_notify.py "BING evaluation $0 Done $ts"
