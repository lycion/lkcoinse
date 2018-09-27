#!/bin/bash
cd build/out || exit "run this from the gitian-builder directory"
mkdir -p tmp
cd tmp
rm -rf lkcoinse-0.11.2/ lkcoinseUnlimited-0.11.2/
tar xvfz ../lkcoinse-0.11.2-linux64.tar.gz
mv lkcoinse-0.11.2/ lkcoinseUnlimited-0.11.2/
find lkcoinseUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../lkcoinseUnlimited-0.11.2-linux64.tar.gz

rm -rf lkcoinseUnlimited-0.11.2/
tar xvfz ../lkcoinse-0.11.2-linux32.tar.gz
mv lkcoinse-0.11.2/ lkcoinseUnlimited-0.11.2/
find lkcoinseUnlimited-0.11.2 | sort | tar --no-recursion --mode='u+rw,go+r-w,a+X' --owner=0 --group=0 -c -T - | gzip -9n > ../lkcoinseUnlimited-0.11.2-linux32.tar.gz

rm -rf lkcoinse-0.11.2/ lkcoinseUnlimited-0.11.2/

cd ../../..
