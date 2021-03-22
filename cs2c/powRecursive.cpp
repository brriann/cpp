
bool isEven(int x)
{
   return x % 2 == 0;
}

long long pow(long long x, int n)
{
   if (n == 0)
   {
      return 1;
   }
   if (n == 1)
   {
      return x;
   }
   if (isEven(n))
   {
      return pow(x * x, n / 2);
   }
   else
   {
      return pow(x * x, n / 2) * x;
   }
}

int main()
{
   long long result1 = pow(33, 8);
   long long result2 = pow(2, 50);
   long long result3 = pow(2, 5);
   long long result4 = pow(2, 7);
   long long result5 = pow(2, 32);
   long long result6 = pow(2, 31);

   return 0;
}