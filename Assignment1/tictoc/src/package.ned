package tictoc3;

@license(LGPL);
//
// TODO documentation
//
network Network
{
    @display("bgb=534,252");
    submodules:
        Tic: Node {
            @display("p=125,90");
        }
        Toc: Node {
            @display("p=363,90");
        }
    connections:
        Toc.out --> Tic.in;
        Tic.out --> Toc.in;
}

