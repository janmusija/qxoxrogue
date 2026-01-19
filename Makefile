CXX      := g++
TARGET   := qxoxrogue

# fsanitize can be removed in a bit when I'm done debugging. -fsanitize=address -fsanitize=undefined in CXXFLAGS and LDFLAGS can help determine why segfaulting is happening
CXXFLAGS := -Wall -Wextra -std=c++20 -O2 -I. -fsanitize=address -fsanitize=undefined -g
LDFLAGS  := -fsanitize=address -fsanitize=undefined
LDLIBS   := -lncursesw -lgmp -lgmpxx

# Put all build artifacts here
BUILD_DIR := build

# Recursively find all .cpp sources (requires a POSIX shell + find)
SRCS := $(shell find . -type f -name '*.cpp' ! -path './$(BUILD_DIR)/*')
OBJS := $(patsubst ./%.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

.PHONY: all clean run
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) $^ $(LDLIBS) -o $@

# Compile .cpp -> build/.../.o and also emit dependency .d files
$(BUILD_DIR)/%.o: ./%.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Include generated dependency files if they exist
-include $(DEPS)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)