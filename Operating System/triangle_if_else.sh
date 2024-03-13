read -p "enter first length: " l1
read -p "enter second length: " l2
read -p "enter third length: " l3

if [ $l1 -eq $l2 -a $l2 -eq $l3 ] 
then
    echo "all are equal"
elif [ $l1 -eq $l2 -o $l2 -eq $l3 -o $l1 -eq $l3 ]
then
    echo "two are equal"
else 
    echo "three length are different"
fi


