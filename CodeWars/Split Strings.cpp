#include <iostream>
#include <string>
#include <vector>

/*https://www.codewars.com/kata/515de9ae9dcfc28eb6000001/cpp*/

std::vector<std::string> solution(const std::string& s)
{
	std::vector<std::string> res_string;
	if (s.length() % 2)
	{
		for (size_t i = 0; i < s.length() - 1; i += 2)
			res_string.push_back(s.substr(i, 2));

		res_string.push_back(s.substr(s.length() - 1) + "_");
	}
	else
	{
		for (size_t i = 0; i < s.length(); i += 2)
			res_string.push_back(s.substr(i, 2));
	}
	return res_string;
}
int main() {
	solution("abcdef");
	solution("HelloWorld");
	solution("abcde");
	solution("LovePizza");
	return 0;
}
