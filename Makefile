
CXX := g++
CC  := $(CXX)
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++11
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system

src := main.cpp
obj := $(patsubst %.cpp,%.o,$(src))
exec := main

all: debug

dep := .depend
-include $(dep)
$(dep): $(src)
	$(CXX) -MM $^ > $@

release debug: $(exec)

debug: CFLAGS += -pg -g
release: CFLAGS += -O2 -DNDEBUG

$(exec): $(obj)

.PHONY: clean
clean:
	$(RM) $(exec)
	$(RM) $(obj)
	$(RM) gmon.out
	$(RM) $(dep)

