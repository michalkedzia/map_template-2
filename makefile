main: main.o
	g++ -g -Wall $^ -o $@

main.o: main.cpp employee.h map_template.h
	g++ -g -c -Wall $< -o $@

.PHONY: clean

clean:
	-rm main.o main