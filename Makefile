FLAGS := -lGL -lGLU -lglut -lm -I.
DEBUG_OPTION := -g
# Always put the flags in the end or it all goes haywire
CXX = g++ $(DEBUG_OPTION)
TRAPADV_H = components/trapadv.h
STATES_H = states.h
MAIN = main.cpp
MAIN_O = main

SPIKE_CPP = components/spike/spike.cpp
SPIKE_H = components/spike/spike.h
SPIKE_O = components/spike/spike.o
FINAL_BUILD = $(SPIKE_O)

INTRO_SCREEN_CPP = components/intro_screen/intro_screen.cpp
INTRO_SCREEN_H = components/intro_screen/intro_screen.h
INTRO_SCREEN_O = components/intro_screen/intro_screen.o
FINAL_BUILD += $(INTRO_SCREEN_O)

INST_SCREEN_CPP = components/inst_screen/inst_screen.cpp
INST_SCREEN_H = components/inst_screen/inst_screen.h
INST_SCREEN_O = components/inst_screen/inst_screen.o
FINAL_BUILD += $(INST_SCREEN_O)

DRAW_CPP = components/draw/draw.cpp
DRAW_H = components/draw/draw.h
DRAW_O = components/draw/draw.o
FINAL_BUILD += $(DRAW_O)

LEVEL1_CPP = components/level1/level1.cpp
LEVEL1_H = components/level1/level1.h
LEVEL1_O = components/level1/level1.o
FINAL_BUILD += $(LEVEL1_O)

R2D3_CPP = components/r2d3/r2d3.cpp
R2D3_H = components/r2d3/r2d3.h
R2D3_O = components/r2d3/r2d3.o
FINAL_BUILD += $(R2D3_O)

STATES_O = states.o
STATES_CPP = states.cpp
STATES_H = states.h
FINAL_BUILD += $(STATES_O)

all: draw intro_screen inst_screen spike level1 main run

run:
	./$(MAIN_O)

# compile:
# 	g++ -o main main.cpp components/spike/spike.cpp components/intro_screen/intro_screen.cpp components/inst_screen/inst_screen.cpp components/draw/draw.cpp components/level1/level1.cpp -lGL -lGLU -lglut -lm -I.
# draw: components/draw/draw.cpp
# 	g++ -c -o components/draw/draw.o components/draw/draw.cpp -lGL -lGLU  -lglut -lm -I.

main: $(MAIN) $(FINAL_BUILD) $(STATES_H) $(TRAPADV_H)
	$(CXX) -o $(MAIN_O) $(FINAL_BUILD) $(MAIN) $(FLAGS)

spike: $(SPIKE_H) $(SPIKE_CPP)
	$(CXX) -c -o $(SPIKE_O) $(SPIKE_CPP)

intro_screen: $(INTRO_SCREEN_CPP) $(INTRO_SCREEN_H)
	$(CXX) -c -o $(INTRO_SCREEN_O) $(INTRO_SCREEN_CPP)

inst_screen: $(INST_SCREEN_H) $(INST_SCREEN_CPP)
	$(CXX) -c -o $(INST_SCREEN_O) $(INST_SCREEN_CPP)

draw: $(DRAW_H) $(DRAW_CPP)
	$(CXX) -c -o $(DRAW_O) $(DRAW_CPP)

level1: $(LEVEL1_CPP) $(LEVEL1_H)
	$(CXX) -c -o $(LEVEL1_O) $(LEVEL1_CPP)

r2d3: $(R2D3_CPP) $(R2D3_H)
	$(CXX) -c -o $(R2D3_O) $(R2D3_CPP)

states: $(STATES_CPP) $(STATES_H)
	$(CXX) -c -o $(STATES_O) $(STATES_CPP)

clean:
	echo $(FINAL_BUILD)
	rm -f $(FINAL_BUILD) $(MAIN_O)

divyaksh_example: example.cpp
	g++ -o example example.cpp -lGL -lGLU -lglut -lm -I.
	./example
