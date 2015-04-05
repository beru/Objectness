#!/bin/bash
# vim ft=sh


ts=`date '+%F-%H-%M-%S'`
subsets=(coco-full-100 coco-full-101 coco-full-102 coco-full-103 coco-subset-100)
rm -f results.$ts
for subset in ${subsets[@]}
do
    ./cvt2yml.sh $subset
    echo $subset >> results.$ts
    ./BING.sh $subset >> results.$ts
    ./ijcv2013.sh $subset >> results.$ts
done

python ~/rcnn/email_notify.py "BING evaluation $0 Done $ts"
