#ifndef ACLENTRY_H
#define ACLENTRY_H

#include <string>
#include "ns3/uinteger.h"
#include "ns3/boolean.h"
#include "ns3/pointer.h"
#include "ns3/ppp-header.h"
#include "ns3/udp-header.h"
#include "ns3/tcp-header.h"
#include "ns3/ipv4-header.h"
#include "ns3/packet.h"
#include "ns3/ipv4-address.h"


namespace ns3{

enum ACLProtocol {ip, icmp, tcp, udp};

class ACLEntry  {
private:
  Ipv4Address sourceIPAddress;
  Ipv4Mask sourceMask;
  uint32_t sourcePortNumber;
  Ipv4Address DestinationIPAddress;
  Ipv4Mask DestinationMask;
  uint32_t DestinationPortNumber;
  ACLProtocol protocol;
  Ipv4Mask InverseMask;

public:
  ACLEntry ();
  virtual ~ACLEntry ();

  bool match(Ptr<Packet> p);

  void setSourceIPAddress (Ipv4Address new_var);

  Ipv4Address getSourceIPAddress ();

  void setSourceMask (Ipv4Mask new_var);

  Ipv4Mask getSourceMask ();

  void setSourcePortNumber (uint32_t new_var);

  uint32_t getSourcePortNumber ();

  void setDestinationIPAddress (Ipv4Address new_var);

  Ipv4Address getDestinationIPAddress ();

  void setDestinationMask (Ipv4Mask new_var);

  Ipv4Mask getDestinationMask ();

  void setDestinationPortNumber (uint32_t new_var);

  uint32_t getDestinationPortNumber ();

  void setProtocol (ACLProtocol new_var);

  ACLProtocol getProtocol ();

};
}
#endif // ACLENTRY_H

