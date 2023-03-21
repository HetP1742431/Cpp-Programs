we3_solution: ref_manager.o we3_test.o
	g++ ref_manager.o we3_test.o -o we3_solution

we3_test.o: we3_test.cpp
	g++ -c we3_test.cpp

ref_manager.o: ref_manager.cpp ref_manager.h
	g++ -c ref_manager.cpp

clean:
	rm *.o we3_solution
