// find the maximal value of fractions of items that fit into the knapsack.

#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  int sizevect = weights.size();

  vector<std::pair<int, int>> Val_Weight(sizevect);
  vector<std::pair<double, int>> ValPerUnit(sizevect);
 for (int i = 0; i < sizevect;i++){
   Val_Weight[i].first = values[i];
   Val_Weight[i].second=weights[i];
   ValPerUnit[i].first = double(Val_Weight[i].first) / double(Val_Weight[i].second);
   ValPerUnit[i].second = Val_Weight[i].second;
 }
 sort(ValPerUnit.begin(), ValPerUnit.end(), std::greater<std::pair<double, int>>());
	

	for (int i = 0; i < ValPerUnit.size() && capacity>0; i++) {
		value += std::min(ValPerUnit[i].second, capacity)*ValPerUnit[i].first;
		capacity -= std::min(ValPerUnit[i].second, capacity);
	}

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
