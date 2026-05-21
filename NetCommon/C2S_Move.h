#pragma once
#include "Packet.h"
class C2S_Move : public IPacket
{
public:

	// Inherited via IPacket
	void Parse(std::string InString) override;
	std::string ToString() override;
};

