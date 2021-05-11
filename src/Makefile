CC = gcc
RAYLIBPATH = C:\raylib
CFLAGS = $(RAYLIBPATH)\raylib\src\raylib.rc.data -s -static -O2 -std=c99 -Wall -Iexternal -I$(RAYLIBPATH)/src -DPLATFORM_DESKTOP
LDFLAGS = -lraylib -lopengl32 -lgdi32 -lwinmm
NAMEPART = watermelon
FILENAME =
FILENAME += watermelon.cpp
FILENAME += fruit.cpp
FILENAME += animation.cpp
FILENAME += button.cpp
FILENAME += digit.cpp
FILENAME += fruit_detect.cpp
FILENAME += fruit_mouse.cpp
FILENAME += fruit_move.cpp
FILENAME += fruit_merge.cpp
FILENAME += music.cpp
FILENAME += scene_game.cpp
FILENAME += scene_setting.cpp
FILENAME += scene_start.cpp

all:
	$(CC) -o $(NAMEPART).exe $(FILENAME) $(CFLAGS) $(LDFLAGS)
	cmd /c IF EXIST $(NAMEPART).exe $(NAMEPART).exe

