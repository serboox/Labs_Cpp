# Labs_C.
# Author:
# Date: 2019-01-05

.PHONY: build test

APP_NAME?=my_app
BUILD_FOLDER_NAME?=build

OSFLAG?=
COMMAND_CREATE_BUILD_DIR?=
COMMAND_BUILD?=
COMMAND_BUILD_OBJECT?=
COMMAND_RUN?=
COMMAND_CLEAN?=
ifeq ($(OS),Windows_NT)
	# Windows commands
	COMMAND_CREATE_BUILD_DIR = mkdir -p ${BUILD_FOLDER_NAME}
	COMMAND_BUILD_OBJECT = gcc -c .\\src\\main.c -o ${BUILD_FOLDER_NAME}\\main.o && \
		gcc -c .\\src\\other.c -o ${BUILD_FOLDER_NAME}\\other.o
	COMMAND_BUILD = gcc -o ${APP_NAME}.exe ${BUILD_FOLDER_NAME}\\${APP_NAME}.o
	COMMAND_RUN = ${APP_NAME}.exe
	COMMAND_CLEAN = rm ${BUILD_FOLDER_NAME} #${APP_NAME}.exe

	OSFLAG += -D WIN32
	ifeq ($(PROCESSOR_ARCHITECTURE),AMD64)
		OSFLAG += -D AMD64
	endif
	ifeq ($(PROCESSOR_ARCHITECTURE),x86)
		OSFLAG += -D IA32
	endif
else
	# Unix commands
	COMMAND_CREATE_BUILD_DIR = mkdir -p ./${BUILD_FOLDER_NAME}
	COMMAND_BUILD_OBJECT = gcc -c ./src/main.c -o ./${BUILD_FOLDER_NAME}/main.o && \
		gcc -c ./src/other.c -o ./${BUILD_FOLDER_NAME}/other.o
	COMMAND_BUILD = gcc -o ${APP_NAME} ./${BUILD_FOLDER_NAME}/*.o
	COMMAND_RUN = ./${APP_NAME}
	COMMAND_CLEAN = rm -f ./${BUILD_FOLDER_NAME}/${APP_NAME}.o ${APP_NAME}

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

all: echo-os build run

echo-os:
	@echo $(OSFLAG)

build: clean build-object
	@echo "+ $@"
	${COMMAND_BUILD}

create-build-dir:
	${COMMAND_CREATE_BUILD_DIR}

build-object: create-build-dir
	@echo "+ $@"
	${COMMAND_BUILD_OBJECT}

clean:
	@echo "+ $@"
	${COMMAND_CLEAN}

run:
	@echo "+ $@"
	${COMMAND_RUN}