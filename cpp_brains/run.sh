[ -d "./build" ] || (mkdir build && cd build && cmake .. && cd ..)
cp ./Roboto-Black.ttf ./build
cd build 
make && ./net_brains
cd ..