
program="maze.c"
testdata="./testdata/testdata.txt"
testdata_2="./testdata/testdata2"

#get test data and map it to variables
mapfile -t data <"$testdata"
mapfile -t data_2 <"$testdata_2"

#test file exists
if [-e "$program"]; then
    echo "the program exists - Pass"
else
    echo "the program doesnt exist- Fail"
    exit 0
fi

gcc maze.c -o maze
#compile code with debugging symbols

#run program to test for the validity of the maze

#test with invalid data
./maze ./testdata/invalid_maze.txt

#exit codes depending on returned value of main()
exit_code=$?
if [$exit_code -eq 0]; then
    echo "the program ran succsesfully- Pass"
elif [$exit_code -eq 1]; then
    echo "there was a problem with the maze file- Fail"
elif [$exit_code -eq 2]; then
    echo "invalid maze- Fail"
elif [$exit_code -eq 3]; then
    echo "invalid user input- Fail"
elif [$exit_code -eq 4]; then
    echo "datatype error- Fail"
else
    echo "Unexpected error- Fail"
fi


#test program to check if it ends correctly after user finishes the maze 1
for input in "${data[@]}"; do
    echo -e "$input" | ./maze ./testdata/maze1.txt > output.txt
    #execute program with inputs from the test data file

    if cmp -s output.txt "congrats! you have finished the maze"; then
        echo "Player is able to finish maze - Pass"
    else
        echo "program finished but no winning message was displayed - Fail"
    fi
    #test for user win message at the end of the program

    exit_code=$?
    if [$exit_code -eq 0]; then
        echo "the program ran succsesfully- Pass"
    elif [$exit_code -eq 1]; then
        echo "there was a problem with the maze file- Fail"
    elif [$exit_code -eq 2]; then
        echo "invalid maze- Fail"
    elif [$exit_code -eq 3]; then
        echo "invalid user input- Fail"
    elif [$exit_code -eq 4]; then
        echo "datatype error- Fail"
    else
        echo "Unexpected error- Fail"
    fi

#test for second maze completion     
for input in "${data_2[@]}"; do
    echo -e "$input" | ./maze ./testdata/maze2.txt > output.txt
    #execute program with inputs from the test data file

    if cmp -s output.txt "congrats! you have finished the maze"; then
        echo "Player is able to finish maze - Pass"
    else
        echo "program finished but no winning message was displayed - Fail"
    fi

    exit_code=$?
    if [$exit_code -eq 0]; then
        echo "the program ran succsesfully- Pass"
    elif [$exit_code -eq 1]; then
        echo "there was a problem with the maze file- Fail"
    elif [$exit_code -eq 2]; then
        echo "invalid maze- Fail"
    elif [$exit_code -eq 3]; then
        echo "invalid user input- Fail"
    elif [$exit_code -eq 4]; then
        echo "datatype error- Fail"
    else
        echo "Unexpected error- Fail"
    fi



