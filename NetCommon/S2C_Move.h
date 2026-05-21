#pragma once
#include "Packet.h"
class S2C_Move : public IPacket
{
public:


	// Inherited via IPacket
	void Parse(std::string InString) override;

	std::string ToString() override;

};

