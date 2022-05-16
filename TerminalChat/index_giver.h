#pragma once
#include <stdint.h>
#include <vector>
#include <ctime>

using std::vector;

class index_giver {
	vector<uint32_t> Register;
	uint32_t X;
	uint32_t A;
	uint32_t C;
public:
	index_giver(uint32_t seed = time(NULL)) {
		A = 214013;
		C = 2531011;
		X = seed;
	}

	bool check_userindex(uint32_t userindex) {
		for(size_t i = 0;i<Register.size();i++)
			if(Register[i]==userindex)
				return true;
		return false;
	}

	uint32_t give_userindex() {
		X = X * A + C;
		Register.push_back(X);
		return X;
	}
};
