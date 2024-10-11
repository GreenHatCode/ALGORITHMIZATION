#0.3 0.7 0.9 1.3 1.7 1.9 2.3 2.7 2.9 3.3 3.7 
# reading input
$input_vals = @()
for($i=0; $i -lt 11; $i++){
	$input_vals += $args[$i]
}

# calculating sum
$sum=0.0
foreach($num in $input_vals){
	$sum+=1+[math]::Sin($num)+[math]::Sin(($num/2))
}
echo "result: $sum"