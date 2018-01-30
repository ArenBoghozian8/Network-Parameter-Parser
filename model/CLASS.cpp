#include "CLASS.h"

namespace ns3{

CLASS::CLASS () {

}

CLASS::~CLASS () {

}

bool CLASS::match (Ptr<Packet> p)  {
	return true;
}

void CLASS::setId (string new_var)   {
      id = new_var;
  }

string CLASS::getId ()   {
    return id;
  }

void CLASS::setAcls (std::vector<ACL> new_var)   {
      acls = new_var;
  }

std::vector<ACL> CLASS::getAcls ()   {
    return acls;
  }

void CLASS::setBytes (uint32_t new_var)   {
      bytes = new_var;
  }

uint32_t CLASS::getBytes ()   {
    return bytes;
  }

void CLASS::setPackets (uint32_t new_var)   {
      packets = new_var;
  }

uint32_t CLASS::getPackets ()   {
    return packets;
  }

void CLASS::setMaxPackets (uint32_t new_var)   {
      maxPackets = new_var;
  }

uint32_t CLASS::getMaxPackets ()   {
    return maxPackets;
  }

void CLASS::setMaxBytes (uint32_t new_var)   {
      maxBytes = new_var;
  }

uint32_t CLASS::getMaxBytes ()   {
    return maxBytes;
  }

void CLASS::setWeight (double_t new_var)   {
      weight = new_var;
  }

double_t CLASS::getWeight ()   {
    return weight;
  }

void CLASS::setIsDefault (bool new_var)   {
      isDefault = new_var;
  }

bool CLASS::getIsDefault ()   {
    return isDefault;
  }

}
