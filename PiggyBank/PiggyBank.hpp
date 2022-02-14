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

	/** Returns how much is in the piggy bank
	* @return Money in the piggy bank
	*/
	double countSavings() const;

	void deposit(double money);

	void withdraw(double money);

	

private:
	double m_balance;
	bool m_state;
};


#endif