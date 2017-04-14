#ifndef __DEMO_SERVER_H__
#define __DEMO_SERVER_H__

// This autogenerated skeleton file illustrates how to build a server.
// You should copy it to another filename to avoid overwriting it.
#include "Demo.h"
#include <thrift/transport/TSocket.h>
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TThreadedServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>
#include <iostream>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::demo_thrift;

class DemoHandler : virtual public DemoIf {
 public:
  DemoHandler() {
    // Your initialization goes here
  }

  /**
   * A method definition looks like C code. It has a return type, arguments,
   * and optionally a list of exceptions that it may throw. Note that argument
   * lists and exception lists are specified using the exact same syntax as
   * field lists in struct or exception definitions.
   */
  void ping();

  int32_t add(const int32_t num1, const int32_t num2);
  int32_t calculate(const int32_t logid, const Work& w);
  /**
   * This method has a oneway modifier. That means the client only makes
   * a request and does not listen for any response at all. Oneway methods
   * must be void.
   */
  void zip();

  void query(std::string& _return, const std::string& request);

};

/*
  DemoCloneFactory is code generated.
  DemoCloneFactory is useful for getting access to the server side of the
  transport.  It is also useful for making per-connection state.  Without this
  CloneFactory, all connections will end up sharing the same handler instance.
*/
class DemoCloneFactory : virtual public DemoIfFactory {
 public:
  virtual ~DemoCloneFactory() {}
  virtual DemoIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo)
  {
    boost::shared_ptr<TSocket> sock = boost::dynamic_pointer_cast<TSocket>(connInfo.transport);
    std::cout << "Incoming connection\n";
    std::cout << "\tSocketInfo: "  << sock->getSocketInfo() << "\n";
    std::cout << "\tPeerHost: "    << sock->getPeerHost() << "\n";
    std::cout << "\tPeerAddress: " << sock->getPeerAddress() << "\n";
    std::cout << "\tPeerPort: "    << sock->getPeerPort() << "\n";
    return new DemoHandler;
  }

  virtual void releaseHandler(DemoIf* handler){//( ::shared::SharedServiceIf* handler) {
    //delete handler;
  }

};


#endif // __DEMO_SERVER_H__