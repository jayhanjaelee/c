DIR="build"

if [ ! -d "$DIR" ]; then
  mkdir -p "$DIR"
fi

cmake . -B $DIR
cd build/
make
cd ..
./build/main
