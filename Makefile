CXX = g++
CXXFLAGS = -std=c++20

BUILD_DIR = build
OUT_EXE = Utaste

ifeq ($(OS),Windows_NT)
	LDLIBS += -l Ws2_32
endif

all: $(BUILD_DIR) $(OUT_EXE)

$(OUT_EXE): $(BUILD_DIR)/main.o $(BUILD_DIR)/Utaste.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o\
			 $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/template_parser.o \
			$(BUILD_DIR)/strutils.o $(BUILD_DIR)/global.o $(BUILD_DIR)/CmdHandler.o $(BUILD_DIR)/Discount.o \
             $(BUILD_DIR)/Exception.o $(BUILD_DIR)/Food.o $(BUILD_DIR)/Neighborhood.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Restaurant.o \
             $(BUILD_DIR)/Reservation.o $(BUILD_DIR)/Table.o $(BUILD_DIR)/web_handler.o
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp utils/strutils.hpp utils/strutils.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp utils/strutils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/strutils.o: utils/strutils.cpp utils/strutils.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/strutils.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/web_handler.o: src/web_handler.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: src/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Utaste.o: src/Utaste.cpp src/Utaste.hpp src/global.hpp src/CmdHandler.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/global.o: src/global.cpp src/global.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/CmdHandler.o: src/CmdHandler.cpp src/CmdHandler.hpp src/Utaste.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Discount.o: src/Discount.cpp src/Discount.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Exception.o: src/Exception.cpp src/Exception.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Food.o: src/Food.cpp src/Food.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Neighborhood.o: src/Neighborhood.cpp src/Neighborhood.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Person.o: src/Person.cpp src/Person.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Restaurant.o: src/Restaurant.cpp src/Restaurant.hpp src/Reservation.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Reservation.o: src/Reservation.cpp src/Reservation.hpp src/Table.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Table.o: src/Table.cpp src/Table.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@



.PHONY: all clean test

test: $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -Wall -Wextra Test/regression.cpp $(filter-out src/main.cpp src/web_handler.cpp,$(wildcard src/*.cpp)) utils/request.cpp utils/utilities.cpp utils/strutils.cpp -o $(BUILD_DIR)/regression
	./$(BUILD_DIR)/regression

clean:
	rm -rf $(BUILD_DIR) *.o $(OUT_EXE) &> /dev/null
