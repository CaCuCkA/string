TARGET_NAME := NONE
STATIC_MAKE := static_makefile
DYNAMIC_MAKE := dynamic_makefile
MAKE_DIR := make_compile
EXAMPLE_DIR := examples
STATIC_LIB = mystring.a
DYNAMIC_LIB = libmystring.so

all:
ifeq ($(TARGET_NAME), dynamic)
	@echo "\033[0;35mCreate dynamic library$<\e[0m\033[1;33m"
	$(MAKE) -C $(MAKE_DIR) -f $(DYNAMIC_MAKE)
	@echo "\033[0;35mCompile our tests with dynamic library$<\e[0m\033[1;33m"
	$(MAKE) -C $(EXAMPLE_DIR) LIB=$(DYNAMIC_LIB)
else ifeq ($(TARGET_NAME), static)
	@echo "\033[0;35mCreate dynamic library$<\e[0m\033[1;33m"
	$(MAKE) -C $(MAKE_DIR) -f $(STATIC_MAKE)
	@echo "\033[0;35mCompile our tests with static library$<\e[0m\033[1;33m"
	$(MAKE) -C $(EXAMPLE_DIR) LIB=$(STATIC_LIB)
else
	@echo "\033[0;31mError your pass incorrect argument $(TARGET_NAME)$<\e[0m"
endif

.PHONY clean:
	$(MAKE) -C $(EXAMPLE_DIR) clean
	if [ -d "lib" ]; then rm -Rf lib; fi
	if [ -d "bin" ]; then rm -rf bin; fi