TARGET := fixed
CXX := c++
STD := -std=c++98
CFLAGS := -Wall -Wextra -Werror $(STD)
RM := rm -rf
SRC := main.cpp Fixed.cpp
OBJ := $(SRC:%.cpp=%.o)
DEPS := $(OBJ:%.o=%.d)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CFLAGS) -MMD -MP -c $< -o $@

clean:
	$(RM) $(OBJ) $(DEPS)

fclean: clean
	$(RM) $(TARGET)

re: fclean all

.PHONY: all clean fclean re

-include $(DEPS)