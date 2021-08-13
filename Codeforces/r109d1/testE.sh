for ((i=1;i<=1;i++))
do
	echo "generating test..."
	./genE >i.dat
	
	echo "solving test..."
	./stressE <i.dat >a.dat
	
	echo "getting output..."
	./E <i.dat >o.dat
	
	diff -bsq a.dat o.dat
	# -e `diff -bsq a.dat o.dat` "Files a.dat and o.dat differ" || exit
	echo ""
done
