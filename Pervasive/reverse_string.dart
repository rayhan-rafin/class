import 'package:dart4/dart4.dart' as dart4;

String reverseString(String name)
{
  String rev = "";
  for (int i =(name.length)-1 ;i>=0;i--){
    rev = rev+name[i];
  }
  return rev;
}

void main()
{
  String name = "Rayhan";
  String reversed = reverseString(name);
  print (reversed);
}
