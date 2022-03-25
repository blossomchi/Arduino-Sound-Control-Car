#include <AFMotor.h>

int _ABVAR_1_cont = 0 ;
int _ABVAR_2_sound = 0 ;
boolean __ardublockDigitalRead(int pinNumber)
{
  pinMode(pinNumber, INPUT);
  return digitalRead(pinNumber);
}


AF_DCMotor motor_dc_1(1, MOTOR12_64KHZ);
AF_DCMotor motor_dc_4(4, MOTOR34_64KHZ);

void Left();
void doOrder();
void Stop();
void Backward();
void Right();
void Forward();
void bye();

void setup()
{
  Serial.begin(9600);
  _ABVAR_1_cont = 0 ;

  _ABVAR_2_sound = 8 ;

}

void loop()
{
  if (( ( __ardublockDigitalRead(_ABVAR_2_sound) ) == ( HIGH ) ))
  {
    delay( 10 );
    _ABVAR_1_cont = ( _ABVAR_1_cont + 1 ) ;
    if (( ( _ABVAR_1_cont ) <= ( 4 ) ))
    {
      doOrder(_ABVAR_1_cont);
    }
    else
    {
      if (( ( _ABVAR_1_cont ) == ( 5 ) ))
      {
        bye(( _ABVAR_1_cont - 5 ));
      }
    }
  }
}

void Stop()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(RELEASE);
  motor_dc_4.setSpeed(255);
  motor_dc_4.run(RELEASE);
}

void doOrder(int cont)
{
  if (( ( cont ) == ( 1 ) ))
  {
    Forward();
    Serial.print("message");
    Serial.print(" ");
    Serial.print(cont);
    Serial.print(" ");
    Serial.println();
    delay( 1000 );
  }
  else
  {
    if (( ( cont ) == ( 2 ) ))
    {
      Serial.print("message");
      Serial.print(" ");
      Serial.print(cont);
      Serial.print(" ");
      Serial.println();
      Backward();
      delay( 1000 );
    }
    else
    {
      if (( ( cont ) == ( 3 ) ))
      {
        Left();
        delay( 1000 );
      }
      else
      {
        if (( ( cont ) == ( 4 ) ))
        {
          Right();
          delay( 1000 );
        }
        else
        {
          if (( ( cont ) == ( 5 ) ))
          {
            Stop();
            delay( 1000 );
          }
        }
      }
    }
  }
}

void bye(int y)
{
  Serial.print("message");
  Serial.print(" ");
  Serial.print(y);
  Serial.print(" ");
  Serial.println();
}

void Left()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(BACKWARD);
  motor_dc_4.setSpeed(255);
  motor_dc_4.run(FORWARD);
}

void Forward()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(FORWARD);
  motor_dc_4.setSpeed(255);
  motor_dc_4.run(FORWARD);
}

void Right()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(FORWARD);
  motor_dc_4.setSpeed(255);
  motor_dc_4.run(BACKWARD);
}

void Backward()
{
  motor_dc_1.setSpeed(255);
  motor_dc_1.run(BACKWARD);
  motor_dc_4.setSpeed(255);
  motor_dc_4.run(BACKWARD);
}
