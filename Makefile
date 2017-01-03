DBG_OPTS = -O0 -g3 -Wall
SOURCE = mathcalc.cpp calculator.cpp
TARGET = mathcalc

mathcalc: $(SOURCE)
	g++ $(DBG_OPTS) -Wall -o $(TARGET) $(SOURCE)

.PHONY: clean run debug release
clean:
	rm $(TARGET)
	rm -r mathcalc.dSYM

run: $(TARGET)
	./mathcalc

release: mathcalc.cpp
	g++ -o $(TARGET) $(SOURCE)
