CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -pedantic
INCLUDES := -Iinclude

ifeq ($(OS),Windows_NT)
EXEEXT := .exe
RM := del /Q
else
EXEEXT :=
RM := rm -f
endif

APP := reservation_system$(EXEEXT)
APP_SOURCES := src/main.cpp src/CancellationHistory.cpp src/Reservation.cpp src/ReservationManager.cpp src/Resource.cpp src/WaitingList.cpp

CANCELLATION_TEST := cancellation_history_test$(EXEEXT)
WAITING_LIST_TEST := waiting_list_test$(EXEEXT)

ifeq ($(OS),Windows_NT)
RUN_COMMAND := ..\$(APP)
else
RUN_COMMAND := ../$(APP)
endif

.PHONY: all run test clean

all: $(APP)

$(APP): $(APP_SOURCES)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(APP_SOURCES) -o $@

$(CANCELLATION_TEST): tests/CancellationHistoryTest.cpp src/CancellationHistory.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

$(WAITING_LIST_TEST): tests/WaitingListTest.cpp src/WaitingList.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) $^ -o $@

test: $(CANCELLATION_TEST) $(WAITING_LIST_TEST)
	./$(CANCELLATION_TEST)
	./$(WAITING_LIST_TEST)

run: $(APP)
	cd src && $(RUN_COMMAND)

clean:
	-$(RM) $(APP) $(CANCELLATION_TEST) $(WAITING_LIST_TEST)
