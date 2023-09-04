# A GUI to simulate and visualize 2d random walk, which in continuous space would be the Brownian motion. 

Tested to work with QT6 in Ubuntu22.0.4


## install QT6 if not yet installed
$ sudo apt install qt6-base-dev

## install opengl library
$ sudo apt install libgl-dev

## Build it.
$ qmake6 -project

$ qmake6 2drandom.pro

$ make

## Run it.
$ ./2drandom
## screenshot
![2d random walk](https://github.com/QiangbingLi/2d-randomwalk/blob/main/captures/Capture.PNG "2d randomwalk example")



