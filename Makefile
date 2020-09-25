
CC := g++
CFLAGS := -Wall -Wextra -Wpedantic -std=c++11
LFLAGS := -lsfml-graphics -lsfml-window -lsfml-system

src := main.cpp 
exec := a.out   # Consistency

all: debug

release debug: $(exec)

debug: CFLAGS += -pg -g
release: CFLAGS += -O2 -DNDEBUG

$(exec): $(src)
	$(CC) $(CPPFLAGS) $(CFLAGS) $^ -o $@ $(LFLAGS)

.PHONY: clean
clean:
	$(RM) $(exec)
	$(RM) gmon.out

