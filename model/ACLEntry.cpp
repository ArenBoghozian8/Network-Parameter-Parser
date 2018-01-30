#include "ACLEntry.h"

namespace ns3{

ACLEntry::ACLEntry () {

}

ACLEntry::~ACLEntry ()  {

}

bool ACLEntry::match (Ptr<Packet> p)  {
	bool matching = true;
	Ipv4Header ip;
	PppHeader ppp;
	p->RemoveHeader(ppp);
	p->RemoveHeader(ip);
	
	if((sourceIPAddress != ip.GetSource()) || (DestinationIPAddress != ip.GetDestination()))
		matching = false;

	if((protocol == ip.GetProtocol())==17){
		UdpHeader udp;
		p->PeekHeader(udp);
		if((DestinationPortNumber != udp.GetDestinationPort()) || (sourcePortNumber != udp.GetSourcePort()))
			matching = false;		
	}
	else if((protocol == ip.GetProtocol())==6){
		TcpHeader tcp;
		p->PeekHeader(tcp);
		if((DestinationPortNumber != tcp.GetDestinationPort()) || (sourcePortNumber != tcp.GetSourcePort()))
			matching = false;
	}	

	p->AddHeader(ip);
	p->AddHeader(ppp);
	return matching;
}

void ACLEntry::setSourceIPAddress (Ipv4Address new_var)   {
      sourceIPAddress = new_var;
}

Ipv4Address ACLEntry::getSourceIPAddress ()   {
    return sourceIPAddress;
}

void ACLEntry::setSourceMask (Ipv4Mask new_var)   {
      sourceMask = new_var;
}

Ipv4Mask ACLEntry::getSourceMask ()   {
    return sourceMask;
}

void ACLEntry::setSourcePortNumber (uint32_t new_var)   {
      sourcePortNumber = new_var;
}

uint32_t ACLEntry::getSourcePortNumber ()   {
    return sourcePortNumber;
}

void ACLEntry::setDestinationIPAddress (Ipv4Address new_var)   {
      DestinationIPAddress = new_var;
}

Ipv4Address ACLEntry::getDestinationIPAddress ()   {
    return DestinationIPAddress;
}

void ACLEntry::setDestinationMask (Ipv4Mask new_var)   {
      DestinationMask = new_var;
}

Ipv4Mask ACLEntry::getDestinationMask ()   {
    return DestinationMask;
}

void ACLEntry::setDestinationPortNumber (uint32_t new_var)   {
      DestinationPortNumber = new_var;
}

uint32_t ACLEntry::getDestinationPortNumber ()   {
    return DestinationPortNumber;
}

void ACLEntry::setProtocol (ACLProtocol new_var)   {
      protocol = new_var;
}

ACLProtocol ACLEntry::getProtocol ()   {
    return protocol;
}


}

