DBG_OPTS = -O0 -g3 -Wall
SOURCE = mathcalc.cpp calculator.cpp stringExpression.cpp expressionList.cpp
TARGET = mathcalc

mathcalc: $(SOURCE)
	g++ $(DBG_OPTS) -o $(TARGET) $(SOURCE)

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