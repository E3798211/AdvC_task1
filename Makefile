
CXX := g++
CC  := $(CXX)
CXXFLAGS := -Wall -Wextra -Wpedantic -std=c++11
LDLIBS := -lsfml-graphics -lsfml-window -lsfml-system

src := main.cpp win_manager.cpp button.cpp
obj := $(patsubst %.cpp,%.o,$(src))
bin := main

all: debug

dep := .depend
-include $(dep)
$(dep): $(src)
	$(CXX) -MM $^ > $@

release debug: $(bin)

debug: CFLAGS += -pg -g
release: CFLAGS += -O2 -DNDEBUG

$(bin): $(obj)

.PHONY: clean
clean:
	$(RM) $(bin)
	$(RM) $(obj)
	$(RM) gmon.out
	$(RM) $(dep)

