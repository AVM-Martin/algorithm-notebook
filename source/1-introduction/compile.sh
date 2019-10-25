if [ $# -eq 0 ] || [ ! -f "$1" ] ; then
	echo -e "File does not exist"
elif g++ -std=c++11 -lm -o "ZZZ" "$1" ; then
	./"ZZZ" # < "stdin.in" > "stdout.out" 2> "stderr.err"
fi
