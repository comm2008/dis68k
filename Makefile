CC ?= clang
CFLAGS = -std=c99 -O2 -Wall -Wextra -Iinc -fPIC $(OPTFLAGS)
PREFIX ?= /usr/local

OUTPUT_LIB_NAME=dis68k

BUILD_DEST=build
TARGET_PREFIX=$(BUILD_DEST)/lib$(OUTPUT_LIB_NAME)
STATIC_LIBRARY_TARGET=$(TARGET_PREFIX).a
SHARED_LIBRARY_TARGET=$(TARGET_PREFIX).so
PROGRAM_TARGET=$(BUILD_DEST)/dis68k

LIBRARY_SOURCE_DIR=src/libdis68k
LIBRARY_SOURCES=$(wildcard $(LIBRARY_SOURCE_DIR)/**/*.c $(LIBRARY_SOURCE_DIR)/*.c)
LIBRARY_OBJECTS=$(patsubst %.c,%.o,$(LIBRARY_SOURCES))

PROGRAM_SOURCE_DIR=src/dis68k
PROGRAM_SOURCES=$(wildcard $(PROGRAM_SOURCE_DIR)/**/*.c $(PROGRAM_SOURCE_DIR)/*.c)
PROGRAM_OBJECTS=$(patsubst %.c,%.o,$(PROGRAM_SOURCES))

.PHONY: program library install clean

program: library $(PROGRAM_OBJECTS)
	$(CC) -o $(PROGRAM_TARGET) $(PROGRAM_OBJECTS) $(STATIC_LIBRARY_TARGET)

library: $(BUILD_DEST) $(LIBRARY_OBJECTS)
	# Static Library
	ar rcs $(STATIC_LIBRARY_TARGET) $(LIBRARY_OBJECTS)
	ranlib $(STATIC_LIBRARY_TARGET)
	# Shared Library
	ld -shared -o $(SHARED_LIBRARY_TARGET) $(LIBRARY_OBJECTS)

install: program
	install -s -m 0755 -o root -g root $(STATIC_PROGRAM_TARGET) $(PREFIX)/bin
	install -s -m 0644 -o root -g root $(STATIC_LIBRARY_TARGET) $(PREFIX)/lib
	install -s -m 0644 -o root -g root $(SHARED_LIBRARY_TARGET) $(PREFIX)/lib

clean:
	rm -rf $(BUILD_DEST)
	rm -f $(LIBRARY_OBJECTS) $(PROGRAM_OBJECTS)

$(BUILD_DEST):
	mkdir -p $@

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
