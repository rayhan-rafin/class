class vehicle
{
  void run()
  {
    print("vehicle is running");
  }
}

class car extends vehicle
{
  @override
  void run()
  {
    print ("car is running");
  }
}

class bus extends vehicle
{
  @override
  void run ()
  {
    print ("bus is running ");
  }
}

void main ()
{
  vehicle v = vehicle();
  v.run();
  car c = car();
  c.run();
  bus b = bus();
  b.run();
}
