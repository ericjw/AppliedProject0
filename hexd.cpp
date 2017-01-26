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
			
			printf("%07x:", position); // prints address
			

			for (int i = 0; i < 16; i++)
			{
				instream.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
				if (!instream)
					break;
				bitset<8> set(value);
				if (i % 2 == 0)
					cout << ' ';
				cout << hex << setfill('0') << setw(2) << set.to_ulong();
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