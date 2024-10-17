#
# @author Riza Kaan Ucak
# @date 27.01.2022
#

.PHONY: clean
.PHONY: test

# Project
BIN=compiler

# Compiler -fPIC
CXX=c++
CXX_FLAGS=-Wall -std=c++17
LIB_FLAGS='-shared'

# Directories
SRC_DIR=src
BUILD_DIR=bin

# Files
HEADERS=$(wildcard src/*.h)
SOURCES=$(wildcard src/*.cpp)
OBJECTS=${SOURCES:.cpp=.o}

# Commands
MKDIR=mkdir -p
REMOVE=rm -f


all: init clean build

build: ${OBJECTS}
	${CXX} ${CXX_FLAGS} $^ -o ${BUILD_DIR}/$(BIN)

%.o: %.cpp
	${CXX} ${CXX_FLAGS} -c $^ -o $@

init:
	${MKDIR} ${BUILD_DIR}

clean:
	${REMOVE} ${BUILD_DIR}/*
	${REMOVE} ${SRC_DIR}/*.o

test:
	./${BUILD_DIR}/${BIN} ./test/test.cpp
