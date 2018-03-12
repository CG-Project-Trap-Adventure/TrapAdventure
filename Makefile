compile:
	g++ -o main main.cpp components/spike/spike.cpp components/intro_screen/intro_screen.cpp components/draw/draw.cpp -lGL -lGLU -lglut -lm -I.