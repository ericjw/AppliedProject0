#include <string>
#include <iomanip>
#include <fstream>

using std::string;
using std::ifstream;
using std::ofstream;

int main(int argc, char*argv[])
{
	if (argc == 2)
	{
		std::ifstream instream(argv[1], std::ios::binary);

		uint8_t value;
		while (!instream.fail())
		{
			instream.read(reinterpret_cast<std::fstream::char_type*>(&value), sizeof value);
		}

		EXIT_SUCCESS;
	}
	else 
		EXIT_FAILURE;
	return 0;
}