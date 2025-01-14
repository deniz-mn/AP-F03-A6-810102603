CXX = g++
CXXFLAGS = -std=c++11

BUILD_DIR = build
OUT_EXE = UTaste

ifeq ($(OS),Windows_NT)
	LDLIBS += -l Ws2_32
endif

all: $(BUILD_DIR) $(OUT_EXE)

$(OUT_EXE): $(BUILD_DIR)/main.o $(BUILD_DIR)/Utaste.o $(BUILD_DIR)/global.o $(BUILD_DIR)/CmdHandler.o $(BUILD_DIR)/Discount.o \
             $(BUILD_DIR)/Exceptions.o $(BUILD_DIR)/Food.o $(BUILD_DIR)/Neighborhood.o $(BUILD_DIR)/Person.o $(BUILD_DIR)/Restaurant.o \
             $(BUILD_DIR)/Reservation.o $(BUILD_DIR)/Table.o $(BUILD_DIR)/web_handler.o
	$(CXX) $(CXXFLAGS) $^ $(LDLIBS) -o $@

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/main.o: src/main.cpp src/Utaste.hpp src/CmdHandler.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Utaste.o: src/Utaste.cpp src/Utaste.hpp src/global.hpp src/CmdHandler.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/global.o: src/global.cpp src/global.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/CmdHandler.o: src/CmdHandler.cpp src/CmdHandler.hpp src/Utaste.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Discount.o: src/Discount.cpp src/Discount.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(BUILD_DIR)/Exceptions.o: src/Exceptions.cpp src/Exceptions.hpp
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

$(BUILD_DIR)/web_handler.o: src/web_handler.cpp src/web_handler.hpp src/CmdHandler.hpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

.PHONY: all clean

clean:
	rm -rf $(BUILD_DIR) *.o $(OUT_EXE) &> /dev/null