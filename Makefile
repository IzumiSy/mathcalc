DBG_OPTS = -O0 -g3 -Wall
TARGET = mathcalc
SOURCE = mathcalc.cpp \
	calculator.cpp \
	stringExpression.cpp \
	expressionList.cpp \
	rpn.cpp

mathcalc: $(SOURCE)
	g++ $(DBG_OPTS) -std=c++11 -o $(TARGET) $(SOURCE)

.PHONY: clean run release
clean:
	$(shell [ -e $(TARGET) ] && rm $(TARGET))
	$(shell [ -d $(TARGET).dSYM ] && rm -r $(TARGET).dSYM)
	$(shell [ -e core ] && rm core)
	@echo Done

run: $(TARGET)
	./mathcalc

release: mathcalc.cpp
	g++ -o $(TARGET) $(SOURCE)
