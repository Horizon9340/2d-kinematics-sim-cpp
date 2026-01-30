CC := clang
CXX := clang++

CFLAGS := -Iglad/include
CXXFLAGS := -std=c++17 -Wall -Wextra -Iglad/include -I$(shell brew --prefix)/include

LDFLAGS := -L$(shell brew --prefix)/lib -lglfw \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC_CPP := main.cpp 
SRC_C := glad/src/glad.c

OBJ_CPP := $(SRC_CPP:.cpp=.o)
OBJ_C := $(SRC_C:.c=.o)

OUT := learn-opengl

all: $(OUT)

$(OUT): $(OBJ_CPP) $(OBJ_C)
	$(CXX) $^ $(LDFLAGS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

run: $(OUT)
	./$(OUT)

clean: 
	rm -f $(OUT) $(OBJ_CPP) $(OBJ_C)
