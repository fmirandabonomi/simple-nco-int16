CC=gcc
LD=gcc
CFLAGS=-Wall -Wextra -Werror -std=c99
LDFLAGS= -lm

SRC_DIR=src
INC_DIR=inc
BUILD_DIR=build
BIN_DIR=$(BUILD_DIR)/bin
OBJ_DIR=$(BUILD_DIR)/obj
DOC_DIR=$(BUILD_DIR)/doc
PROG_NAME=nco

SRC_FILES=$(wildcard $(SRC_DIR)/*.c)
OBJ_FILES=$(patsubst $(SRC_DIR)%c,$(OBJ_DIR)%o,$(SRC_FILES))
DEP_FILES=$(patsubst %o,$d,$(OBJ_FILES))

PROG = $(BIN_DIR)/$(PROG_NAME)

all: $(PROG);

$(PROG): $(OBJ_FILES) | $(BIN_DIR)
	$(LD) $(LDFLAGS) -o $(PROG) $(OBJ_FILES)

doc: |$(DOC_DIR)
	doxygen doxyfile

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(foreach d,$(INC_DIR),-I$(d)) -MMD -c -o $@ $<

$(OBJ_DIR) $(BIN_DIR) $(DOC_DIR):
	

-include $(DEP_FILES)
