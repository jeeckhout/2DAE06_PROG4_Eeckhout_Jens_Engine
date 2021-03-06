#pragma once
#include <fstream>
#include <string>
class BinaryWriter
{
public:
	BinaryWriter();
	~BinaryWriter();
	template <typename T>
	void Write(const T& obj);
	void WriteString(const std::string& str);
private:
	std::ofstream m_File;

};

template<typename T>
void BinaryWriter::Write(const T & obj)
{
	m_File.open("Ex1.bin", std::ios::out | std::ios::binary | std::ios::app);
	if (m_File.is_open())
	{
		m_File.write((const char *)&obj, sizeof(obj));
		m_File.close();
	}
}
