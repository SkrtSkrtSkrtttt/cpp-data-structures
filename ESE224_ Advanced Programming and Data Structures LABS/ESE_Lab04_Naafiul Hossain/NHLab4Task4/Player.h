//Naafiul Hossain
//SBU ID: 115107623
#pragma once
class Player {
public:
	Player();
	void playround(int dice);
	int getCoins() const;
	void setCoins(int coins);
	int getChoice() const;
	void setChoice(int choice);

private:
	int coins;
	int choice;
};
