CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -Wpedantic -Iinclude -g
LDFLAGS :=

SRCDIR := src
OBJDIR := build
BINDIR := bin
TARGET := $(BINDIR)/app

SRCS := $(wildcard $(SRCDIR)/*.cpp)
OBJS := $(patsubst $(SRCDIR)/%.cpp,$(OBJDIR)/%.o,$(SRCS))

.PHONY: all clean run format

all: $(TARGET)

$(TARGET): $(OBJS) | $(BINDIR)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

clean:
	rm -rf $(OBJDIR) $(BINDIR)

run: all
	./$(TARGET)

format:
	clang-format -i $(SRCS) include/*.hpp || true
