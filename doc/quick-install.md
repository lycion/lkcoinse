Installing BU from sources and from Ubuntu repos
======================================

Really quick guide to get your lkcoinsed/qt up and running

Installing binaries from Lkcoinse Unlimited Official BU repositories
------------------------------------------------------------------

This is valid for Ubuntu Trusty 14.04 and Xenial 16.04. The repos will provide binaries and debug symbols for 4 different architectures: i386, amd64, armhf and arm64.


```sh
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:lkcoinse-unlimited/bu-ppa
sudo apt-get update
sudo apt-get install lkcoinsed lkcoinse-qt (# on headlesse server just install lkcoinsed)
```

If you are moving from another Lkcoinse compatible implementations (Core, Classic, XT) to BU, make sure to follow this plan before moving:

- backup your wallet (if any)
- make a backup of the `~/.lkcoinse` dir
- if you have installed Core via apt using the ppa lkcoinse core repo:
   - `sudo apt-get remove lkcoinse*`
   - `sudo rm /etc/apt/sources.list.d/lkcoinse-*.*`
- if you have compile Core from source:
   - `cd /path/where/the/code/is/stored`
   - `sudo make uninstall`

Other than the PPA repo mentioned above, serving stable version of Lkcoinse Unlimited, we have set up another repository which will contain binaries built from source code snapshots of the BU development branch (`0.12.1bu` currently). If you're interested in testing the latest features included in BU but still not released just add this repository to your system. Use this commands:

```sh
sudo add-apt-repository ppa:lkcoinse-unlimited/bu-ppa-nightly
sudo apt-get update
sudo apt-get install lkcoinsed lkcoinse-qt
```
In case you installed both repos on your system, take into account that binaries belonging to the `nightly` will supersede the ones of the stable one.

Compiling and installing binaries source:
---------------------------------------

This is valid for Ubuntu Trusty 14.04 and Xenial 16.04.

### Installing pre-reqs

If you need `lkcoinsed` and `lkcoinse-cli` only:

```sh
sudo apt-get install git
sudo apt-get install build-essential libtool autotools-dev
sudo apt-get install automake pkg-config libssl-dev libevent-dev bsdmainutils libboost-all-dev
```

If you want also to install `lkcoinse-qt`:

```sh
sudo apt-get install libqt4-dev libprotobuf-dev protobuf-compiler libqrencode
```

This is step is optional, to be done only if you need if you need wallet functionality and you want your wallet created with an earlier version of lkcoinsed

```sh
sudo apt-get install software-properties-common
sudo add-apt-repository ppa:lkcoinse-unlimited/bu-ppa
sudo apt-get update
sudo apt-get install libdb4.8-dev libdb4.8++-dev
```

### Fetching the code and compile it


```sh
mkdir -p ~/src
cd ~/src
git clone https://github.com/Lkcoinse/Lkcoinse.git bu-src
cd bu-src
git checkout <desired_branch/tag>   # e.g. git checkout 0.12.1c
./autogen.sh
# if you want a plain lkcoinsed binary without GUI withou wallet support, use this configure line:
./configure --disable-wallet --without-gui
# otherwise if you need lkcoinse-qt just issue a plain ./configure
export NUMCPUS=`grep -c '^processor' /proc/cpuinfo`
make -j$NUMCPUS
sudo make install #(will place them in /usr/local/bin, this is step is to be considered optional.)
```

### Miscellaneous


- `strip(1)` your binaries, lkcoinsed will get a lot smaller, from 73MB to 4.3MB)
- execute `lkcoinsed` using the `-daemon` option, bash will fork lkcoinse process without cluttering the stdout

