#ifndef PIGGYBANK_HPP
#define PIGGYBANK_HPP

class PiggyBank 
{
public: 

	/** Default Constructor
	*/
	PiggyBank();

	/** Parameter Constructor
	* @param[in] balance - How much money is in the piggy bank
	*/
	PiggyBank(double balance);

	/** Deconstructor
	*/
	~PiggyBank();

	/** Copy Constructor
	*/
	PiggyBank(PiggyBank const& pb) = delete;


private:
	double m_balance;
	bool m_state;
};


#endif