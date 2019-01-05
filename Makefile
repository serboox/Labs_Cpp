# Labs_C.
# Author:
# Date: 2019-01-05

.PHONY: build test asm

APP_NAME?=lab_c
CMAKE_FOLDER_NAME?=build

OSFLAG?=
COMMAND_CREATE_BUILD_DIR?=
COMMAND_BUILD?=
COMMAND_BUILD_OBJECT?=
COMMAND_RUN?=
COMMAND_CLEAN?=
ifeq ($(OS),Windows_NT)
	# Windows commands
	COMMAND_CREATE_BUILD_DIR = mkdir -p ${CMAKE_FOLDER_NAME}
	COMMAND_BUILD_OBJECT = gcc -c .\\src\\main.c -o ${CMAKE_FOLDER_NAME}\\main.o && \
		gcc -c .\\src\\other.c -o ${CMAKE_FOLDER_NAME}\\other.o
	COMMAND_BUILD = gcc -o ${APP_NAME}.exe ${CMAKE_FOLDER_NAME}\\${APP_NAME}.o
	COMMAND_RUN = ${APP_NAME}.exe
	COMMAND_CLEAN = rm ${CMAKE_FOLDER_NAME} #${APP_NAME}.exe

	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	# Unix commands
	COMMAND_CREATE_BUILD_DIR = mkdir -p ./${CMAKE_FOLDER_NAME}
	COMMAND_BUILD_OBJECT = gcc -c ./src/main.c -o ./${CMAKE_FOLDER_NAME}/main.o && \
		gcc -c ./src/other.c -o ./${CMAKE_FOLDER_NAME}/other.o
	COMMAND_BUILD = gcc -o ${APP_NAME} ./${CMAKE_FOLDER_NAME}/*.o
	COMMAND_RUN = ./${APP_NAME}
	COMMAND_CLEAN = rm -f ./${CMAKE_FOLDER_NAME}/${APP_NAME}.o ${APP_NAME}

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += -D LINUX
	endif
	ifeq ($(UNAME_S),Darwin)
		OSFLAG += -D OSX
	endif
		UNAME_P := $(shell uname -p)
	ifeq ($(UNAME_P),x86_64)
		OSFLAG += -D AMD64
	endif
		ifneq ($(filter %86,$(UNAME_P)),)
	OSFLAG += -D IA32
		endif
	ifneq ($(filter arm%,$(UNAME_P)),)
		OSFLAG += -D ARM
	endif
endif

# Default target executed when no arguments are given to make.
default_target: all

p-all: echo-os build run

p-echo-os:
	@echo $(OSFLAG)

p-build: p-clean p-build-object
	@echo "+ $@"
	${COMMAND_BUILD}

p-create-build-dir:
	${COMMAND_CREATE_BUILD_DIR}

p-build-object: create-build-dir
	@echo "+ $@"
	${COMMAND_BUILD_OBJECT}

p-clean:
	@echo "+ $@"
	${COMMAND_CLEAN}

p-run:
	@echo "+ $@"
	${COMMAND_RUN}

asm:
	mkdir -p ./asm
	cd ./src && for i in *.c;do gcc -S $${i} ;done
	cd ./src  && for i in *.s;do mv $${i} ../asm;done

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