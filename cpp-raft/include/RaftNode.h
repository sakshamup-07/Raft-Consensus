#pragma once

enum class NodeState {
    FOLLOWER,
    CANDIDATE,
    LEADER
};

class RaftNode {
private:
    int nodeId;
    int currentTerm;
    int votedFor;
    int votesReceived;
    NodeState state;

public:
    RaftNode(int id);

    void startElection();
    bool requestVote(int candidateId, int candidateTerm);
    void receiveVote(bool granted);
    void printState() const;
};