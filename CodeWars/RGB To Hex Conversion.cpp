#include <iostream>

/*link: https://www.codewars.com/kata/513e08acc600c94f01000001/train/cpp */

std::string rgb_to_hex(int r, int g, int b)
{
    int rgb[3]{ r,g,b };
    std::string hex;
	for (size_t i = 0; i < 3; i++)
	{
		if (rgb[i] < 0)rgb[i] = 0;
		else if (rgb[i] > 255)rgb[i] = 255;

		// converting to base 16
		std::string buf;
		while (rgb[i] != 0)
		{
			int temp = rgb[i] % 16;
			rgb[i] /= 16;
			if (temp < 10)buf.insert(0, 1, temp += 48);
			else buf.insert(0, 1, temp += 55);
		}
		if (buf.empty())hex += "00";
		else if (buf.length() == 1)hex += buf.insert(0, 1, '0');
		else hex += buf;


	}
    return hex;
}

int main()
{
    std::cout << rgb_to_hex(0, 0, 0);


}
