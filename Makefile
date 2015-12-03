C = g++
CF = -std=c++11 -Wall
DEPS = -lglfw3 -lGL -lX11 -lXi -lXrandr -lXxf86vm -lXinerama -lXcursor -lrt -lm -pthread -ldl
SOURCES = main.cpp include/*.cpp
OBJECTS = $(SOURCES:.cpp=.o)
OUT = out

recomp main.cpp:
	$(C) $(CF) $(SOURCES) $(DEPS) -o $(OUT)

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(C) $(CF) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
	
