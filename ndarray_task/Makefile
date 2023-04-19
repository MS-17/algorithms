CC = g++
PYTHON = python
CFLAGS = -std=c++17 -O2 #-Wall -pedantic
SOURCES = main.cpp # NDArray.cpp
PY_SRC = main.py

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET = main.exe
else
	RM = rm
	TARGET = ./main
endif

all:

	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) && $(TARGET)

clean:
	$(RM) $(TARGET)

run:all
	@echo "The end of the program"

# @echo $(OS)
# $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) && $(TARGET) | $(PYTHON) $(PY_SRC)
# $(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) && $(TARGET) && $(PYTHON) $(PY_SRC)
# $(CC) $(CFLAGS) -c main.cpp
# $(CC) $(CFLAGS) -c NDArray.cpp
# $(CC) $(CFLAGS) -o $(TARGET) main.o NDArray.o && $(TARGET)

