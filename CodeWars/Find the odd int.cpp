
/*source link: https://www.codewars.com/kata/54da5a58ea159efa38000836/train/cpp */

int findOdd(const std::vector<int>& numbers) {
	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	for (size_t i = 0; i < sortedNumbers.size(); i++)
	{
		int key = sortedNumbers[i];
		int count = 0;
		size_t j = i;
		for (; j < sortedNumbers.size(); j++, count++)
			if (sortedNumbers[j] != key)break;
		if (count % 2 != 0)return key;
		i = j - 1;
	}
	return 0;
}