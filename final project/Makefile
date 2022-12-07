CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes/ -g -O0 -Wall -Wextra -Werror

exec: bin/exec

bin/exec: src/graphtraversal.cpp src/main.cc includes/graphtraversal.hpp
	${CXX} ${CXX_FLAGS} src/graphtraversal.cpp src/main.cc  -o bin/exec
# src/airports.cpp src/pathway.cpp src/utils.cpp includes/utils.h 
#src/airports.cpp src/pathway.cpp src/utils.cpp

.DEFAULT_GOAL := exec
.PHONY: clean exec

clean:
	rm -rf bin/*
