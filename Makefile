CXX = g++
CXXFLAGS = -std=c++20 -Wall

SRCS = 

LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
OBJS = $(SRCS:.cpp=.o)
EXEC = utaste

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
