strl=${#2}
n=0;
while [ $n -le $strl ];
do
	spstr="$spstr="
	n=$(($n+1))
done
echo "/*======$spstr"
echo "Program name: $1"
echo "Developer name: Aaron Schraner"
echo "Date: $(date +%m/%d/%Y)"
echo -e "Purpose: $2"
echo "========$spstr*/"


