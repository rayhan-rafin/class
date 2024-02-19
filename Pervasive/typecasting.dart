import 'package:dart4/dart4.dart' as dart4;
import "dart:io";


void main()
{
  print("Enter name: ");
  String? name = stdin.readLineSync();
  print(name);

  print("Enter your age: ");
  int? age = int.parse(stdin.readLineSync()!);
  print("Enter your ID: ");
  double id = double.parse(stdin.readLineSync()!);
  print(id);
}
