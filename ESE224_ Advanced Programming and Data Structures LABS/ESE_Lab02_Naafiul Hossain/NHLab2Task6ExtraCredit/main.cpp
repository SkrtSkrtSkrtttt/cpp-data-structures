//Naafiul Hossain
//SBU ID: 115107623

#include <iostream>
using namespace std;




/* 
my leetcode soultion which i reused and rethinked with: 

bool isPalindrome(int x) {
        int number=x;
        if(x<0){
            return false; //checks for negative 
        }
        else{
          unsigned  int rev=0;
            while(x!=0){  //as long as its not zero
                int rem=x%10; //reminder 
                rev=rev*10+rem; //add the reminder at the end in its left
                x=x/10; //divide again
            }
            if(number==rev){
                return true;  //if its true return true 
            }
            else{
                return false;
            }
        }
    }
};*/
bool isPalindrome(int num) {
    int originalNum = num;
    int reverseNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reverseNum = reverseNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reverseNum;
}

int main() {
    int num;

    std::cout << "Enter an integer: ";
    std::cin >> num;

    if (isPalindrome(num)) {
        std::cout << num << " is a palindrome.\n";
    }
    else {
        std::cout << num << " is not a palindrome.\n";
    }

    return 0;
}
