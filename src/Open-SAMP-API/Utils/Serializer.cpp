#include "Serializer.hpp"

Utils::Serializer::Serializer()
{
	_oa = SafeBlock::safeMakeShared<oarchive>(_ss);
}

Utils::Serializer::Serializer(const char * const _data, const unsigned int len) : _ss(std::string(_data, len))
{
	_ia = SafeBlock::safeMakeShared<iarchive>(_ss);
}

Utils::Serializer::~Serializer()
{
	SafeBlock::safeExecute([&](){
		_oa.reset();
		_ia.reset();
	});
}

const char * Utils::Serializer::data()
{
	_ss_str = _ss.str();
	return _ss_str.c_str();
}

void Utils::Serializer::setData(const char *szData, const size_t size)
{
	_ss = std::stringstream(std::string(szData, size));
	_ia = SafeBlock::safeMakeShared<iarchive>(_ss);
}

int Utils::Serializer::numberOfBytesUsed() const
{
	return _ss.str().length();
}
