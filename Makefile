CC = clang

BUILDDIR = build
SRCDIR = src

COMMONSRC = common.c
COMMONOUT = common.o

TEST1SRC = test.c
TEST1OUT = perftest1

INCS = $(BUILDDIR)/$(COMMONOUT)

all: test1
common:
	mkdir -p $(BUILDDIR)
	$(CC) -O2 -c -o $(BUILDDIR)/$(COMMONOUT) $(SRCDIR)/$(COMMONSRC)
test1: common
	mkdir -p $(BUILDDIR)
	$(CC) -O2-o $(BUILDDIR)/$(TEST1OUT)  $(SRCDIR)/$(TEST1SRC) 
install:
	cp $(BUILDDIR)/$(TEST1OUT) /usr/bin/$(TEST1OUT)
clean:
	rm -f $(BUILDDIR)/*
.PHONY: test1
.DEFAULT: all