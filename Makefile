CC = g++
CFLAGS = -g -Wall
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

OBJS = main.o base/abstract_renderer.o obj/player.o

all: sfml

sfml: $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) -o $@ $(LDFLAGS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@