EXE=../../../../../build-pld-comp-Desktop_Qt_5_8_0_GCC_64bit-Debug/bin/Debug/pld-comp
TESTDIR=.
ROUGE='\e[0;31m'
NEUTRE='\e[0;m'

testFiles=$(find $TESTDIR -name "*.c")

for file in $testFiles
do
	fileName=${file##*/}
	fileName=${fileName%.*}
	$EXE -O0 -o ${fileName}O0.s< $file &>temp.s
	result=$?
	if [ "$result" != "0" ]; then
	    echo -e "${fileName}.c fail to be compiled"
    else
		rm ${fileName}O0.s
	fi
done
rm temp.s   
