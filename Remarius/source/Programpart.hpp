#ifndef PROGRAMPART_HPP
#define PROGRAMPART_HPP


class CProgrampart
{
public:
	virtual void Tick(){ eventprocessing(); rendering(); }
	virtual void eventprocessing()=0;
	virtual void rendering()=0;
};

#endif