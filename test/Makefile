DBG_OPTS = -O0 -g3 -Wall
TEST_SOURCE = test.cpp
TARGET = test

test: $(TEST_SOURCE)
	g++ $(DBG_OPTS) -o $(TARGET) $(TEST_SOURCE) -I ../vendors

.PHONY: clean 
clean: $(TARGET)
	$(shell [ -e $(TARGET) ] && rm $(TARGET))
	$(shell [ -d $(TARGET).dSYM ] && rm -r $(TARGET).dSYM)
	@echo Done

run: $(TARGET)
	./$(TARGET)