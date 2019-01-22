#pragma config(Sensor, S1,     left,                   sensorLightActive)
#pragma config(Sensor, S2,     right,                   sensorLightActive)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
  int l,r;
	int count;
	count = 0;

	nMotorEncoder[motorA] = 0;
	while(true)
	{
	  l = SensorValue(left);
	  r = SensorValue(right);

	  if(l > 40 && r > 40)
	  {
		  motor[motorA] = 100;
		  motor[motorC] = 98;

	  }
	  else if(l > 40 && r < 40)
	  {
		  motor[motorA] = 100;
		  motor[motorC] = 0;

	  }
	  else if(l < 40 && r > 40)
	  {
		  motor[motorA] = 0;
		  motor[motorC] = 100;

  	}
	  else if(l < 40 && r < 40)
	  {
	  	if(nMotorEncoder[motorA] > 6000)
	  	{
	  		nMotorEncoder[motorA]=0;
        while(nMotorEncoder[motorA]<800)
        {
          motor[motorA]=100;
          motor[motorC]=98;
        }
        break;
	  	}
		  else
		  {
		  	motor[motorA] = 100;
		    motor[motorC] = 98;
		  }
		}
	}

  motor[motorA] = 0;
  motor[motorC] = 0;
  wait1Msec(300);

  nMotorEncoder[motorB] = 0;
    while(nMotorEncoder[motorB] > - 150)
    {
	    motor[motorB] = -100;
    }

  while(count < 60)
  {
  	nMotorEncoder[motorB] = 0;
    while(nMotorEncoder[motorB] < 300)
    {
      motor[motorB] = 100;
    }

    nMotorEncoder[motorB] = 0;
    while(nMotorEncoder[motorB] > - 300)
    {
	    motor[motorB] = -100;
    }

  	count++;
  }

  motor[motorB] = 0;
  wait1Msec(300);
	while(true)
	{
		l = SensorValue(left);
	  r = SensorValue(right);

	  if(l > 40 && r > 40)
	  {
	  	motor[motorA] = -98;
	  	motor[motorC] = -100;
	  }
	  else if(l > 40 && r < 40)
	  {
	  	motor[motorA]=0;
	  	motor[motorC]=-100;
	  }
	  else if(l < 40 && r > 40)
	  {
	  	motor[motorA]=-100;
	  	motor[motorC]=0;
	  }
	  else
	  {
	  	break;
	  }
	}

   nMotorEncoder[motorC] = 0;
   while(nMotorEncoder[motorC] < 600)
   {
     motor[motorA]=-70;
     motor[motorC]=100;
   }

	while(true)
	{
	  l = SensorValue(left);
	  r = SensorValue(right);

	  if(l > 40 && r > 40)
	  {
		  motor[motorA] = 100;
		  motor[motorC] = 98;

	  }
	  else if(l > 40 && r < 40)
	  {
		  motor[motorA] = 100;
		  motor[motorC] = -100;

	  }
	  else if(l < 40 && r > 40)
	  {
		  motor[motorA] = -100;
		  motor[motorC] = 100;

  	}
	  else if(l < 40 && r < 40)
	  {
		  motor[motorA] = 100;
		  motor[motorC] = 98;
		}
	}
}
//sensor = r-3(g),l-1(i) motor = r-C,l-B,a-A//
