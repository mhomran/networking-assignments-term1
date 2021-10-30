package mesh_traffic;

@license(LGPL);

network Network
{
    parameters:
        int N = default(4);
        @display("bgb=554,299");
    submodules:
        nodes[N]: Node {
            //@display("p=139,108");
        }
    connections:
        for i=0..N-1, for j=i+1..N-1 {
            nodes[i].port++ <--> nodes[j].port++;
        }
}
