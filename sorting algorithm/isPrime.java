//checks whether an int is prime or not.
boolean isPrime(int n) {
	if(n==2)   return true;
    //check if n is a multiple of 2
    if (n%2==0&&n!=2) return false;
    //if not, then just check the odds

    //attention: because we have checked if(n%2) here we only need to check i = i+2
    for(int i=3;i*i<=n;i=i+2) {
        if(n%i==0)
            return false;
    }
    return true;
}



/*
Let’s say you write a program where you’re asked to check whether many numbers are prime; 
not just once. Even though our program above is highly optimized for that algorithm, 
there exists another way specifically suited for this situation: 

The Prime Sieve.  质数筛/过滤网

Here’s the basic idea:

1.Assume every integer greater than or equal to 2 is prime.
2.Start at the beginning of the list, if the number is prime, cross out every multiple of that 
  number off the list. They are not prime.
3.Go to the next number, if it is crossed out, skip it – it is not prime. If it is not crossed out, 
  it must be prime, cross out it’s multiples.
4.Repeat
*/

import java.util.Arrays;
//global array just to keep track of it in this example, 
//but you can easily do this within another function.
 
// will contain true or false values for the first 10,000 integers
boolean[] primes=new boolean[10000]; 
//set up the primesieve
public void fillSieve() {
    Arrays.fill(primes,true);        // assume all integers are prime.
    primes[0]=primes[1]=false;       // we know 0 and 1 are not prime.
    for (int i=2;i<primes.length;i++) {
        //if the number is prime, 
        //then go through all its multiples and make their values false.
        if(primes[i]) {
            for (int j=2;i*j<primes.length;j++) {
                primes[i*j]=false;
            }
        }
    }
}
 
public boolean isPrime(int n) {
    return primes[n]; //simple, huh?
}