/* source link: https://www.codewars.com/kata/546e2562b03326a88e000020/solutions/cpp */
int square_digits(int num) {
	int result = 0;
	int i = 0;
	while (num > 0)
	{
		int squared_digit = pow(num % 10, 2);
		result += squared_digit * pow(10, i);
		if (squared_digit < 10)i += 1;
		else i += 2;

		num /= 10;
	}
	return result;
}