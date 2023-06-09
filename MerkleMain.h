#pragma once

#include <vector>
#include "OrderBookEntry.h"

class MerkleMain {

	public:
		MerkleMain();
		void init();

	private:
		bool isRunning;
		std::vector<OrderBookEntry> orders;

		void loadOrderBook();
		void printMenu();
		void printHelp();
		void printStats();
		void enterOffer();
		void enterBid();
		void printWallet();
		void gotoNextTimeFrame();
		int getUserOption();
		void processUserOption(int userOption);
};