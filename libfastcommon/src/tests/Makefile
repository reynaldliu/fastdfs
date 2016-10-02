.SUFFIXES: .c .o

COMPILE = g++ -g -O1 -Wall -D_FILE_OFFSET_BITS=64 -g -DDEBUG_FLAG
INC_PATH = -I../
LIB_PATH = -L../ -lfastcommon -lpthread -lm

ALL_PRGS = test_hash test_allocator test_skiplist test_multi_skiplist test_mblock test_blocked_queue \
           test_id_generator

all: $(ALL_PRGS)
.c:
	$(COMPILE) -static -o $@ $< $(LIB_PATH) $(INC_PATH)
.c.o:
	$(COMPILE) -static -c -o $@ $<  $(INC_PATH)
clean:
	rm -f $(ALL_PRGS)

