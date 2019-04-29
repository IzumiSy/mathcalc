DBG_OPTS = -O0 -g3 -Wall
TARGET = test
TEST_SOURCE = test.cpp ../rpn.cpp

test: $(TEST_SOURCE)
	g++ $(DBG_OPTS) -std=c++11 -o $(TARGET) $(TEST_SOURCE) -I vendors

.PHONY: clean
clean: $(TARGET)
	$(shell [ -e $(TARGET) ] && rm $(TARGET))
	$(shell [ -d $(TARGET).dSYM ] && rm -r $(TARGET).dSYM)
	@echo Done

run: $(TARGET)
	./$(TARGET)
