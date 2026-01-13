CXX := clang++
CXXFLAGS := -std=c++17 -Wall -Wextra -Iglad/include -I$(shell brew --prefix)/include
LDFLAGS := -L$(shell brew --prefix)/lib -lglfw \
	-framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC := main.cpp glad/src/glad.c
OUT := learn-opengl

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LDFLAGS) -o $(OUT)

run: $(OUT)
	./$(OUT)

clean: 
	rm -f $(OUT)