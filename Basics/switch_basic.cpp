// error

#include <iostream>

using namespace std;

int main() {
  int age = 4;

  if (age == 18) {
    switch (age) {
    case 18:
      cout << " You are 18 years old.";
    }
  } else if (age >= 18) {

    switch (age) {
    case age:
      cout << " You are above 18 years old.";
    }
  } else {
    switch (age) {
    case age:
      cout << " You are below 18 years old.";
    }
  }

  return 0;
}