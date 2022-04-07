#pragma oonce
#include<iostream>
class Score
{
public:
	float English;
	float Math;
	float program_design;
	float PE;
	Score() {}
    Score(float a, float b, float c, float d);
	Score(const Score &obj);
	friend std::ostream &operator<<(std::ostream &os, Score &s);
    Score &operator+=(Score obj);
    Score &operator=(Score obj);
};