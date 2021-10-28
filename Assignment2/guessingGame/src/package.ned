package guessinggame;

import ned.IBidirectionalChannel;


@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=243.82,162.825");
    types:
    submodules:
        player1: Player1 {
            @display("p=53,76");
        }
        player2: Player2 {
            @display("p=172,76;is=vl");
        }
    connections:
        player1.out --> player2.in;
        player2.out --> player1.in;
}

