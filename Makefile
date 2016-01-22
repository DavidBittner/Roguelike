C = g++
CF = -std=c++11 -Wall
DEPS = -lGLEW -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl
SOURCES = main.cpp include/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)
OUT = out

main main.cpp:
	$(C) $(CF) $(SOURCES) $(DEPS) -o $(OUT)
	
