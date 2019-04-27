#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <strstream>

class BinaryReader
{
public:
	BinaryReader();
	~BinaryReader();
	template <typename T>
	void Read (T& obj);
	std::string ReadString(int size);
private:
	std::ifstream m_File;
	std::strstream::pos_type m_CurrentPos{};
};

template<typename T>
inline void BinaryReader::Read(T & obj)
{
	m_File.open("Ex1.bin", std::ios::in | std::ios::binary);
	if (m_File.is_open())
	{
		m_File.seekg(m_CurrentPos);
		m_File.read((char *)&obj, sizeof(obj));
		m_CurrentPos = m_File.tellg();
		m_File.close();
	}
}
