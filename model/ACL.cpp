#include "ACL.h"

namespace ns3{

ACL::ACL ()  {

}

ACL::~ACL ()  {

}

bool ACL::match (Ptr<Packet> p) {
	return true;
}

void ACL::setId (string new_var)   {
      id = new_var;
}

string ACL::getId ()   {
    return id;
}

void ACL::setAclEntries (std::vector<ACLEntry> new_var)   {
      aclEntries = new_var;
}

std::vector<ACLEntry> ACL::getAclEntries ()   {
    return aclEntries;
}

}
