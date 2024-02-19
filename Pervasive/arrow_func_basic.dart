import 'package:dart4/dart4.dart' as dart4;

int add(int n1, int n2)=> n1+n2;
int sub(int n1, int n2)=> n1-n2;
int mul(int n1, int n2)=> n1*n2;
double div(int n1, int n2)=> n1/n2;
int div2(int n1, int n2)=> n1~/n2;

void main()
{
  int num1 =100;
  int num2 = 30;
  print("Addition is : ${add(num1,num2)}");
  print("subtraction is : ${sub(num1,num2)}");
  print("multiplication is : ${mul(num1,num2)}");
  print("double div is : ${div(num1,num2)}");
  print("int div is : ${div2(num1,num2)}");
}
