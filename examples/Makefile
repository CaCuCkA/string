CXX = g++
CFLAGS =
PRG_NAME = example
OBJ_DIR := obj
BIN_DIR := ../bin
OBJ = example.o
LIB =
STATIC = mystring.a
STATIC_PATH = ../lib/make/static/bin
DYNAMIC = libmystring.so
DYNAMIC_PATH = ../lib/make/dynamic/bin

all: $(BIN_DIR)/$(PRG_NAME)
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(OBJ_DIR)/$(OBJ): $(PRG_NAME).cpp
ifeq ($(LIB),$(DYNAMIC))
	$(CXX) $(CFLAGS) -fPIC -c $< -o $@
else
	$(CXX) $(CFLAGS) -fPIC -c $< -o $@
endif

$(BIN_DIR)/$(PRG_NAME): $(OBJ_DIR) $(BIN_DIR) $(OBJ_DIR)/$(OBJ)
ifeq ($(LIB),$(DYNAMIC))
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/$(OBJ) $(DYNAMIC_PATH)/$(DYNAMIC) -o $(BIN_DIR)/dynamic_$(PRG_NAME)
else ifeq ($(LIB),$(STATIC))
	$(CXX) $(CXXFLAGS) $(OBJ_DIR)/$(OBJ) $(STATIC_PATH)/$(STATIC) -o $(BIN_DIR)/static_$(PRG_NAME)
else
	@echo "Error your pass incorrect argument $(LIB)"
endif

.PHONY: clean
clean:
	if [ -d "$(OBJ_DIR)" ]; then rm -Rf $(OBJ_DIR); fi