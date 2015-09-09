CXX = c++
RM = rm -f
CXXFLAGS = -std=c++11 -I.

all: test_mtbound

test_mtbound: test_mtbound.cc
	$(CXX) $^ -o $@ $(CXXFLAGS)

clean:
	$(RM) test_mtbound
