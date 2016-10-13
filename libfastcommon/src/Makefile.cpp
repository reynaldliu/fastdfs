.SUFFIXES: .c .o .lo

COMPILE = g++ -Wall -D_FILE_OFFSET_BITS=64 -D_GNU_SOURCE -D__STDC_FORMAT_MACROS -g -O3
INC_PATH = 
LIB_PATH = -lm -lpthread

FAST_CPP_SHARED_OBJS = exception.lo 
FAST_CPP_STATIC_OBJS = exception.o

ALL_OBJS = $(FAST_CPP_STATIC_OBJS) $(FAST_CPP_SHARED_OBJS)

SHARED_LIBS = libfastcommon_c++.so
STATIC_LIBS = libfastcommon_c++.a
ALL_LIBS = $(SHARED_LIBS) $(STATIC_LIBS)

all: $(ALL_OBJS) $(ALL_LIBS)
libfastcommon_c++.so:
	$(COMPILE) -o $@ $< -shared $(FAST_CPP_SHARED_OBJS) $(LIB_PATH)
libfastcommon_c++.a: $(FAST_CPP_STATIC_OBJS)
	ar rcs $@ $(FAST_CPP_STATIC_OBJS)
.o:
	$(COMPILE) -o $@ $<  $(FAST_CPP_STATIC_OBJS) $(LIB_PATH) $(INC_PATH)
.c:
	$(COMPILE) -o $@ $<  $(FAST_CPP_STATIC_OBJS) $(LIB_PATH) $(INC_PATH)
.c.o:
	$(COMPILE) -c -o $@ $<  $(INC_PATH)
.c.lo:
	$(COMPILE) -c -fPIC -o $@ $<  $(INC_PATH)
install:
	mkdir -p $(DESTDIR)/usr/lib64
	mkdir -p $(DESTDIR)/usr/lib
	install -m 755 $(SHARED_LIBS) $(DESTDIR)/usr/lib64
	install -m 755 $(SHARED_LIBS) $(DESTDIR)/usr/lib
	mkdir -p $(DESTDIR)/usr/include/fastcommon
	install -m 644 $(HEADER_FILES) $(DESTDIR)/usr/include/fastcommon
clean:
	rm -f $(ALL_OBJS) $(ALL_PRGS) $(ALL_LIBS)

