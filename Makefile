CXX = g++
CXXFLAGS = -std=c++20

SRCS = src/main.cpp src/global.cpp src/CmdHandler.cpp src/Utaste.cpp src/Person.cpp src/Restaurant.cpp src/Reservation.cpp src/Food.cpp src/Neighborhood.cpp src/Exception.cpp src/Table.cpp src/Discount.cpp src/web_handler.cpp server/server.cpp server/route.cpp 

TARGET = server 

OBJS = $(SRCS:.cpp=.o)

EXEC = utaste

all: $(EXEC)

$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(EXEC)
