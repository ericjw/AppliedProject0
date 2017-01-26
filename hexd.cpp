#include <fstream>
#include <iostream>
#include <cstdlib>
#include <stdint.h>

using namespace std;
int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		ifstream instream(argv[1], ios::binary);
		uint8_t value;
		int position = 0;

		while (!instream.fail())
		{
			char buff[16];
			int valid;

			for (valid = 0; valid < 16 && instream; valid++)
			{
				instream.read(reinterpret_cast<fstream::char_type*>(&value), sizeof value);
				if (!instream)
					break;
				buff[valid] = value;
			}

			if (valid == 0)
				break;
			printf("%07x:", position);
			
			for (int i = 0; i < 16; i++)
			{
				if (i % 2 == 0)
					cout << ' ';
				if (i < valid)
				{
					printf("%02x", (uint8_t)buff[i]);
				}
				else
					cout << "  ";
			}

			cout << "  ";

			for (int i = 0; i < valid; i++)
			{
				if (buff[i] < 32 || buff[i] > 126)
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