
mathcalc: mathcalc.cpp
	g++ -g -Wall -o mathcalc mathcalc.cpp

.PHONY: clean run
clean:
	rm mathcalc

run: mathcalc
	./mathcalc

