CXX = g++
CXXFLAGS = -std=c++20 -Wall

SRCS = src/main.cpp src/global.cpp src/CmdHandler.cpp src/Utaste.cpp src/Person.cpp 



OBJS = $(SRCS:.cpp=.o)
EXEC = utaste

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
