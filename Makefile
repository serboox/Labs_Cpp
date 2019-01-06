# Labs_C.
# Author:
# Date: 2019-01-05

.PHONY: build test asm

APP_NAME?=cw_11
CMAKE_FOLDER_NAME?=build

# Default target executed when no arguments are given to make.
default_target: all

all: build run

install:
	@echo "+ $@"
	brew install cmake

init:
	@echo "+ $@"
	cmake ./CMakeLists.txt -B./${CMAKE_FOLDER_NAME} -H.

build:
	@echo "+ $@"
	cd ./${CMAKE_FOLDER_NAME} && make

run:
	@echo "+ $@"
	cd ./${CMAKE_FOLDER_NAME} && ./${APP_NAME}