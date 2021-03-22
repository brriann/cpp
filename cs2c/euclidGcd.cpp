

long long gcd(long long m, long long n)
{
   while (n != 0)
   {
      long long rem = m % n;
      m = n;
      n = rem;
   }
   return m;
}

int main()
{
   long long result1 = gcd(122356, 33);
   long long result2 = gcd(44552, 225444);

   return 0;
}