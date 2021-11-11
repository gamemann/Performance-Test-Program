CC = clang

BUILDDIR = build
SRCDIR = src

COMMONSRC = common.c
COMMONOBJ = common.o

TEST1SRC = test1.c
TEST1OUT = perftest1

INCS = $(BUILDDIR)/$(COMMONOBJ)

all: test1
common:
	mkdir -p $(BUILDDIR)
	$(CC) -O2 -c -o $(BUILDDIR)/$(COMMONOBJ) $(SRCDIR)/$(COMMONSRC)
test1: common $(INCS)
	mkdir -p $(BUILDDIR)
	$(CC) -O2 -o $(BUILDDIR)/$(TEST1OUT) $(INCS) $(SRCDIR)/$(TEST1SRC) 
install:
	cp $(BUILDDIR)/$(TEST1OUT) /usr/bin/$(TEST1OUT)
clean:
	rm -f $(BUILDDIR)/*
.PHONY: common test1
.DEFAULT: all