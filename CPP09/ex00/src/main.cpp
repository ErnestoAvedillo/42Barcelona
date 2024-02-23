#include "../inc/main.hpp"

int main (int av, char **ac)
{
    if (av < 2)
        return 0;
//    std::string fDataStr = DATA;
//    std::string fInStr(ac[1]);
    std::ifstream fData;
    std::ifstream fIn ;
    std::string line;

    fData.open(DATA_CSV, std::ios::in);
	if (!fData)
	{
		std::cout << "File Data.csv couldn't be opened." << std::endl;
		return 0;
	}

    std::cout << "paso" << std::endl;
	while (std::getline(fData, line))
	{
		std::cout << "paso " << line << std::endl;
	}
    fIn.open(ac[1], std::ios::in);
    if (!fIn)
        std::cout << "File " << ac[1] <<" couldn't be opened" << std::endl;
    while (std::getline(fIn, line))
    {
		std::cout << line << std::endl;
    }
}