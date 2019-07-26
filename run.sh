if [[ ${1} != "" ]]; then
	g++ -std=c++14 -O2 ${1} && ./a.out < input.txt
else
	echo "provide filename"
fi

