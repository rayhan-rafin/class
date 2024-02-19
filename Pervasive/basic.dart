import 'package:dart4/dart4.dart' as dart4;

void main() {
  var num1= 100;
  var num2 = 50;
  List<String> list = ["sun","mon","tues","wednesday"];
  Set<String> set = {"sun","mon","tues","wednesday"};
  Map<String,dynamic> map = {
    "name":"DIU",
    "age":100};
  
  print("$list");
  print("$set");
  print("$map");


  num n1 = 23;
  num n2 = 23.67;
  String st1 = n1.toString();
  print(st1.runtimeType);
  String st2 = n2.toString();
  print(st1.runtimeType);
}
