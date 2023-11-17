#include <iostream>
#include <math.h>
using namespace std;
// функция считывает число
float num()
{
  double res = 0;
  double k = 10;
  double p;
  char c;

  for (;;)
  {
    c = cin.get();

    if (c >= '0' && c <= '9')
        {
          res = res * 10 + c - '0';
        }

   else
    {
	if(c == 'p')
	{
	  c = cin.get();
	  if(c == 'i')
	   res = 3.1415926535;
	   return res;
	}
	if(c=='e')
    {
        res=2.7182818284;
        return res;
    }
        p=res;
        cin.putback(c);
        break;
    }
  }
c = cin.get();
if(c == '.')
    {
        for (;;)
        {
			c = cin.get();
            if (c >= '0' && c <= '9')
            {
                p= p + (c - '0') / k;
                k = k * 10.0;
            }
            else
                {
                    cin.putback(c);
                    break;
                }
        }
        return p;
	}
	else
	{
        cin.putback(c);
        return res;
	}
}

float plmin();
float sk()
{
   char a =cin.get();
   if (a=='(')
   {
       float x=plmin();
       cin.get();
       return x;
   }
   else
   {
       cin.putback(a);
       return num();
   }
}



// степень
float st()
{
    float x = sk();
    for (;;)
    {
        char a=cin.get();
        switch(a)
        {
        case '^':
            x=pow(x,sk());
            break;
        default:
            cin.putback(a);
            return x;
        }
    }

}
// умножение деление
float umdel()
{
    float x = st();
    for (;;)
    {
        char a=cin.get();
        switch(a)
        {
        case '*':
            x*=st();
            break;
        case '/':
            x/=st();
            break;
        default:
            cin.putback(a);
            return x;
        }
    }

}

// плюс минус
float plmin()
{
    float x = umdel();
    for (;;)
    {
        char a=cin.get();


        switch(a)
        {
        case '+':
            x+=umdel();
            break;
        case '-':
            x-=umdel();
            break;
        default:
            cin.putback(a);
            return x;
        }
    }

}
int main()
{
    cout<<"number:";
    double r=plmin();
    cout<<"res:"<<r<<endl;
    return 0;
}

