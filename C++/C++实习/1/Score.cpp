#pragma once
#include "Score.h"
Score::Score(float a, float b, float c, float d) : English(a), Math(b), program_design(c), PE(d) {

}

Score::Score(const Score &obj){
	this->English = obj.English;
	this->Math = obj.Math;
	this->PE = obj.PE;
	this->program_design = obj.program_design;
}
std::ostream &operator<<(std::ostream &os, Score &s)
{
	os << " English: " << s.English
	   << " Math: " << s.Math
	   << " program_design: " << s.program_design
	   << " PE:" << s.PE;
	return os;
}
Score &Score::operator+=(Score obj)
{
	English += obj.English;
	Math += obj.Math;
	program_design += obj.program_design;
	PE += obj.PE;
	return *this;
}
Score &Score::operator=(Score obj){
	this->English = obj.English;
	this->Math = obj.Math;
	this->PE = obj.PE;
	this->program_design = obj.program_design;
	return *this;
}