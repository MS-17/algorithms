CC = g++
PYTHON = python
CFLAGS = -std=c++11 -Wall -pedantic
SOURCES = main.cpp
PY_SRC = main.py

ifeq ($(OS), Windows_NT)
	RM = del
	TARGET = main.exe
else
	RM = rm
	TARGET = main
endif

all:

	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) && $(TARGET) && $(PYTHON) $(PY_SRC)

clean:
	$(RM) $(TARGET)

run:all
	@echo "The end of the program"

# @echo $(OS)
# #$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES) && $(TARGET) | $(PYTHON) $(PY_SRC)
