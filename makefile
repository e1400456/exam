
CC=g++
LIBS=libgtest.a
CFLAGS=-I$(GTEST_DIR) -I$(GTEST_DIR)/include -pthread -fprofile-arcs -ftest-coverage


all: my_test
	
my_test: main.c linkedlist.c test.c
	$(CC) $(CFLAGS) main.c linkedlist.c test.c  $(LIBS) -o my_test
clean:
	rm *o my_test



