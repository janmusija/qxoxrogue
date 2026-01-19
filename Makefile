CXX      := g++
TARGET   := qxoxrogue

CXXFLAGS := -Wall -Wextra -std=c++17 -O2 -g
LDFLAGS  :=
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