main.obj: ../Main/main.c
	gcc -c ../Main/main.c -o main.obj

multiplayer.obj: ../Multiplayer/multiplayer.c ../Appearance_Functions/appearance.h
	gcc -c ../Multiplayer/multiplayer.c -o multiplayer.obj

singleplayer.obj: ../Singleplayer/singleplayer.c ../Multiplayer/multiplayer.h
	gcc -c ../Singleplayer/singleplayer.c -o singleplayer.obj

generalfunctions.obj: ../General_Functions/generalfunctions.c ../Singleplayer/singleplayer.h
	gcc -c ../General_Functions/generalfunctions.c -o generalfunctions.obj

appearance.obj: ../Appearance_Functions/appearance.c ../General_Functions/generalfunctions.h
	gcc -c ../Appearance_Functions/appearance.c -o appearance.obj

game.exe: main.obj multiplayer.obj singleplayer.obj generalfunctions.obj appearance.obj
	gcc main.obj multiplayer.obj singleplayer.obj generalfunctions.obj appearance.obj -o game.exe

game.out: main.obj multiplayer.obj singleplayer.obj generalfunctions.obj appearance.obj
	gcc main.obj multiplayer.obj singleplayer.obj generalfunctions.obj appearance.obj -o game.out
