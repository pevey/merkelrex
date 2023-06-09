#include <iostream>
#include <string>
#include <vector>

enum class OrderBookType {bid, ask};

class OrderBookEntry {
	public:
		OrderBookEntry(double _price, double _amount, std::string _timestamp, std::string _product, OrderBookType _orderType)
			: price(_price), amount(_amount), timestamp(_timestamp), product(_product), orderType(_orderType) {}

		double price;
		double amount;
		std::string timestamp;
		std::string product;
		OrderBookType orderType;
};

double computeAveragePrice(std::vector<OrderBookEntry>& orders) {
	double total = 0.0;
	for (OrderBookEntry& order : orders) {
		total += order.price;
	}
	return total / orders.size();
}

double computeLowPrice(std::vector<OrderBookEntry>& orders) {
	double lowPrice = orders[0].price;
	for (OrderBookEntry& order : orders) {
		if (order.price < lowPrice) {
			lowPrice = order.price;
		}
	}
	return lowPrice;
}

double computeHighPrice(std::vector<OrderBookEntry>& orders) {
	double highPrice = orders[0].price;
	for (OrderBookEntry& order : orders) {
		if (order.price > highPrice) {
			highPrice = order.price;
		}
	}
	return highPrice;
}

double computePriceSpread(std::vector<OrderBookEntry>& orders) {
	double lowPrice = computeLowPrice(orders);
	double highPrice = computeHighPrice(orders);
	return highPrice - lowPrice;
}

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

	std::vector<OrderBookEntry> orders;
	orders.push_back(OrderBookEntry{0.02187308, 7.44564869, "2020/03/17 17:01:24.884492", "ETH/BTC", OrderBookType::bid});
	orders.push_back(OrderBookEntry{0.02187307, 3.467434, "2020/03/17 17:02:24.884492", "ETH/BTC", OrderBookType::bid});

	for (OrderBookEntry& order : orders) {
		std::cout << "Price: " << order.price << std::endl;
	}

	double averagePrice = computeAveragePrice(orders);
	std::cout << "Average price: " << averagePrice << std::endl;

	double lowPrice = computeLowPrice(orders);
	std::cout << "Low price: " << lowPrice << std::endl;

	double highPrice = computeHighPrice(orders);
	std::cout << "High price: " << highPrice << std::endl;

	double priceSpread = computePriceSpread(orders);
	std::cout << "Price spread: " << priceSpread << std::endl;

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