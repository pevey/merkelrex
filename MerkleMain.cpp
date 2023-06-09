#include <iostream>
#include <vector>
#include "MerkleMain.h"
#include "OrderBookEntry.h"

MerkleMain::MerkleMain() {
	this->isRunning = true;
	this->orders = std::vector<OrderBookEntry>{};
}

void MerkleMain::init() {
	loadOrderBook();
	while (isRunning) {
		// loadOrderBook();
		printMenu();
		int input = getUserOption();
		processUserOption(input);
	}
}

void MerkleMain::loadOrderBook() {
	std::cout << "Loading order book" << std::endl;

	this->orders.push_back(OrderBookEntry{0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
	this->orders.push_back(OrderBookEntry{0.02186299, 0.1, "2020/03/17 17:02:24.884492", "ETH/BTC", OrderBookType::bid});

	// for (OrderBookEntry& order : this->orders) {
	// 	std::cout << "Price: " << order.price << std::endl;
	// }
}

void MerkleMain::printMenu() {
	std::cout << "1: Print help" << std::endl;
	std::cout << "2: Print exchange stats" << std::endl;
	std::cout << "3: Make an offer" << std::endl;
	std::cout << "4: Make a bid" << std::endl;
	std::cout << "5: Print wallet" << std::endl;
	std::cout << "6: Continue" << std::endl;
	std::cout << "7: Exit" << std::endl;
}

void MerkleMain::printHelp() {
	std::cout << "Help - your aim is to make money.  Analyze the market, and make bids and offers." << std::endl;
}

void MerkleMain::printStats() {
	std::cout << "OrderBook contains: " << this->orders.size() << " entries" << std::endl;

	// double averagePrice = computeAveragePrice(orders);
	// std::cout << "Average price: " << averagePrice << std::endl;

	// double lowPrice = computeLowPrice(orders);
	// std::cout << "Low price: " << lowPrice << std::endl;

	// double highPrice = computeHighPrice(orders);
	// std::cout << "High price: " << highPrice << std::endl;

	// double priceSpread = computePriceSpread(orders);
	// std::cout << "Price spread: " << priceSpread << std::endl;
}

void MerkleMain::enterOffer() {
	std::cout << "Enter offer" << std::endl;
}

void MerkleMain::enterBid() {
	std::cout << "Enter bid" << std::endl;
}

void MerkleMain::printWallet() {
	std::cout << "Print wallet" << std::endl;
}

void MerkleMain::gotoNextTimeFrame() {
	std::cout << "Goto next time frame" << std::endl;
}

int MerkleMain::getUserOption() {
	std::cout << "Type in 1-7" << std::endl;
	int userOption;
	std::cin >> userOption;
	std::cout << "You chose: " << userOption << std::endl;
	return userOption;
}

void MerkleMain::processUserOption(int userOption) {
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
		case 7:
			isRunning = false;
			std::cout << "Exiting" << std::endl;
			break;
		default:
			std::cout << "Invalid choice.  Choose 1-7" << std::endl;
			break;
	}
}

// double computeAveragePrice(std::vector<OrderBookEntry>& orders) {
// 	double total = 0.0;
// 	for (OrderBookEntry& order : orders) {
// 		total += order.price;
// 	}
// 	return total / orders.size();
// }

// double computeLowPrice(std::vector<OrderBookEntry>& orders) {
// 	double lowPrice = orders[0].price;
// 	for (OrderBookEntry& order : orders) {
// 		if (order.price < lowPrice) {
// 			lowPrice = order.price;
// 		}
// 	}
// 	return lowPrice;
// }

// double computeHighPrice(std::vector<OrderBookEntry>& orders) {
// 	double highPrice = orders[0].price;
// 	for (OrderBookEntry& order : orders) {
// 		if (order.price > highPrice) {
// 			highPrice = order.price;
// 		}
// 	}
// 	return highPrice;
// }

// double computePriceSpread(std::vector<OrderBookEntry>& orders) {
// 	double lowPrice = computeLowPrice(orders);
// 	double highPrice = computeHighPrice(orders);
// 	return highPrice - lowPrice;
// }