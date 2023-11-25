target:
	g++ -Wall -g -o final_debug Q1.cpp read.cpp 
	g++ -Wall -O2 -o final_optimized Q1.cpp read.cpp 

clean:
	rm -f *.o final_debug final_optimized final
