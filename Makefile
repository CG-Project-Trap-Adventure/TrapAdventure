all: compile run

compile:
	g++ -o main main.cpp components/spike/spike.cpp components/intro_screen/intro_screen.cpp components/inst_screen/inst_screen.cpp components/draw/draw.cpp components/level1/level1.cpp -lGL -lGLU -lglut -lm -I.
# draw: components/draw/draw.cpp
# 	g++ -c -o components/draw/draw.o components/draw/draw.cpp -lGL -lGLU  -lglut -lm -I.
run:
	./main

divyaksh_example:
	g++ -o example example.cpp -lGL -lGLU -lglut -lm -I.
