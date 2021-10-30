//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
// 

#include "Node.h"
#include <string>
using namespace std;

Define_Module(Node);

void Node::initialize()
{
    cMessage* msg = new cMessage("Hi");
    scheduleAt(simTime(), msg);
}

void Node::handleMessage(cMessage *msg)
{
    int NodeId = (getId() - 2);
    if(msg->isSelfMessage()) {
        //delay is finished

        //logging
        EV << "{self message received}" << endl;

        //uniform sampling
        double rand = (int)uniform(0, gateSize("port"));

        //send message to a random node
        send(new cMessage("Hello"), "port$o", rand);

        //sleep
        double interval = exponential(1 / par("lambda").doubleValue());
        scheduleAt(simTime() + (int)interval, new cMessage("self msg"));
    } else {
        EV << "node " << NodeId << " " << "recevied: " << msg << endl;
    }
}
