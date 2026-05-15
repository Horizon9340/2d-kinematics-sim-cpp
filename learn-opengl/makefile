CC := clang
CXX := clang++

CFLAGS := -I../external/glad/include -I/opt/homebrew/include
CXXFLAGS := -std=c++17 -Wall -Wextra -I../external/glad/include -I/opt/homebrew/include

LDFLAGS := -L$(shell brew --prefix)/lib -lglfw \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC_CPP := main.cpp 
SRC_C := ../external/glad/src/glad.c

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
