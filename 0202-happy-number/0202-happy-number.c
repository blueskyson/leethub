int getSum(int n) {
    int sum = 0;
    while(n != 0) {
        int digit = n % 10;
        sum += digit * digit;
        n /= 10;
    }
    
    return sum;
}

bool isHappy(int n) {
    int slow = n, fast = n;
    do {
        slow = getSum(slow);
        fast = getSum(getSum(fast));
        if (slow == 1) {
            return true;
        }
    } while (slow != fast);

    return false;
}