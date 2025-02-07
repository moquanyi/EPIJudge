#include <vector>

#include "test_framework/generic_test.h"
using namespace std;

double BuyAndSellStockOnce(const vector<double>& prices) {
  if (prices.empty()) return 0;
  double max_profit = 0, min_price = prices[0];
  for(int i = 1; i < prices.size(); i++) {
    max_profit = max(max_profit, prices[i] - min_price);
    min_price = min(min_price, prices[i]);
  }
  return max_profit;
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"prices"};
  return GenericTestMain(args, "buy_and_sell_stock.cc",
                         "buy_and_sell_stock.tsv", &BuyAndSellStockOnce,
                         DefaultComparator{}, param_names);
}
