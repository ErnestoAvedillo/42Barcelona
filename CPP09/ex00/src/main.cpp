#include "../inc/main.hpp"

int main (int av, char **ac)
{
	if (av < 2)
		return 0;
	std::ifstream fData;
	std::ifstream fIn ;
	std::string line;


	BtcData DataBase(DATA_CSV,',');
	BtcData input(ac[1], '|');
	std::cout << "Datos de entrada de Data:" << std::endl;
	std::vector<t_btc>::iterator l = DataBase.getEnd();
	for (std::vector<t_btc>::iterator i = DataBase.getBegin(); i < l; i ++)
		{
			try
			{
				std::cout << "Fecha: " << DataBase.getDate(i - DataBase.getBegin()) << "," << DataBase.getVal(i - DataBase.getBegin()) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	std::cout << "Datos de entrada de input:" << std::endl;
	l = input.getEnd();
	for (std::vector<t_btc>::iterator i = DataBase.getBegin(); i < l; i ++)
		try
		{
			std::cout << "Fecha: " << input.getDate(i - input.getBegin()) << "," << input.getVal(i- input.getBegin()) << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}

/*	while (std::getline(fData, line))
	{
		std::cout << "paso " << line << std::endl;
	}
	fIn.open(ac[1], std::ios::in);
	if (!fIn)
		std::cout << "File " << ac[1] <<" couldn't be opened" << std::endl;
	while (std::getline(fIn, line))
	{
		std::cout << line << std::endl;
	}*/
}
