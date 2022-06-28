
start=1
end=10000
read num
declare -a prime

function init_prime() {
	local end=$1
	local i
	prime[1]=1
	for (( i=2; i <= ${end}; i++ ));do
		for (( j=$[ 2 * ${i} ]; j <= ${end}; j+=i ));do
			prime[${j}]=1	
		done
    done
}

init_prime 10000

sum=0
for (( i=${start}; i<=${end}; i++ ));do
	if [[ ${prime[$i]}x == x ]];then
		sum=$[ ${sum} + 1 ]
        if (( ${sum} == ${num} ));then
             echo $i
        fi
	fi
done

#echo ${sum}


