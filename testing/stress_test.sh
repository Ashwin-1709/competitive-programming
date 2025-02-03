g++ generator.cpp -std=c++17 -o gen
g++ brute.cpp -std=c++17 -o brute
g++ solution.cpp -std=c++17 -o sol
for((i = 1; ; ++i)) do
  echo test case $i
  ./gen $i > int
  ./sol < int > out1
  ./brute < int > out2
  diff -w out1 out2 || break
done