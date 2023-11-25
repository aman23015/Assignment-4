target:
	g++ -Wall -g -o final_debug main.cpp vdb.cpp rdb.cpp udb.cpp headers.h
	g++ -Wall -O2 -o final_optimized main.cpp vdb.cpp rdb.cpp udb.cpp headers.h

clean:
	rm -f *.o final_debug final_optimized final
