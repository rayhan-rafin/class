class student
{
  String? _name;
  int? _age;
  void setName(String name)
  {
    this._name = name;
  }
  void setAge(int age)
  {
    this._age = age;
  }
  String getName()
  {
    return this._name!;
  }
  int getAge()
  {
    return this._age!;
  }
}




void main ()
{
  student st = student();
  st.setName("Rayhan");
  st.setAge(23);
  print(st.getName());
  print(st.getAge());
}
