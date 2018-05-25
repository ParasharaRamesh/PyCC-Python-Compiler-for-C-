
 int main(){
  int x=1;
  int y=2;
  int z=3;
  int q=(x*(x-y)) + (z*(x-y));
	int a=(( 1 * 3 )  + ( 9 * 7 ))/2;
	int b=2;
	int c=b;
  switch(c)
  {
    case 1 :
            b=1;
            break;
    case 2 :
          b=10;
          break;
    default : b=3;
  }
  while(b>0)
  {
    a=a+c;
    b=b-1;
  }
  return;
}
