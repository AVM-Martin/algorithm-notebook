if [ $# -eq 0 ] || [ ! -f "$1" ]; then
	echo -e "File does not exist"
	exit 1
fi
# compile
if g++ -std=c++11 -lm -o "ZZZ" "$1" ; then
	echo -e "==================================================="
	./"ZZZ"
	# ./"ZZZ" < "stdin.in" > "stdout.out" 2> "stderr.err"
	echo -e ""
	echo -e "==================================================="
fi