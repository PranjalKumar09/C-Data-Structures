// error

#include <iostream>

using namespace std;

int main() {
  int age = 4;

  // case must have int , char, short, long, enum  (Even expression leading to this)

  if (age == 18) {
    switch (age) {
    case 18:
      cout << " You are 18 years old.";
    }
  } else if (age >= 18) {

    switch (age) {
    case 18:
      cout << " You are above 18 years old.";
    }
  } else {
    switch (age) {
    case 18:
      cout << " You are below 18 years old.";
    }
  }

  return 0;
}