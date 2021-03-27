main: test
	./test.sh

test: data test.cpp
	g++ test.cpp -I../.. -o test 

data: gen
	cd data && ../gen

gen: gen.cpp
	g++ gen.cpp -I../.. -o gen

clean:
	-rm gen test data/* log/*