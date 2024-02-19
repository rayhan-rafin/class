class person
{
  String? name;
  int? age;

}

class doctor extends person
{
  List<String>? listofdegree;
  String? hospitalname;

  void display()
  {
    print("Name is : $name");
    print("Age is : $age");
    print("Degree is : $listofdegree");
    print("Hospital name : $hospitalname");
  }
}

class specialist extends doctor
{
  String? specialization;
  void display()
  {
    super.display();
    print("Specialization: $specialization");
  }
}


void main ()
{
  specialist sp = specialist();
  sp.name = "Rayhan";
  sp.age = 23;
  sp.listofdegree = ["MBBS","BDDS"];
  sp.hospitalname = "Delta";
  sp.specialization = "Eye";
  sp.display();
}
