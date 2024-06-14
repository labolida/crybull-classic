# Crybull classic

Command line tool to encode files with password.

    crybull mysecretkey mymessage.txt encrypted-message.x

    base64 encrypted-message.x > sendToaFriend.x

 Recursive

    find -type f -exec echo crybull $pwd {} {}.crp \;


# Compile and test it

File "comp"

    #!/bin/bash
    clear 


    export KEYPASS1=$(cat key-password-001)
    export KEYPASS2=$(cat key-password-002)

    echo "Using password1: " $KEYPASS1
    echo "Using password2: " $KEYPASS2


    rm crybull
    gcc crybull.c  -o crybull

    ./crybull



    ./crybull $KEYPASS1 message temp1

    ./crybull $KEYPASS2 temp1 temp2

    ./crybull $KEYPASS2 temp2 temp1

    ./crybull $KEYPASS1 temp1 decoded

    cat decoded


