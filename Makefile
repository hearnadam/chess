TARGET = chess

# Using g++ to compile and link
CC       = g++

# locations for sources and objects
SRCDIR   = ./src
OBJDIR   = ./obj
BINDIR   = ./bin
INCDIR 	= ./include

# compiling flags here
CFLAGS   = -Wall -std=c++11 -g -I $(INCDIR) # For debugging
#CFLAGS   = -Wall -std=c++11 -I $(INCDIR)

# get a list of all the sources and replace the suffix with .o to create
# a list of all the object files we need
OBJECTS  = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(notdir $(wildcard $(SRCDIR)/*)))))
# get a list of all include files
INCLUDES = $(wildcard $(INCDIR)/*)

# Default target depends on all objects
$(BINDIR)/$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(BINDIR)/$(TARGET) $(OBJECTS)

# Object files depend on corresponding source and ALL includes; could be
# more precise with includes, but this covers all bases
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp $(INCLUDES)
	$(CC) -c -o $@ $< $(CFLAGS)

# Delete objects and binary
clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/*
