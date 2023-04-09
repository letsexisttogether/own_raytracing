#pragma once

#include <vector>
#include <cstddef>

template<class _FileType>
class Reader
{
public:
	Reader(std::vector<std::byte>&& bytes)
		: m_Bytes{ std::move(bytes) }
	{}

	virtual ~Reader() {}

	virtual void Read() noexcept(false) = 0;
	
	inline const _FileType GetFormatedStruct() const noexcept { return m_UnformattedStruct; }

protected:
	// ��� ��� ����� ��������� ������� � Read, 
	// � ���� �����-�� �� ��� ������ false, ��������� exception
	virtual bool ReadHeader() noexcept = 0;
	virtual bool ReadContent() noexcept = 0;

protected:
	_FileType m_UnformattedStruct;
	std::vector<std::byte> m_Bytes;
};