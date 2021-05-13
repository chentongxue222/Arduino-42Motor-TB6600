#define DIR 3 //方向信号
#define PUL 4 //脉冲信号
int flag=0;
char num='0';
void setup() 
{
  pinMode(DIR, OUTPUT);
  pinMode(PUL, OUTPUT);
  Serial.begin(9600);
  digitalWrite(DIR, LOW);//设置步进电机转动方向
}

void loop() 
{
    if(Serial.available()>0)    //串口接收数据给num
    {
        num=Serial.read();
        Serial.println(num);
    }

  if(flag==0)            //处于不同位置，收到不同数据，转不同角度，以下类似
  {
      switch (num)
      {
      case '1': 
      {
        turn(200);
        flag=1;
        num='0';
      }
      break;
      case '2': 
      {
         turn(400);
         flag=2;
         num='0';
      }
      
      break;
      case '3': 
      {
        turn(600);
        flag=3;
        num='0';
      }

      break;
      case '4': 
      {
      turn(0);
      flag=0;
      num='0';
      }
      break;
      
      default:
          break;
      }
  }

  if(flag==1)
  {
      switch (num)
      {
      case '1': 
      {
      turn(0);
      flag=1;
      num='0';
      }

      break;
      case '2': 
      {
      turn(200);
      flag=2;
      num='0';
      }

      break;
      case '3': 
      {
      turn(400);
      flag=3;
      num='0';
      }

      break;
      case '4': 
      {
      turn(600);
      flag=0;
      num='0';
      }

      break;
      
      default:
          break;
      }
  }

  if(flag==2)
  {
      switch (num)
      {
      case '1': 
      {
      turn(600);
      flag=1;
      num='0';
      }

      break;
      case '2': 
      {
      turn(0);
      flag=2;
      num='0';
      }

      break;
      case '3': 
      {
      turn(200);
      flag=3;
      num='0';
      }

      break;
      case '4': 
      {
      turn(400);
      flag=0;
      num='0';
      }

      break;
      
      default:
          break;
      }
  }

    if(flag==3)
  {
      switch (num)
      {
      case '1': 
      {
      turn(400);
      flag=1;
      num='0';
      }

      break;
      case '2': 
      {
      turn(600);
      flag=2;
      num='0';
      }

      break;
      case '3': 
      {
      turn(0);
      flag=3;
      num='0';
      }

      break;
      case '4': 
      {
      turn(200);
      flag=0;
      num='0';
      }

      break;
      
      default:
          break;
      }
  }
}

void turn(int count)
{
    for(int i=0;i<count;i++)
    {
        digitalWrite(PUL, HIGH);
        delayMicroseconds(800);
        digitalWrite(PUL, LOW);
        delayMicroseconds(800);    
    }
}