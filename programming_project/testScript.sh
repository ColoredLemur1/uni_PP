
program="maze.c"
valid_testdata="testdatavalid.txt"
invalid_testdata="testdatainvalid.txt"

#get test data and map it to arrays
mapfile -t valid_data_array < "$valid_testdata"
mapfile -t invalid_data_array < "$invalid_testdata"



#test file exists
if [-e "$program"]; then
    echo "the program exists - Pass"
else
    echo "the program doesnt exist- Fail"
    exit 0
fi

gcc maze.c -o maze
#compile code

#run program
./maze

#test with invalid data
for input in "${invalid_data_array[@]}"; do





#test for exit codes depending on returned value
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
