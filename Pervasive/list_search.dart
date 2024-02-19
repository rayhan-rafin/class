import 'package:dart4/dart4.dart' as dart4;

int findIndex(List<int>list, int target)
{
  for (int i =0;i<list.length;i++){
    if (list[i]==target){
      return i;
    }
  }
  return -1;
}

void main()
{
  List<int> list =[12,43,354,221,2134];
  int target = 354;
  int found = findIndex(list,target);
  if (found == -1){
    print("Element not found");
  }
  else {
      print("Element is found at position $found");
    }
}
