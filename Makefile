# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = /usr/bin/g++
CC  = $(CXX)

# Generate dependencies in *.d files
DEPFLAGS = -MT $@ -MMD -MP -MF $*.d

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11 -I.
CXXFLAGS =  -O0 -Wall -Wextra -pedantic-errors -Wold-style-cast #No optimization activated (-O0). -O2 is with optimization
CXXFLAGS += -std=c++11
CXXFLAGS += -g
CXXFLAGS += $(DEPFLAGS)
LDFLAGS =   -g 
CXXFLAGS += -fsanitize=address
LDFLAGS += -fsanitize=address


#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = tag_remover test_find_primes print_primes test_to_string date_test

all: $(PROGS)

test: 

# Targets rely on implicit rules for compiling and linking
tag_remover: tag_remover.o

find_primes: find_primes.o

test_find_primes: test_find_primes.o find_primes.o

print_primes: find_primes.o print_primes.o

test_to_string: test_to_string.o date.o

date_test: date_test.o date.o

test_string_cast: test_string_cast.o date.o 

# Phony targets
.PHONY: all test clean distclean

# Standard clean
clean:
	rm -f *.o $(PROGS)

distclean: clean
	rm *.d


# Include the *.d files
SRC = $(wildcard *.cc)
-include $(SRC:.cc=.d)
