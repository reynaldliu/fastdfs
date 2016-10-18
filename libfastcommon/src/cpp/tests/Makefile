.SUFFIXES: .c .o

COMPILE = g++ -g -O1 -Wall -D_FILE_OFFSET_BITS=64 -g -DDEBUG_FLAG
INC_PATH = -I../
LIB_PATH = ../libfastcommon_c++.a -lpthread -lm

ALL_PRGS = test_exception

all: $(ALL_PRGS)
.cc:
	$(COMPILE) -static -o $@ $< $(LIB_PATH) $(INC_PATH)
.cc.o:
	$(COMPILE) -static -c -o $@ $<  $(INC_PATH)
clean:
	rm -f $(ALL_PRGS)

