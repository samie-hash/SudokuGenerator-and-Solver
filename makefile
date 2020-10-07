# define the compiler to use
CXX = clang++
CXXFLAGS = -Wall -g

# include the headers folder
INCLUDES = -I/include

# define the source files
SRCS = $(wildcard *.cc) 

# define c++ object files
OBJS = $(SRCS:.cc = .o )

# name of the executable
MAIN = Sudoku

.PHONY: depend clean

all: $(MAIN)
	@echo Simple program, Sudoku has been compiled sucessfully

$(MAIN) : $(OBJS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -o $(MAIN) $(OBJS)

.cc.o:
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f *.o *~ $(MAIN)

depend: $(SRCS)
	makedepend $(INCLUDES) $^