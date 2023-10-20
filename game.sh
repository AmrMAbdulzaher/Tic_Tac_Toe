cd ./make_build_files

if [ "$(uname)" == "Linux" ]; then
    make game.out
    ./game.out
elif [ "$(expr substr $(uname -s) 1 10)" == "MINGW32_NT" ]; then
    mingw32-make game.exe
    start game.exe
fi
