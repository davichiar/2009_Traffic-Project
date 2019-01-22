void pro1()
{
	nMotorEncoder[motorA] = 0;
	while(nMotorEncoder[motorA] > -200)
	  {
		  motor[motorA] = -80;
	  }
}
void pro2()
{
	nMotorEncoder[motorA] = 0;
	while(nMotorEncoder[motorA] < 100)
	  {
	  	motor[motorA] = 90;
	  }
}

task main()
{
	while(true)
	{
    pro1();
    pro2();
  }
}
