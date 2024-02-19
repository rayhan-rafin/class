abstract class vehicle
{
  void start();
  void stop();
}

class car extends vehicle
{
  void start()
  {
    print ("car is starting");
  }
  void stop()
  {
    print ("car is stopping");
  }
}

class bus extends vehicle
{
  void start ()
  {
    print ("bus is starting ");
  }
  void stop()
  {
    print ("bus is stopping");
  }
}

void main ()
{
  bus b = bus();
  b.start();
  b.stop();
  car c = car();
  c.start();
  c.stop();
}
