cc = g++
flags = -Wall -g -std=c++11 -pthread
objs = main.o signalhandle.o
target = test

$(target) : $(objs)
	$(cc) $(flags) -o $@ $^
main.o : main.cpp
	$(cc) $(flags) -c $< -o $@ -I.
signalhandle.o : csignalhandle.cpp
	$(cc) $(flags) -c $< -o $@ -I.

clean:
	rm -rf $(objs) $(target)
