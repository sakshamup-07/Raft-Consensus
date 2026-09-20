#include "RaftNode.h"
#include <iostream>

RaftNode::RaftNode(int id)
    : nodeId(id),
      currentTerm(0),
      votedFor(-1),
         votesReceived(0),

      state(NodeState::FOLLOWER) {
}

void RaftNode::startElection() {

    currentTerm++;

    state = NodeState::CANDIDATE;

    votedFor = nodeId;

    std::cout << "Node " << nodeId << " started an election.\n";
    std::cout << "Current Term: " << currentTerm << "\n";
    std::cout << "State: CANDIDATE\n";
    std::cout << "Voted for itself.\n";
}
bool RaftNode::requestVote(int candidateId, int candidateTerm) {

    // Candidate has an older term
    if (candidateTerm < currentTerm) {
        return false;
    }

    // Candidate has a newer term
    if (candidateTerm > currentTerm) {
        currentTerm = candidateTerm;
        state = NodeState::FOLLOWER;
        votedFor = -1;
    }

    // Already voted for someone else
    if (votedFor != -1 && votedFor != candidateId) {
        return false;
    }

    // Give vote
    votedFor = candidateId;

    return true;
}

void RaftNode::printState() const {
    std::cout << "Node ID: " << nodeId << "\n";
    std::cout << "Current Term: " << currentTerm << "\n";
    std::cout << "State: FOLLOWER\n";
    std::cout << "Voted For: " << votedFor << "\n";
}