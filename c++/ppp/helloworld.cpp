#include "gui/std_lib_facilities.h"

void repetitions();
void comparison();
void test_integers();
void currency_conversion();
void read_write_strings();
void temperatures();
int area(int a, int b);
class Bad_area { };
void print_temperatures();

int main() {
  //test_integers();
  //comparison();
  //currency_conversion();
  //read_write_strings();
  //repetitions();
  //temperatures();
  /*
  try {
    int a = area(-1, 3);
  }
  catch (Bad_area){
    cout << "Oops! bad arguments to area()\n";
  }
  */
  print_temperatures();

}
void test_integers() {
  cout << "Enter two integers \'a\' and \'b\':\n";
  int a, b;
  cin >> a >> b;
  cout << "a = " << a << ", b = " << b << "\n";
  int c = a / b * b + a % b;
  c == a ? cout << "c == a == " << c << "\n" : cout << "c != a\n";
}
void comparison() {
  cout << "Enter two names for comparison:\n";
  string n1, n2;
  cin >> n1 >> n2;
  if (n1 == n2)
    cout << n1 << " and " << n2 << " are the same name.\n";
  else if (n1 > n2)
    cout << n1 << " is alphabetically after " << n2 << "\n";
  else
    cout << n2 << " is alphabetically after " << n1 << "\n";
}
void repetitions() {
  cout << "Enter as many words as you like (to exit Ctrl+D):\n";
  string prev = "";
  string current;
  int repetition = 0;
  while (cin >> current) {
    if (prev == current) {
      cout << "repeated word: " << current << "\n";
      repetition++;
    }
    prev = current;
  }
  cout << "Number of repetitions: " << repetition << "\n";
}
void currency_conversion() {
  cout << "Currency conversion Euro - Swiss Franc.\n";
  double amount;
  char unit;
  cout << "Write the amount and the unit (e or f):\n";
  constexpr double conv = 0.98; // swiss francs for 1 euro
  cin >> amount >> unit;
  if (unit == 'e')
    cout << "Swiss francs: " << amount / conv << "\n";
  else if (unit == 'f')
    cout << "Euros: " << amount * conv << "\n";
  else
    cout << "Currency of any other type cannot be converted.\n";

}
void read_write_strings() {
  constexpr int size = 3;
  vector<string> v(size);
  int count = 0;
  cout << "Enter 3 names:\n";
  for (int i = 0; i < v.size(); ++i)
    cin >> v[i];

  cout << "Printing the names:\n";
  for (string s: v)
    cout << s << " \n";
}
void temperatures() {
  cout << "Enter some temperature values (not a double to exit):\n";
  vector<double> temps;
  double sum = 0.0;
  for (double temp; cin >> temp;)
    temps.push_back(temp);
  cout << "Printing the temperature values:\n";
  for (double t: temps) {
    cout << t << " \n";
    sum += t;
  }
  cout << "Mean temperature: " << sum / temps.size() << "\n";
  sort(temps);
  cout << "Median temperature: " << temps[temps.size() / 2] << "\n";
}

int area(int a, int b) {
  if (a <= 0 || b <= 0) throw Bad_area{};
  return a * b;
}
void print_temperatures() {
  vector<double> temps; // temperatures
  cout << "Enter some temperature values (not a double to exit):\n";
  for (double temp; cin>>temp; ) // read and put into temps
    temps.push_back(temp);

  double sum = 0;
  double high_temp = -273.0; // lower universe temperature
  double low_temp = 6000; // sun temperature

  for (double x : temps) {
    if(x > high_temp) high_temp = x; // find high
    if(x < low_temp) low_temp = x; // find low
    sum += x; // compute sum
  }

  cout << "High temperature: " << high_temp<< '\n';
  cout << "Low temperature: " << low_temp << '\n';
  cout << "Average temperature: " << sum/temps.size() << '\n';
}
