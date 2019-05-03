#include "MiniginPCH.h"
#include "BinaryReader.h"


BinaryReader::BinaryReader()
{
}


BinaryReader::~BinaryReader()
{
}

std::string BinaryReader::ReadString(const int& size)
{
	std::string returnString{};
	m_File.open("Ex1.bin", std::ios::in | std::ios::binary);
	if (m_File.is_open())
	{
		m_File.seekg(m_CurrentPos);
		returnString.resize(size);
		m_File.read(&returnString[0], returnString.size());
		m_CurrentPos = m_File.tellg();
		m_File.close();
	}
	return returnString;
}
