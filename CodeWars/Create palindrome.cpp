
/* task: https://www.codewars.com/kata/5b7bd90ef643c4df7400015d/solutions/cpp?filter=me&sort=best_practice&invalids=false */

bool solve(std::string str) {
	for (size_t i = 0; i < str.length() / 2; i++)
	{
		int temp = std::abs(str[i] - str[str.length() - 1 - i]);
		if (temp != 2 && temp != 0)return false;
	}
	return true;
}

