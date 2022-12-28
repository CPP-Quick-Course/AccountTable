#include "File.h"

File::File(std::string filename)
{
	m_file.open(filename);
	if (!m_file)
	{
		std::cout << "Can't open file " << filename << std::endl;
		exit(1);
	}
}

File::~File()
{
	m_file.close();
}

void File::writeTable(Table* table)
{
	m_file << table->getHeader();
	for (int i = 0; i < table->getRowsCount(); ++i)
	{
		m_file << table->getRow(i) << std::endl;
		m_file << table->getFooter() << std::endl;
	}
}