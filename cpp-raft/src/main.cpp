#include <iostream>
#include "RaftNode.h"

int main() {

    RaftNode node1(1);
    RaftNode node2(2);
    RaftNode node3(3);

    std::cout << "--- Node 1 starts election ---\n";

    node1.startElection();

    std::cout << "\n--- Node 2 receives vote request ---\n";

    bool vote2 = node2.requestVote(1, 1);

    std::cout << "Node 2 vote: "
              << (vote2 ? "YES" : "NO")
              << "\n";

    std::cout << "\n--- Node 3 receives vote request ---\n";

    bool vote3 = node3.requestVote(1, 1);

    std::cout << "Node 3 vote: "
              << (vote3 ? "YES" : "NO")
              << "\n";

    return 0;
}