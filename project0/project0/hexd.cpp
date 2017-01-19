#include <string>
#include <iomanip>
#include <fstream>
#include <iostream>
#include <bitset>
#include <cstdlib>
#include <stdint.h>

/*
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::bitset;
using std::hex;
using std::endl;
*/
using namespace std;

int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		std::ifstream instream(argv[1], std::ios::binary);

		uint8_t value;
		while (!instream.fail())
		{
			instream.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
			std::bitset<8> set(value);
			cout << setfill('0') << setw(2) << hex << set.to_ulong() << endl;
		}

		return EXIT_SUCCESS;
	}
	else 
		return EXIT_FAILURE;
}