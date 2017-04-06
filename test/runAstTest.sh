EXE=../../build-pld-comp-Desktop_Qt_5_8_0_GCC_64bit-Debug/bin/Debug/pld-comp
TESTDIR=OptimisationTest

testFiles=$(find $TESTDIR -name "*.c")

for file in $testFiles
do
	fileName=${file##*/}
	fileName=${fileName%.*}
	$EXE -O0 -o ${fileName}O0.s < $file &>temp.s
	result=$?
	echo "$result for file $fileName"
	if [ "$result" == "0" ]; then
		as ${fileName}O0.s -o ${fileName}O0.o
		gcc ${fileName}O0.o -o ${fileName}O0
		rm ${fileName}O0.o
	fi
	$EXE -O1 -o ${fileName}O1.s < $file &>temp.s
	result=$?
	echo "$result for file $fileName"
	if [ "$result" == "0" ]; then
		as ${fileName}O1.s -o ${fileName}O1.o
		gcc ${fileName}O1.o -o ${fileName}O1
		rm ${fileName}O1.o
	fi
	$EXE -O2 -o ${fileName}O2.s < $file &>temp.s
	result=$?
	echo "$result for file $fileName"
	if [ "$result" == "0" ]; then
		as ${fileName}O2.s -o ${fileName}O2.o
		gcc ${fileName}O2.o -o ${fileName}O2
		rm ${fileName}O2.o
	fi
done
rm temp.s
