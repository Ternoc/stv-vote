#ifndef VOTERESULT_H
#define VOTERESULT_H
#include <vector>
#include <string>

struct VoteResult
{
	std::vector<std::string> orderedCandidates;
	std::string electorName;
};

#endif // VOTERESULT_H
