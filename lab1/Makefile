
PIZZA = pizza.o dough.o chicken.o cheese.o
PASTA = pasta.o spaghetti.o herb.o chicken.o cheese.o
SOUP = soup.o
#You might want to use the variable $(LUNCHSET) some points later in this lab.
#The variable will take the union of the set PIZZA, PASTA, and SOUP.
LUNCHSET = $(sort $(PIZZA) $(PASTA) $(SOUP))

#@TODO Edit all target
all: soup.exe pizza.exe pasta.exe Lunchset.exe

#@TODO Add new targets
soup.exe: $(SOUP) mainSoup.cpp
	g++ -o $@ -std=c++11 $(SOUP) mainSoup.cpp

pizza.exe: $(PIZZA) mainPizza.cpp
	g++ -o $@ -std=c++11 $(PIZZA) mainPizza.cpp

pasta.exe: $(PASTA) mainPasta.cpp
	g++ -o $@ -std=c++11 $(PASTA) mainPasta.cpp

Lunchset.exe: $(LUNCHSET) mainLunchset.cpp
	g++ -o $@ -std=c++11 $(LUNCHSET) mainLunchset.cpp

%.o: %.cpp
	g++ -std=c++11 -c $< -o $@ 

clean:
	rm -f *.o *.exe
