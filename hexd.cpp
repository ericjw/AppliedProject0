#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <stdint.h>

using namespace std;

int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		std::ifstream instream(argv[1], std::ios::binary);
		uint8_t value;
		int position = 0;

		while (!instream.fail())
		{
			char buff[16];
			int valid;

			for (valid = 0; valid < 16 && instream; valid++)
			{
				instream.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
				if (!instream)
					break;
				bitset<8> set(value);
				buff[valid] = set.to_ulong();
			}
			if (valid == 0)
				break;
			printf("%07x:", position); // prints address
			
			for (int i = 0; i < 16; i++)
			{
				if (i % 2 == 0)
					cout << ' ';
				if (i < valid)
				{
					//cout << hex << setfill('0') << setw(2) << buff[i];
					printf("%02x", (uint8_t)buff[i]);
				}
				else
					cout << "  ";
			}

			cout << "  ";

			for (int i = 0; i < valid; i++)
			{
				if (buff[i] < 32)
					cout << '.';
				else
					cout << buff[i];
			}
			
			cout << endl;

			position += 16;
		}
		
		return EXIT_SUCCESS;
	}
	else
		cout << "Incorrect number of arguments" << endl;
		return EXIT_FAILURE;
}