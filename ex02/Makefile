TARGET := fixed
CXX := c++
STD := -std=c++98
CFLAGS := -Wall -Wextra -Werror $(STD)
RM := rm -rf
SRC := main.cpp Fixed.cpp
OBJ := $(SRC:%.cpp=%.o)
all: $(TARGET)
$(TARGET): $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $(TARGET)
%.o: %.cpp
	$(CXX) $(CFLAGS) -c $<  -o $@
clear:
	$(RM) $(OBJ)
fclean: clear
	$(RM) $(TARGET)
re: fclean all
.PHONY: all clean fclean re