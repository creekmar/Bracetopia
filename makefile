#
# Created by gmakemake (Ubuntu Jul 25 2014) on Thu Feb 24 19:15:42 2022
#

#
# Definitions
#

.SUFFIXES:
.SUFFIXES:	.a .o .c .C .cpp .s .S
.c.o:
		$(COMPILE.c) $<
.C.o:
		$(COMPILE.cc) $<
.cpp.o:
		$(COMPILE.cc) $<
.S.s:
		$(CPP) -o $*.s $<
.s.o:
		$(COMPILE.cc) $<
.c.a:
		$(COMPILE.c) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.C.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%
.cpp.a:
		$(COMPILE.cc) -o $% $<
		$(AR) $(ARFLAGS) $@ $%
		$(RM) $%

CC =		gcc
CXX =		g++

RM = rm -f
AR = ar
LINK.c = $(CC) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS)
LINK.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(LDFLAGS)
COMPILE.c = $(CC) $(CFLAGS) $(CPPFLAGS) -c
COMPILE.cc = $(CXX) $(CXXFLAGS) $(CPPFLAGS) -c
CPP = $(CPP) $(CPPFLAGS)
########## Flags from header.mak

CFLAGS =	-std=c99 -ggdb -Wall -Wextra -pedantic
CLIBFLAGS =	-lm  -lcurses 


########## End of flags from header.mak


CPP_FILES =	
C_FILES =	bracetopia.c measure.c movements.c printing.c
PS_FILES =	
S_FILES =	
H_FILES =	definition.h measure.h movements.h printing.h
SOURCEFILES =	$(H_FILES) $(CPP_FILES) $(C_FILES) $(S_FILES)
.PRECIOUS:	$(SOURCEFILES)
OBJFILES =	measure.o movements.o printing.o 

#
# Main targets
#

all:	bracetopia 

bracetopia:	bracetopia.o $(OBJFILES)
	$(CC) $(CFLAGS) -o bracetopia bracetopia.o $(OBJFILES) $(CLIBFLAGS)

#
# Dependencies
#

bracetopia.o:	definition.h measure.h movements.h printing.h
measure.o:	definition.h measure.h
movements.o:	definition.h movements.h
printing.o:	definition.h printing.h

#
# Housekeeping
#

Archive:	archive.tgz

archive.tgz:	$(SOURCEFILES) Makefile
	tar cf - $(SOURCEFILES) Makefile | gzip > archive.tgz

clean:
	-/bin/rm -f $(OBJFILES) bracetopia.o core

realclean:        clean
	-/bin/rm -f bracetopia 
