#include <iostream>

void printMenu() {
	 std::cout << "1: Print help" << std::endl;
	 std::cout << "2: Print exchange stats" << std::endl;
	 std::cout << "3: Make an offer" << std::endl;
	 std::cout << "4: Make a bid" << std::endl;
	 std::cout << "5: Print wallet" << std::endl;
	 std::cout << "6: Continue" << std::endl;
	 std::cout << "7: Exit" << std::endl;
}

void printHelp() {
	std::cout << "Help - your aim is to make money.  Analyze the market, and make bids and offers." << std::endl;
}

void printStats() {
	std::cout << "Stats - here are the stats" << std::endl;
}

void enterOffer() {
	std::cout << "Enter offer" << std::endl;
}

void enterBid() {
	std::cout << "Enter bid" << std::endl;
}

void printWallet() {
	std::cout << "Print wallet" << std::endl;
}

void gotoNextTimeFrame() {
	std::cout << "Goto next time frame" << std::endl;
}

int getUserOption() {
	std::cout << "Type in 1-7" << std::endl;
	int userOption;
	std::cin >> userOption;
	std::cout << "You chose: " << userOption << std::endl;
	return userOption;
}

void processUserOption(int userOption) {
	switch (userOption) {
		case 1:
			printHelp();
			break;
		case 2:
			printStats();
			break;
		case 3:
			enterOffer();
			break;
		case 4:
			enterBid();
			break;
		case 5:
			printWallet();
			break;
		case 6:
			gotoNextTimeFrame();
			break;
		default:
			std::cout << "Invalid choice.  Choose 1-7" << std::endl;
			break;
	}
}

int main() {
	bool exit = false;
	while (!exit) {
		printMenu();
		std::cout << "====================== " << std::endl;
		int userOption = getUserOption();
		if (userOption == 7) {
			exit = true;
			std::cout << "Exiting" << std::endl;
			break;
		} else {
			processUserOption(userOption);
		}
	}
	return 0;
}