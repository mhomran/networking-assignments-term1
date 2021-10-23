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
    if(strcmp(getName(), "Tic") == 0) {
        cMessage* msg = new cMessage("hello");
        send(msg, "out");
    }
}

void Node::handleMessage(cMessage *msg)
{
    static uint32_t count = 0;
    if(strcmp(getName(), "Tic") == 0)
        {

                cMessage* msg;

                string tmp = "hello" + to_string(count);
                msg = new cMessage(tmp.c_str());

                send(msg, "out");
        }
    else if(strcmp(getName(), "Toc") == 0) {
        cMessage* msg;
        if(count == 0) {
            msg = new cMessage("hi");
        } else {
            string tmp = "hi" + to_string(count);
            msg = new cMessage(tmp.c_str());
        }
        send(msg, "out");
        count++;
    }
}
