for((i=0 ; ; i++)); do
	echo $i
	./gen $i students$i.txt courses$i.txt
	./placer students.txt courses.txt > placer_out.txt
	./brute students.txt courses.txt brute_out.txt
	diff -w placer_out.txt brute_out.txt || break
done
