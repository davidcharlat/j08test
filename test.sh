let "n = 0"
nfile=$(find j08 -type f ! -regex '.*/\..*' -printf "0"|wc -c)

for file in 'ft' 'ft_boolean' 'ft_abs' 'ft_point'
do	
	if [ -f j08/ex0$n/$file.h ]
	then 
		gcc -o test$n $file.test.c
		./test$n firststring string2 "3rd str"
		let "n = n + 1"
	fi
done
if [ -f j08/ex04/ft_stock_par.h ] && [ -f j08/ex04/ft_param_to_tab.c ]
then
	gcc -o test4 ft_param_to_tab.test.c j08/ex04/ft_param_to_tab.c
	./test4 1st arg2 "3rd   argument"
	let "n = n + 2"
fi
if [ -f j08/ex05/ft_stock_par.h ] && [ -f j08/ex05/ft_show_tab.c ]
then
	gcc -o test5 ft_show_tab.test.c j08/ex05/ft_show_tab.c
	./test5 1st arg2 "3rd   argument"
	let "n = n + 2"
fi
if [ $n -eq $nfile ]
then
	echo "resultat = $n"
else
	echo "presence de fichiers autres que ceux specifies dans l'enonce -> resultat = 0"
fi
