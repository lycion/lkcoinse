# Image Sources

The directory contains source images for a lot of the images and icons used in the client.

It also contains iconmaker.py, a small python program that generates icon images of various sizes and formats.

## iconmaker.py Required Packages
sudo apt-get install icnsutils imagemagick
pip install Pillow

## Running iconmaker.py

```bash
./iconmaker.py <1024px square png file>  <output filename prefix>

./iconmaker.py with no args runs "./iconmaker.py icon1024.png lkcoinse"
```

## Handling the output

The following recipe puts the output files in the appropriate locations for this project:

```bash
cp *.xpm ../../share/pixmaps
cp lkcoinse*.png ../../share/pixmaps/
cp lkcoinse.ico ../../share/pixmaps/lkcoinse.ico 
cp lkcoinse.ico ../../src/qt/res/icons
cp lkcoinse.icns ../../src/qt/res/icons
cp lkcoinse512.png ../../src/qt/res/icons/lkcoinse.png

rm lkcoinse*.png
```
